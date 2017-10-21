#include <QFile>
#include <QMessageBox>
#include <QRadioButton>
#include <QDebug>
#include <QThread>
#include <QSqlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPair>
#include <QSqlDatabase>
#include <QImage>

#include "../packet.h"

#include "player.h"
#include "client.h"
#include "game.h"
#include "loginwindow.h"
#include "countdowntimer.h"

#include "ui_loginwindow.h"
#include "ui_account.h"

Client::Client(LoginWindow* login_window, QObject *parent) :
    QObject(parent),
    account(this),
    login_window(login_window),
    menu(this),
    game(new Game(this)),
    card_sheet("images/cardDeck.png"),
    socket(new QTcpSocket(this))
{

    //this->loadHost();

    host = "localhost";
    port = 44444;
    if(!this->connectTcp()){
        login_window->ui->label_status->setText("Failed to connect to host: " + host);
        //QMessageBox::information(&account, QString("Failed to Connect!"), QString("Failed to connect to host: " + host));
        login_window->ui->button_create_account->setEnabled(false);
        login_window->ui->button_login->setEnabled(false);
    }

    this->sendPacket(Packet(Packet::Opcode::C2S_KEY, "asdf"));

    account.socket = this->socket;
    account.login_ui = login_window->ui;

    connect(socket, &QTcpSocket::readyRead, this, &Client::readPacket);
    connect(login_window->ui->button_connect_direct, &QPushButton::clicked, this, &Client::connectToGame);
    //connect(login_window->ui->button_connect_direct, &QPushButton::clicked, game, &Game::setup);



    //connect login window functions to account...
    connect(&account, &QDialog::rejected, login_window, &LoginWindow::show);
    connect(login_window->ui->button_login, &QPushButton::clicked, &account, &Account::login);
    connect(login_window->ui->button_create_account, &QPushButton::clicked, &account, [&](){
        account.show(); //toggle login and create account windows.
        this->login_window->hide();
    });

    //game->setup();

    //menu.show();
}

void Client::connectToGame(){
    QString host = login_window->ui->line_hostname->text();

    if(host.isEmpty()) return;
    if(!host.contains(':')) return;

    port = host.splitRef(':')[1].toInt();
    host = host.splitRef(':')[0].toString();

    qDebug() << "host: " << host;
    qDebug() << "port: " << port;

    game->setup();

    if(this->connectTcp()){
        if(game->mode = Game::ACCOUNT)
            sendPacket(Packet(Packet::Opcode::C2S_KEY, "asdf"));

        //if(game->setup())
        game->show();
        login_window->close();
    }
    else{
        QMessageBox::information(&account, QString("Failed to Connect!"), QString("Failed to connect to host: " + host));
    }
}


bool Client::connected(){
    return this->socket->state() == QTcpSocket::ConnectedState;
}

bool Client::connectTcp(){
    socket->connectToHost(host, port);
    return socket->waitForConnected(5000);
}

void Client::loadHost(){
    QFile file("host.config");

    if(!file.open(QIODevice::ReadOnly)){
        QString msg = "Please add 'host.config' to your installation directory.\nThe file should contain the host and port (i.e. localhost:45454).";

        QMessageBox::information(&account, QString("Cannot Find File!"), msg);
        exit(1);
    }

    QTextStream input(&file);
    QString info = input.readLine();

    //invalid format.
    if(info.split(':').size() != 2) return;

    host = info.split(':')[0];
    port = QString(info.split(':')[1]).toUInt();
}


void Client::sendPacket(Packet packet){
    qDebug() << "sendPacket called!";
    socket->write(packet.package());
}

