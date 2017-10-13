#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QTcpSocket>

#include "../globals.h"
#include "card.h"
#include "community.h"
#include "countdowntimer.h"

class Account;
class Seat;

class Player : public QObject
{
    Q_OBJECT
    friend class Dealer;
    friend class Client;
    friend class Seat;
    friend class Game;
public:
    Player(int handle, int id, QString name, QObject *parent = 0);
    Player(int seatid, QString name);

    QString getName() const { return name; }
    int getId() const { return id; }

    enum Move {FOLD, CALL, BET, CHECK} move;

    void setCards(int c1, int c2);
    void setCards(QString payload);

    void displayCards();
    void displayChips();

    void startCountdownTimer();
    void fold();

    void bet(int amount);
    void call(int amount);

    void check();
private:
    const int id;
    int handle;
    QString name;

    int chips;
    int hand_contribution;
    int round_contribution; //chips contributed this round (i.e. flop, turn, river).

    Card card1;
    Card card2;

    JsonString toJsonString();

    QTcpSocket* socket;
    Seat* seat;
    CountdownTimer* timer;
};

#endif // PLAYER_H
