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

#include "client.h"
#include "game.h"
#include "player.h"
#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "ui_account.h"



Client::Client(LoginWindow* login_window, QObject *parent) :
    QObject(parent),
    account(this),
    login_window(login_window),
    menu(this),
    db(QSqlDatabase::addDatabase("QMYSQL")),
    socket(new QTcpSocket(this))
{

    if(!this->connectTcp()){
        QMessageBox::information(&account, QString("Failed to Connect!"), QString("Failed to connect to host: " + host));
        exit(1);
    }

    account.socket = this->socket;
    account.login_ui = login_window->ui;

    connect(socket, &QTcpSocket::readyRead, this, &Client::readPacket);

    //connect login window functions to account...
    connect(&account, &QDialog::rejected, login_window, &LoginWindow::show);
    connect(login_window->ui->button_login, &QPushButton::clicked, &account, &Account::login);
    connect(login_window->ui->button_create_account, &QPushButton::clicked, &account, [&](){
        account.show(); //toggle login and create account windows.
        this->login_window->hide();
    });
}

bool Client::connected(){
    return this->socket->state() == QTcpSocket::ConnectedState;
}

bool Client::connectTcp(){
    this->loadHost();
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
        //Packet incoming;
        //socket->read(PACKET_SIZE) >> incoming;

        Packet incoming;
        incoming = socket->read(PACKET_SIZE); // >> incoming;

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
                //menu->updateGames(incoming.payload);
                break;
            case Packet::Opcode::S2C_MESSAGE:
                qDebug() << "Got a chat message.";
                //this->game->displayMessage(incoming.dest, incoming.payload);
                break;
            case Packet::Opcode::S2C_CARDSDEALT:
                //game->addSelf(incoming.payload);
                break;
            case Packet::Opcode::S2C_ACCOUNT_ACCEPTED:
                qDebug() << "Account succesfully created!\n";
                account.promptAccountSuccess();
                login_window->show();
                break;
            case Packet::Opcode::S2C_ACCOUNT_REJECTED:
                qDebug() << "Could not create account.\n";

                //game->addSelf(incoming.payload);
                break;
            case Packet::Opcode::S2C_LOGIN_SUCCESS:
                qDebug() << "Login success!\n";
                login_window->ui->button_login->setEnabled(true);
                login_window->ui->label_status->setText("");
                login_window->hide();
                menu.show();
                break;
            case Packet::Opcode::S2C_LOGIN_FAILURE:
                qDebug() << "Login failure!\n";
                login_window->ui->button_login->setEnabled(true);
                login_window->ui->label_status->setText(incoming.payload);
                break;
            case Packet::Opcode::S2C_ADD_PLAYER:
                qDebug() << "The dealer is telling us a player has joined the game.";
                addPlayer(incoming.payload);
                break;
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



    if(account.username == username){
        qDebug() << "Seating myself...\n";
        this->player = player; //player is self.

    }

    game->addPlayer(player);
}

void Client::leaveGame(int game_id){
    qDebug() << "The client has left the game!\n";
    this->sendPacket(Packet(Packet::Opcode::C2S_DISCONNECT));

    game->hide();
}