void Client::readPacket(){
    socket->waitForBytesWritten(10);

    while(socket->bytesAvailable()){
        Packet incoming;
        incoming = socket->read(PACKET_SIZE);

        incoming.unpack();

        int i = 0;
        QString str1 = "";
        QString str2 = "";

        qDebug() << "Opcode: " << int(incoming.opcode);
        qDebug() << "Payload: " << incoming.payload;

        switch(incoming.opcode){

            case Packet::Opcode::S2C_GAME_INFO:
                qDebug() << "Received Game Info!";
                qDebug() << incoming.payload;
                menu.updateGame(incoming.payload);
                break;
            case Packet::Opcode::S2C_MESSAGE:
                qDebug() << "Got a chat message.";
                game->displayMessage(incoming.payload);
                break;
            case Packet::Opcode::S2C_CARDSDEALT:
                player->setCards(incoming.payload);
                game->refreshTable();
                break;
            case Packet::Opcode::S2C_ACCOUNT_ACCEPTED:
                qDebug() << "Account succesfully created!\n";
                account.promptAccountSuccess();
                login_window->show();
                break;
            case Packet::Opcode::S2C_ACCOUNT_REJECTED:
                qDebug() << "Could not create account.\n";
                break;
            case Packet::Opcode::S2C_LOGIN_SUCCESS:
                qDebug() << "Login success!\n";
                login_window->ui->button_login->setEnabled(true);
                login_window->ui->label_status->setText("");
                login_window->hide();
                menu.show();
                break;
            case Packet::Opcode::S2C_NEW_HAND:
                game->startNewGameTimer();
                break;
            case Packet::Opcode::S2C_LOGIN_FAILURE:
                qDebug() << "Login failure!\n";
                login_window->ui->button_login->setEnabled(true);
                login_window->ui->label_status->setText(incoming.payload);
                break;
            case Packet::Opcode::S2C_SEAT_ACCEPT:
                qDebug() << "The server has ok'ed our seat.\n";
                addSelf(incoming.payload);
                break;
            case Packet::Opcode::S2C_SEAT_REJECT:
                qDebug() << "The dealer has rejected our seat.\n";
                break;
            case Packet::Opcode::S2C_ADD_PLAYER:
                qDebug() << "The dealer is telling us a player has joined the game.";
                addPlayer(incoming.payload);
                break;
            case Packet::Opcode::S2C_PLAYER_TURN:
                game->setPlayerTurn(incoming.payload);
                qDebug() << "The deal is telling us it's a player's turn.\n";
                break;
            case Packet::Opcode::S2C_BLINDS:
                qDebug() << "Setting blinds for this hand.";
                game->setBlinds(incoming.payload);
                break;
            case Packet::Opcode::S2C_REMOVE_PLAYER:
                qDebug() << "A player has left the game.\n";
                game->removePlayer(incoming.payload);
                break;
        default:
            qDebug() << "UNKNOWN PACKET!!!!\n";
            qDebug() << "Contents: " << incoming.payload;
        }
    }
}

void Client::addPlayer(JsonString json_str){
    QJsonObject json = QJsonDocument::fromJson(json_str.toUtf8()).object();

    qDebug() << "Seat packet: " << json_str;

    QString username = json["username"].toString();
    int game_id = json["game_id"].toInt();
    int seat_id = json["seat_id"].toInt();

    qDebug() << "Seat ID: " << seat_id;

    Player *player = new Player(seat_id, username);
    game->addPlayer(player);
    //player->setCardSheet(&card_sheet);
}

void Client::addSelf(QString payload){
    int seat_id = payload.toInt();

    this->player = new Player(seat_id, this->account.username);
    game->addPlayer(this->player);

    game->hideSeatButtons();
    qDebug() << "Adding card...\n";

    qDebug() << "labelcard1: " << player->seat->labelCard1;

    connect(player->seat->timer, &CountdownTimer::timeout, player, &Player::fold);
    //player->setCardSheet(&card_sheet);
}

void Client::leaveGame(int game_id){
    qDebug() << "The client has left the game!\n";
    this->sendPacket(Packet(Packet::Opcode::C2S_DISCONNECT));

    game->hide();
}

