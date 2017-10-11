#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QSqlDatabase>

#include "account.h"
#include "packet.h"
#include "mainmenu.h"

typedef QString JsonString;

class MainMenu;
class Game;
class Player;
class LoginWindow;

class Client : public QObject
{
    Q_OBJECT
    friend class Game;
public:
    explicit Client(LoginWindow* login_window, QObject *parent = 0);

    bool connected();
    bool connectTcp();

    Account* getAccount(){ return &account; }
signals:


public slots:
    void readPacket();
    void sendPacket(Packet packet);
    void addPlayer(JsonString json_str);
    void leaveGame(int game_id);

private:
    QTcpSocket* socket;

    Player* player;
    Game* game;

    QString host = "";
    quint16 port = 0;

    Account account;
    MainMenu menu;
    LoginWindow* login_window;
    QSqlDatabase db;

    void loadHost();
};

#endif
