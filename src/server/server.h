#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QThread>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QJsonObject>
#include <QVector>
#include <QMap>
#include <QProcess>

#include <vector>
#include <unordered_map>
#include <set>

#include "../globals.h"

//#include "player.h"

class Game;
class Player;
class Client;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject* parent = 0);
    //~Server(){}

    bool start();
    bool loadGames();

    //std::unordered_map<int, QTcpSocket*> clients;
    std::unordered_map<int, Client*> clients;
    std::unordered_map<int, QMetaObject::Connection> connections;

public slots:
    void readPacket(qintptr handle);
    //void moveClientToGame(qintptr handle, int gameno);
    void handleDisconnect(qintptr handle);
    void sendSeatedPlayers(qintptr handle, int gameno);
    //void removePlayer(int handle, int gameno);
    void returningClient(qintptr handle);

    bool createAccount(qintptr, QJsonObject);
    bool authenticate(qintptr handle, QJsonObject json);

protected:
    void incomingConnection(qintptr handle);

private:
    QTimer timer;
    QSqlDatabase database;

    QMap<int, QProcess*> games;
    //std::vector<Game*> games;

    //std::vector<Game*> games;
    //std::unordered_map<int, Player*> clients2;
    std::set<QString> users_online;

    void sendGameInfo(qintptr handle); // Send Game Info for every game. (used for new connections).
    void sendGameInfo(qintptr handle, int gameno); //Send game info for one game. (used if one game is updated).

    bool connectToDatabase();

    //void seatClient(qintptr handle, JsonString json_str);
};

#endif // SERVER_H
