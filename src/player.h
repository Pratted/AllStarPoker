#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QTcpSocket>

#include "globals.h"
#include "card.h"

class Account;
class Seat;

class Player : public QObject
{
    Q_OBJECT
    friend class Dealer;
    friend class Client;
    friend class Seat;
public:
    explicit Player(int handle, int id, QString name, QObject *parent = 0);
    Player(int seatid, QString name):id(seatid), name(name){}

    QString getName() const { return name; }
    int getId() const { return id; }

    enum Move {FOLD, CALL, RAISE} move;

private:
    const int id;
    int handle;
    QString name;

    Card card1;
    Card card2;

    JsonString toJsonString();

    QTcpSocket* socket = nullptr;
    Seat* seat = nullptr;
};

#endif // PLAYER_H
