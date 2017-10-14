#include <QJsonDocument>
#include <QJsonObject>
#include <QImage>
#include <QDebug>

#include "player.h"
#include "seat.h"
#include "card.h"
#include "countdowntimer.h"

Player::Player(int handle, int id, QString name, QObject *parent) : QObject(parent), handle(handle), id(id), name(name), move(BET)
{
    seat = nullptr;
    timer = nullptr;
}

Player::Player(int seatid, QString name):id(seatid), name(name)
{
    seat = nullptr;
    timer = nullptr;
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


void Player::setCards(int c1, int c2){
    card1 = Card(c1, seat->labelCard1);
    card2 = Card(c2, seat->labelCard2);
}

void Player::setCards(QString payload){
    int c1 = payload.split(",")[0].toInt();
    int c2 = payload.split(",")[1].toInt();

    setCards(c1, c2);
}

void Player::displayCards(){
    card1.show();
    card2.show();
}
void Player::displayChips(){
    for(auto &stack: seat->chipStacks){
        stack->show();
    }
}

void Player::startCountdownTimer(){
    seat->timer->raise();
    seat->timer->show();
    seat->timer->start();
}

void Player::fold(){
    qDebug() << "Player " << id << " has folded.\n";
}

void Player::displayBigBlind(){


}
void Player::displaySmallBlind(){}
void Player::displayDealer(){}
void Player::hideBlindChip(){}
