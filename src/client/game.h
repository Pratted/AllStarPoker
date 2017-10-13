#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QRadioButton>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QTimer>
#include <QImage>

#include "../globals.h"
#include "../packet.h"
#include "seat.h"
#include "community.h"

#define MAX_TABLE_SIZE 8

namespace Ui {
class Game;
}

class Player;
class Account;
class Client;


class Game : public QMainWindow
{
    Q_OBJECT
    friend class Client;

public:
    Game() = default;
    Game(Client* client);
    Game(QWidget *parent);
    Game(Client * client, JsonString str_game);

    enum Status {
        WAITING_FOR_PLAYERS,
        STARTING,
        IN_PROGRESS
    } status;

    enum {
        ANYONE,
        ACCOUNT
    } mode;

    QString statusToString();

    int id;
    int numPlayers() const { return num_players; }
    int maxPlayers() const { return max_players; }
    int chipCount() { return chip_count; }
    QString promptName();
    void displayMessage(QString message);
    void removePlayer(QString payload);
    void refreshTable();
    void setPlayerTurn(QString payload);

    QPushButton* push_button;
    QVector<Seat> seats;
    QVector <Player*> players;

    //pointers to widgets on main menu.
    struct TableRow {
        QTableWidgetItem* item_max_players;
        QTableWidgetItem* item_curr_players;
        QTableWidgetItem* item_chip_count;
        QTableWidgetItem* item_status;
    } table_row;

    /*
    class BetMenu {
    private:
        QLabel* button_holder;
        QLabel* card_holder;
        QLabel* card1;
        QLabel* card2;

        QPushButton* button_submit;
        QPushButton* button_cancel;
        QPushButton* button_bet;
        QPushButton* button_fold;
        QPushButton* button_decrement_bet;
        QPushButton* button_increment_bet;
    public:

        void show();



    } bet_menu;
    */

    ~Game();
signals:
    void packetReady(Packet);

public slots:
    void peek();
    int chooseSeat(int seat_id);
    bool setup();
    void addPlayer(Player* player);
    void sendMessage();
    void startNewGameTimer();

private:
    Ui::Game *ui;
    Account* account;
    Client* client;
    Community community;

    QTimer new_game_timer;

    int num_players;
    int max_players;
    int chip_count;

    void hideSeatButtons();
    void positionSeats();
    void setBackground();
    void countdown();
    void hideBetMenu();
    void showBetMenu();
    void startRoundTimer();

    Player* getPlayerFromId(int id);
};

#endif // GAME_H
