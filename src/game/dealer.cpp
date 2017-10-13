#include <QTcpSocket>
#include <QStringList>
#include <QFile>
#include <QSet>
#include <QDir>
#include <QTimer>
#include <iostream>
#include <algorithm>
#include <random>

#include "dealer.h"
#include "game.h"

#include "../packet.h"
#include "../player.h"

#define TABLE_SIZE 8

void Dealer::incomingConnection(qintptr handle){
    game->clients[handle] = new QTcpSocket(this);
    game->clients[handle]->setSocketDescriptor(handle);

    clients[handle] = game->clients[handle];

    std::cout << "Handle: " << handle << "\nSocket: " << game->clients[handle];

    connections[handle] = connect(game->clients[handle], &QTcpSocket::readyRead, this, std::bind(&Dealer::readPacket, this, handle));
    connect(game->clients[handle], &QTcpSocket::disconnected, this, std::bind(&Dealer::removeClient, this, handle));
    std::cout << "A client has connected!\n";

    sendExistingPlayers(handle);
}
void Dealer::sendExistingPlayers(qintptr handle){
    for(auto &player: game->players){
        Packet packet(Packet::Opcode::S2C_ADD_PLAYER, player->toJsonString(), Packet::Type::JSON);
        clients[handle]->write(packet.package());
    }
}

void Dealer::removeClient(qintptr handle){
    clients[handle]->close(); //close the socket.
    delete game->clients[handle]; //free the socket

    auto a = clients.find(handle);
    clients.erase(a);

    auto b = game->clients.find(handle);
    game->clients.erase(b);

    auto c = connections.find(handle);
    connections.erase(c);

    int seat_id = handle_seats[handle];

    //iterator to player that is leaving.
    auto it = std::find_if(game->players.begin(), game->players.end(), [seat_id](const Player* p){
        return p->id == seat_id;
    });

    Player* temp = *it;
    delete temp; //free the player
    game->players.erase(it); //remove player from players.

    std::cout << "A client has disconnected!\n";
    std::cout << "There are now " << game->players.size() << " players left.\n";

    for(auto &key: clients.keys()){
        Packet packet(Packet::Opcode::S2C_REMOVE_PLAYER, QString::number(seat_id));
        //clients.value(key)->write(packet.package());
    }

    std::cout << "Done notifying players...\n";
}

void Dealer::seatClient(qintptr handle, JsonString json_str){
    QJsonObject json = QJsonDocument::fromJson(json_str.toUtf8()).object();

    qDebug() << "Seating client..." << json_str;
    int game_id = json["game_id"].toInt();
    int seat_id = json["seat_id"].toInt();
    QString username = json["username"].toString();

    for(auto &player: game->players){
        if(player->id == seat_id){ //seat already taken...
            qDebug() << "Seat not available\n";
            Packet packet(Packet::S2C_SEAT_REJECT);
            clients[handle]->write(packet.package());
            return;
        }
    }

    Player* player = new Player(handle, seat_id, username);

    //notify all clients (except for this current player) that a player has chosen a seat.
    for(auto &key: clients.keys()){
        if(key == handle) continue; //skip this current player.

        Packet packet(Packet::Opcode::S2C_ADD_PLAYER, player->toJsonString(), Packet::JSON);
        clients.value(key)->write(packet.package());
    }

    player->socket = clients[handle];
    handle_seats[handle] = seat_id;

    game->players.push_back(player); //allocate the player.

    Packet packet(Packet::S2C_SEAT_ACCEPT, QString::number(seat_id));
    player->socket->write(packet.package());

    if(game->players.size() == game->capacity){
        qDebug() << "Preparing game start...\n";
        this->prepareGameStart();
    }
}

void Dealer::prepareGameStart(){
    for(auto &key: clients.keys()){
        Packet out(Packet::Opcode::S2C_NEW_GAME);

        clients.value(key)->write(out.package());
    }

    std::cout << "Starting timer...\n";
    game->next_hand_timer.start(DEFAULT_COUNTDOWN);
    std::cout << "Started\n";
}



void Dealer::authenticate(qintptr handle, QString payload){
    QDir dir(game->name + "/players");

    //QStringList files = dir.entryList(QDir::Files);

    QSet<QString> files = QSet<QString>::fromList(dir.entryList(QDir::Files));

    if(files.find(payload.trimmed()) != files.end()){
        qDebug() << "Found the file!\n";

        //sendSeatedPlayers(handle);
    }
    else{
        qDebug() << "Could not find file.\n";
    }
}

void Dealer::forwardChatMessage(Packet& packet){
    Packet revised(Packet::Opcode::S2C_MESSAGE, packet.payload);

    messageAll(revised);
}


