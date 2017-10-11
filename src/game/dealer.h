#ifndef DEALER_H
#define DEALER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QMap>
#include <QTimer>
#include <QVector>

#include "../globals.h"
#include "../packet.h"
#include "../card.h"

class Player;
class Game;

class Dealer : public QTcpServer
{
    Q_OBJECT
public:
    Dealer(Game* game, QObject* parent = 0): game(game), QTcpServer(parent){}

public slots:
    void readPacket(qintptr handle); //{ qDebug() << "The dealer has received a packet!\n"; }
    void removePlayer(qintptr handle);
    void removeClient(qintptr handle);

    //Dealer::~Dealer(){}

    void incomingConnection(qintptr handle);
    void authenticate(qintptr handle, QString payload);
    void sendExistingPlayers(qintptr handle);
    void forwardChatMessage(Packet& packet);
    void readMove(qintptr handle, QString payload);
    void prepareGameStart();

    void dealNewHand();

    void dealFlop(){}
    void dealTurn(){}
    void dealRiver(){}

    void shuffle();
    void clearTable(){}
    void messageAll(Packet packet);

    Player* findNextPlayer(QVector<Player*>::iterator current_player);

    static QVector<Card> newDeck();
signals:
    void clientLeaving(qintptr handle);

private:
    void seatClient(qintptr handle, JsonString json_str);
    QMap<int, QMetaObject::Connection> connections;
    QMap<int, QTcpSocket*> clients;
    QMap<int, int> handle_seats;

    Game* game;
    QVector<Card> deck;

    Player* button;
    Player* small_blind;
    Player* big_blind;
    Player* lead_better;

    //std::vector<Player*> &players; //reference to the game's players.
    //std::map<int, bool> &seats; //map to check if seats are available.
};

#endif // DEALER_H
