#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QTcpSocket>
#include <QLabel>

//#include "card.h"

typedef QString JsonString;

class Seat;
class Game;

class Player : public QObject
{
    Q_OBJECT

    friend class Client;
    friend class Game;
public:
    Player(QObject *parent = 0);
    Player(int seatid):id(seatid){}
    Player(int seatid, QString name):id(seatid), name(name){}
    Player(JsonString json_player);

    //Player(Player &) = delete;
    //Player(Player &&) = delete;
    //Player& operator=(Player &rhs) = delete;
    //Player& operator=(Player &&rhs) = delete;

    QTcpSocket* socket = nullptr;
    QLabel* labelChipCount;
    Seat* seat;

    QString getName() const{ return name; }
    int getId() const { return id; }

    //Card card1;
    //Card card2;

    bool isSeated = false;
private:

    int id;
    QString name;
    int chip_count;
};

#endif // PLAYER_H