void Dealer::readPacket(qintptr handle){

    qDebug() << "Dealer received a packet from: " << handle;

    qDebug() << "Socket Address: " << clients[handle];

    while(game->clients[handle]->bytesAvailable()){
        qDebug() << "Dealer: Reading packet...";
        Packet incoming;
        incoming = game->clients[handle]->read(PACKET_SIZE); // >> incoming;

        incoming.unpack();

        switch(incoming.opcode){
            case Packet::Opcode::C2S_KEY:
                qDebug() << "We need to authenticate this client.\n";
                authenticate(handle, incoming.payload);
                break;
            case Packet::Opcode::C2S_CHOSE_SEAT:
                qDebug() << "The client has chosen a seat!";
                seatClient(handle, incoming.payload);
                break;
            case Packet::Opcode::C2S_DISCONNECT:
                qDebug() << "The client has left the game.\n";
                break;
            case Packet::Opcode::C2S_MESSAGE:
                qDebug() << "Dealer: Chat message!";
                forwardChatMessage(incoming);
                break;
            case Packet::Opcode::C2S_PEEK_GAME:
                qDebug() << "A client is attemping to peek game...\n";
                //sendSeatedPlayers(handle, incoming.payload.toInt());
                break;
            case Packet::Opcode::C2S_PLAYER_MOVE:
                qDebug() << "A client has made a move\n";

            default:
                qDebug() << "Uknown packet type.";
                break;
        }
    }
}

void Dealer::removePlayer(qintptr handle){
    /*
    auto it = std::find_if(game->players.begin(), game->players.end(), [handle](const Player* p){
        return handle == p->handle;
    });

    Player* player = *it;

    if(it != game->players.end())
        game->players.erase(it);
    else
        qDebug() << "Error, could not remove player...\n";

    //disconnect readyReady signal from dealer.
    disconnect(connections[handle]);

    emit clientLeaving(handle);
    //connections[handle] = connect(clients[handle]->socket, &QTcpSocket::readyRead, this, std::bind(&Server::readPacket, this, handle));
    */
}

Player* Dealer::findNextPlayer(Player* current_player){
    int seat = current_player->id;
    int id = current_player->id;

    auto it = std::find_if(game->players.begin(), game->players.end(), [id](const Player* p){return p->id == id;});
    auto original = it;

    do {
        it++; //advance to next player.

        //end of vector; go back to begining.
        if(it == game->players.end())
            it = game->players.begin();


        Player* player = *it;
        if(player->move != Player::FOLD){
            return player;
        }
    } while(it != original);

    //no next player.
    return nullptr;
}


void Dealer::readMove(qintptr handle, QString payload){
    int id = handle_seats[handle];

    game->player_timer.stop(); //stop timer; prevent player from timing out.
    qDebug() << "Player " << id << " has " << payload << endl;

}


void Dealer::messageAll(Packet outgoing){
    for(auto key: clients.keys()){
        Packet temp(outgoing);
        clients.value(key)->write(temp.package());
    }
}


//Called once and only once when game starts for the first time.
//initializes the button pointer.
Player* Dealer::findButton(){
    return game->players.front();
}


/*
 * Betting order
 * Button->Small Blind->Big Blind (last).
 *
 * The person to the left (clockwise) of the big blind bets first.
 *
 *
 *
 *
 *
*/
void Dealer::dealNewHand(){
    std::cout << "Game: " << game << std::endl;
    //game->next_hand_timer.stop();
    std::cout << "Dealing new hand...";

    this->shuffle();

    std::cout << "Shuffled deck.\n";
    //remove cards from back of deck and give to player.
    for(auto &player: game->players){
        std::cout << "Dealing player ";
        std::cout << player->id << std::endl;
        player->card1 = deck.back();
        deck.pop_back();

        player->card2 = deck.back();
        deck.pop_back();

        QString cards = QString::number(player->card1.id) + "," + QString::number(player->card2.id);
        Packet out(Packet::S2C_CARDSDEALT, cards);
        std::cout << "Sending packet...\n";
        player->socket->write(out.package());
    }

    //button will be nullptr for first game; initialize it.
    if(!button) button = findButton();

    std::cout << "Updating positional pointers.\n";
    //update positional pointers.
    button = findNextPlayer(button);

    std::cout << "Set button.\n";
    small_blind = findNextPlayer(button);
    big_blind = findNextPlayer(small_blind);
    lead_better = findNextPlayer(big_blind);

    std::cout << "Lead better: ";
    std::cout << lead_better->id << std::endl;

    //notify all players of betting order.
    Packet outgoing(Packet::Opcode::S2C_PLAYER_TURN, QString::number(lead_better->id));
    messageAll(outgoing);

    //start timer for next player.
    game->player_timer.start(game->timer_duration);
}

void Dealer::shuffle(){
    deck = newDeck();

    std::default_random_engine rng(std::random_device{}());
    std::shuffle(deck.begin(), deck.end(), rng);
}

QVector<Card> Dealer::newDeck(){
    QVector<Card> deck;

    for(int i = 0; i < DECK_SIZE; i++){
        deck.push_back(Card(i));
    }

    return deck;
}
