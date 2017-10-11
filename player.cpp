#include <QString>
#include <QDebug>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>

#include "player.h"
#include "packet.h"

Player::Player(QObject *parent) : QObject(parent), socket(new QTcpSocket(this))
{
    //connect(socket, &QTcpSocket::readyRead, this, &Player::readPacket);
}

Player::Player(JsonString json_player){
    QJsonObject json = QJsonDocument::fromJson(json_player.toUtf8()).object();

    this->name = json["name"].toString();
    this->id = json["id"].toInt();
    this->chip_count = json["chip_count"].toInt();
}
