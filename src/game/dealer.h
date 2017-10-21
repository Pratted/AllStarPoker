#ifndef DEALER_H
#define DEALER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QMap>
#include <QTimer>
#include <QVector>
#include <memory>

#include "../globals.h"
#include "../packet.h"
#include "card.h"
#include "hand.h"

class Player;
class Game;

/********************************************************************
 * The dealer is responsible for managing the player's moves and
 * controling the flow of the game.
 *
 *
 * The hand is over when there one non-folded player left or
 * all of the betting rounds have been completed.
 *******************************************************************/
class Dealer : public QTcpServer
{
    Q_OBJECT
public:
    Dealer(Game* game, QObject* parent = 0);

    Player* findButton();
    Player* findNextPlayer(Player* current_player);

    static void shuffle(QVector<Card> &deck);
    static QVector<Card> newDeck();

public slots:
    void readPacket(qintptr handle); //{ qDebug() << "The dealer has received a packet!\n"; }
    void removeClient(qintptr handle);

    //Dealer::~Dealer(){}

    void incomingConnection(qintptr handle);
    void authenticate(qintptr handle, QString payload);
    void sendExistingPlayers(qintptr handle);
    void forwardChatMessage(Packet& packet);
    void readMove(qintptr handle, QString payload, bool forced_move = false);

    void prepareGameStart(); //new game
    void prepareHandStart(); //new hand

    void dealNewHand();
    void dealNextRound();
    void forceFold();

    void dealFlop();
    void dealTurn();
    void dealRiver();

    void clearTable(){}
    void messageAll(Packet packet);
    void distributeWinnings();
signals:
    void clientLeaving(qintptr handle);

private:
    void seatClient(qintptr handle, JsonString json_str);
    QMap<int, QMetaObject::Connection> connections;
    QMap<int, QTcpSocket*> clients;
    QMap<int, int> handle_seats;

    QMap<int, int> id_to_handle;
    QMap<int, Player*> id_to_player;

    Game* game;
    QVector<Card> deck;
    std::unique_ptr<Hand> hand; //unique ptr since 'new' hands will often be dealt.

    Player* button;
    Player* small_blind;
    Player* big_blind;
    Player* lead_better;
    Player* prev_lead_better;
    Player* current_player;
};

#endif // DEALER_H
