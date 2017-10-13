#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QJsonObject>
#include <QVector>
#include <QTcpSocket>
#include <QSqlDatabase>

#include "dealer.h"
#include "../community.h"

#define MAX_TABLE_SIZE 8
#define DEFAULT_COUNTDOWN 5000 //milliseconds
#define DECK_SIZE 52

typedef QString JsonString;

class Player;
class Dealer;

class Game: public QObject
{
    Q_OBJECT
    friend class Dealer;
public:
    Dealer dealer;
    //std::cout << "Usage: " << "<name> <id> <size> <chip count> <small blind> <big blind> <port>\n";

    //Game(int id, int max_players, long chip_count);
    Game(QString name, int id, int size, long chip_count, int small_small, int big_blind, int timer_duration, int port);

    enum Status {
        WAITING_FOR_PLAYERS,
        STARTING,
        IN_PROGRESS
    } status;

    enum Mode {
        ANYONE_CAN_JOIN,
        ACCOUNTS_ONLY,
        PASSWORD_PROTECTED
    } mode;

    Community community;
    int getid();
    int getnumPlayers();
    int getmaxPlayers();
    long getchipCount();

    bool start();

    int size() const { return players.size(); }

    QString toJsonString();
    QVector <Player*> players;
    QMap <int, QTcpSocket*> clients;

    ~Game() {}

signals:
    void ended();

private:
    QSqlDatabase db;
    bool connectToDatabase();

    const size_t id;
    const size_t capacity;
    const size_t chip_start_amount;
    const size_t timer_duration;
    const QString name;

    QTimer player_timer;
    QTimer next_hand_timer;

    int small_blind;
    int big_blind;
    qint16 port;
};

#endif // GAME_H
