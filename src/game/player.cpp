#include <QJsonDocument>
#include <QJsonObject>
#include <memory>

#include "player.h"
#include "hand.h"

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


void Player::call(std::unique_ptr<Hand> &hand){
    move = Player::CALL;
    int amount_to_call = hand->community.current_bet - round_contribution;

    chips -= amount_to_call;
    hand->community.pot += amount_to_call;
    round_contribution += amount_to_call;
}

void Player::fold(std::unique_ptr<Hand> &hand){
    move = Player::FOLD;

    //hand->removePlayer(this);
}

void Player::bet(std::unique_ptr<Hand> &hand, int amount){
    move = Player::BET;

    int amount_to_call = hand->community.current_bet - round_contribution;
    int raise = 0;

    //player owed chips, but still bet -> implies raise.
    if(amount_to_call) {
        hand->community.current_bet += raise; //current bet increases by raise amount.
    }
    else{
        hand->community.current_bet = amount; //normal bet.
    }

    chips -= amount;
    hand->community.pot += amount;
    round_contribution += amount;

    hand->prev_lead_better = hand->lead_better;
    hand->lead_better = this;
}
