#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QTcpSocket>
#include <memory>

#include "../globals.h"
#include "card.h"
#include "community.h"
#include "hand.h"

class Account;
class Seat;

class Player : public QObject
{
    Q_OBJECT
    friend class Dealer;
    friend class Client;
    friend class Hand;
public:
    explicit Player(int handle, int id, QString name, QObject *parent = 0);
    Player(int seatid, QString name):id(seatid), name(name){}

    QString getName() const { return name; }
    int getId() const { return id; }

    enum Move {FOLD, CALL, BET, CHECK, NONE} move;

    void setCards(int c1, int c2);
    void setCards(QString payload);

    void displayCards();
    void displayChips();

    void startCountdownTimer();

    void fold(std::unique_ptr<Hand> &hand);
    void call(std::unique_ptr<Hand> &hand);
    void bet(std::unique_ptr<Hand> &hand, int amount);
private:
    int id;
    int handle;
    QString name;

    int chips;
    //int hand_contribution;
    int round_contribution; //chips contributed this round (i.e. flop, turn, river).
    int timeouts;

    Card card1;
    Card card2;

    JsonString toJsonString();

    QTcpSocket* socket = nullptr;
};

#endif // PLAYER_H
