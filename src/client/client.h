#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QImage>
#include <QLabel>

#include "../packet.h"
#include "../globals.h"

#include "account.h"
#include "mainmenu.h"

//QImage CARD_SHEET("images/cardDeck.png");

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
    void addSelf(QString payload);

    Account* getAccount(){ return &account; }
signals:


public slots:
    void readPacket();
    void sendPacket(Packet packet);
    void addPlayer(JsonString json_str);
    void leaveGame(int game_id);
    void connectToGame(); //manually connect to a game from login window.

private:
    QTcpSocket* socket;

    Player* player;
    Game* game;

    QString host = "";
    quint16 port = 0;

    QImage card_sheet;
    Account account;
    MainMenu menu;
    LoginWindow* login_window;

    void loadHost();
};

#endif
