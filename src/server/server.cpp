#include <QObject>
#include <QDebug>
#include <functional>
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTcpSocket>
#include <QVector>

#include <vector>
#include <random>

#include "../packet.h"
#include "../player.h"

#include "server.h"
//#include "player.h"
#include "client.h"
//#include "gameinfo.h"

Server::Server(QObject* parent): QTcpServer(parent), timer(this), database(QSqlDatabase::addDatabase("QMYSQL"))
{
    std::cout << "Constructed\n";

    //timer.start(5000);

    //connect(&timer, &QTimer::timeout, this, &Server::messageClients);
}

bool Server::connectToDatabase(){
    QFile file("db.json");
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QString contents =file.readAll();
    file.close();

    QJsonObject settings = QJsonDocument::fromJson(contents.toUtf8()).object();

    database.setDatabaseName(settings["database"].toString());
    database.setHostName(settings["hostname"].toString());
    database.setUserName(settings["user"].toString());
    database.setPassword(settings["password"].toString());

    return database.open();
}

bool Server::start(){
    if(!this->listen(QHostAddress::AnyIPv4, 45454)){
        qDebug() << "Failed to open listener";
        return false;
    }
    if(!this->connectToDatabase()){
        qDebug() << "Failed to connect to database";
        return false;
    }
    if(!this->loadGames()){
        qDebug() << "Failed to load games.";
    }


    return true;
}

bool Server::loadGames(){
    QFile file("games.json");
    file.open(QIODevice::ReadOnly);

    QString contents =file.readAll();
    file.close();

    QJsonArray json_games = QJsonDocument::fromJson(contents.toUtf8()).array();

    if(json_games.empty()) return false;

    qDebug() << "Begin load games...\n";

    for(int i = 0; i < json_games.size(); i++){
        QJsonObject game = json_games[i].toObject();

        QString max_players = QString::number(game["max_players"].toInt());
        QString chip_count = QString::number(game["chip_count"].toInt());
        QString port = QString::number(42444 + i);
        QString small_blind = QString::number(game["small_blind"].toInt());
        QString big_blind = QString::number(game["big_blind"].toInt());
        QString name = game["name"].toString();
        QString timer = QString::number(game["timer"].toInt());

        qDebug() << "Loading game: " << i;
        qDebug() << "Size: " << max_players;
        qDebug() << "Chip count: " << chip_count;
        qDebug() << "Name " << name;
        qDebug() << "Port: " << port;

        QProcess *proc = new QProcess(this);
        QStringList args;
        args << name << QString::number(i) << max_players << chip_count << small_blind << big_blind << timer << port;

        proc->start("~/projects/allstarpoker/bin/hostgame.sh", args);
        games[i] = proc;

        qDebug() << "-----------------------------";
    }

    return true;
}

void Server::incomingConnection(qintptr handle){

    std::cout << "Incoming connection!\n";
    qDebug() << "A player has connected.";

    clients[handle] = new Client;
    clients[handle]->socket = new QTcpSocket(this);

    clients[handle]->socket->setSocketDescriptor(handle);

    connections[handle] = connect(clients[handle]->socket, &QTcpSocket::readyRead, this, std::bind(&Server::readPacket, this, handle));

    connect(clients[handle]->socket, &QTcpSocket::disconnected, this, std::bind(&Server::handleDisconnect, this, handle));
}

void Server::returningClient(qintptr handle){
    qDebug() << "Moving client back to lobby...\n";
    connections[handle] = connect(clients[handle]->socket, &QTcpSocket::readyRead, this, std::bind(&Server::readPacket, this, handle));
}


void Server::handleDisconnect(qintptr handle){
    qDebug() << "A client has been disconnected!";
    //qDebug() << "User " << clients[handle]->account.username << "has disconnected!";

    //users_online.erase(clients[handle]->account.username);

    delete clients[handle];
}


bool Server::createAccount(qintptr handle, QJsonObject json){
    QString username = json["username"].toString();
    QString password = json["password"].toString();
    QString email = json["email"].toString();

    QString salt = crypto::salt();

    qDebug() << "Salt: " << salt;
    qDebug() << "Password: " << password;

    QString hash = crypto::hash(salt, password);

    qDebug() << "Salt + Password: " << password;

    QSqlQuery cursor(database);

    QString query = "insert into user (username, hash, salt, email) values ('" + username + "','" + hash + "','" + salt + "','" + email +"');";
    qDebug() << query;

    Packet outgoing;

    if(cursor.exec(query) && database.commit()){
        outgoing.opcode = Packet::Opcode::S2C_ACCOUNT_ACCEPTED;
        qDebug() << "Account added to database\n";
    }
    else{
        outgoing.opcode = Packet::Opcode::S2C_ACCOUNT_REJECTED;
        qDebug() << "Failed to add account to database\nQuery: " << query;
    }

    clients[handle]->socket->write(outgoing.package());
    return outgoing.opcode == Packet::Opcode::S2C_ACCOUNT_ACCEPTED;
}

