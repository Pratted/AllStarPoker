#include <QJsonDocument>
#include <QJsonObject>

#include "../player.h"

Player::Player(int handle, int id, QString name, QObject *parent) : QObject(parent), handle(handle), id(id), name(name), move(BET)
{

}


JsonString Player::toJsonString(){
    QJsonObject json;
    json.insert("seat_id", id);
    json.insert("username", name);
    //json.insert("current_players", long(5));
    //json.insert("chip_count", int(chip_count));
    //json.insert("id", id);
    //json.insert("status", int(status));

    QJsonDocument doc(json);
    return QString(doc.toJson(QJsonDocument::Compact));
}


void Player::setCards(int c1, int c2){}