bool Server::authenticate(qintptr handle, QJsonObject json){
    Packet outgoing;

    QString username = json["username"].toString();
    QString password = json["password"].toString();

    if(users_online.find(username) != users_online.end()){ //already logged in.
        qDebug() << "User is already logged in.\n";

        outgoing.opcode = Packet::Opcode::S2C_LOGIN_FAILURE;
        outgoing.payload = "User is already logged in.";
        clients[handle]->socket->write(outgoing.package());

        return false;
    }

    QSqlQuery cursor(database);
    cursor.exec("select salt, hash from user where username = '" + username + "';");

    if(!cursor.next()){ //username not in database
        qDebug() << "Could not find salt for user: " << username;
        outgoing.opcode = Packet::Opcode::S2C_LOGIN_FAILURE;
        outgoing.payload = "Invalid username or password.";
        clients[handle]->socket->write(outgoing.package());
        //send failure packet....
        return false;
    }

    //get salt
    QString salt = cursor.value(0).toString();
    QString db_hash = cursor.value(1).toString();

    qDebug() << "username: " << username;
    qDebug() << "DB salt: " << salt;
    qDebug() << "DB hash: " << db_hash;


    QString hash = crypto::hash(salt, password);
    qDebug() << "This hash: " << hash;

    if(hash == db_hash){
        qDebug() << "Login Success!\n";
        outgoing.opcode = Packet::Opcode::S2C_LOGIN_SUCCESS;
        outgoing.payload = "Login Successful.";
        clients[handle]->socket->write(outgoing.package());

        //clients[handle]->account->username = username;
        //clients[handle]->account->users_online = &users_online;

        users_online.insert(username); //mark user as logged in to prevent multiple logins.

        sendGameInfo(handle);
        return true;
    }
    else{
        qDebug() << "Hashes don't match.";

        outgoing.opcode = Packet::Opcode::S2C_LOGIN_FAILURE;
        outgoing.payload = "Invalid username or password.";
        clients[handle]->socket->write(outgoing.package());

        return false;
    }
}


void Server::readPacket(qintptr handle){
    qDebug() << "Received a message from player: " << handle;

    while(clients[handle]->socket->bytesAvailable()){
        qDebug() << "Reading packet...";
        Packet incoming;
        incoming = clients[handle]->socket->read(PACKET_SIZE); // >> incoming;

        incoming.unpack();

        qDebug() << "Opcode: " << int(incoming.opcode);
        qDebug() << "Payload: " << incoming.payload;

        switch(incoming.opcode){
            case Packet::Opcode::S2C_GAME_INFO:
                qDebug() << "Received Game Info!";
                //menu->updateGames(incoming.payload);
                break;
            case Packet::Opcode::C2S_CHOSE_SEAT:
                qDebug() << "The client has chosen a seat!";
                //seatClient(handle, incoming.payload);
                break;
            case Packet::Opcode::S2C_MESSAGE:
                qDebug() << "Chat message!";
                break;
            case Packet::Opcode::C2S_CREATE_ACCOUNT:
                qDebug() << "A client has created an account.\n";

                createAccount(handle, incoming.json);
                break;
            case Packet::Opcode::C2S_LOGIN:
                qDebug() << "A client is attempting to login..\n";
                authenticate(handle, incoming.json);
                break;
            case Packet::Opcode::C2S_PEEK_GAME:
                qDebug() << "A client is attemping to peek game...\n";
                sendSeatedPlayers(handle, incoming.payload.toInt());
                break;
            default:
                qDebug() << "Other packet...";
                break;
        }
    }
}


void Server::sendSeatedPlayers(qintptr handle, int gameno){
    /*
    qDebug() << "Game: " << gameno << " has " << games[gameno]->players.size() << " players.";

    for(auto &player: games[gameno]->players){
        Packet packet(Packet::Opcode::S2C_ADD_PLAYER, player->toJsonString(), Packet::Type::JSON);

        clients[handle]->socket->write(packet.package());
        qDebug() << "Sending seated player...";
    }
    */
}


void Server::sendGameInfo(qintptr handle){

    /*
    for(auto &game: games){
        Packet outgoing(Packet::Opcode::S2C_GAME_INFO, Packet::Type::JSON);

        outgoing.payload = game->toJsonString(); //.leftJustified(PAYLOAD_SIZE, '\0');
        qDebug() << "Sending game: " << outgoing.payload;
        clients[handle]->socket->write(outgoing.package());
    }
    */

    /*
    Packet outgoing(Packet::Opcode::S2C_GAME_INFO);

    for(int i = 0; i < games.size(); i++){
        GameInfo gameinfo(QString::number(i), "Waiting for Players", "0", QString::number(games[i]->size), QString::number(games[i]->chipcount));
        outgoing.payload += gameinfo.package();
    }

    clients[handle]->write(outgoing.package());
    */
}

void Server::sendGameInfo(qintptr handle, int gameno){
    /*
    Packet outgoing(Packet::Opcode::S2C_GAME_INFO, Packet::Type::JSON);

    outgoing.payload = games[gameno]->toJsonString().leftJustified(PAYLOAD_SIZE, '\0');
    clients[handle]->socket->write(outgoing.package());
    */
}
