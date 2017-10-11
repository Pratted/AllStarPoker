#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QRadioButton>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QTimer>

#include "packet.h"
#include "seat.h"

typedef QString JsonString;

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
    Game(QWidget *parent);
    Game(Client * client, JsonString str_game);

    enum Status {
        WAITING_FOR_PLAYERS,
        STARTING,
        IN_PROGRESS
    } status;

    QString statusToString();

    int id;
    int numPlayers() const { return num_players; }
    int maxPlayers() const { return max_players; }
    int chipCount() { return chip_count; }

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


    ~Game();
signals:
    void packetReady(Packet);

public slots:
    void peek();
    int chooseSeat(int seat_id);
    void showOpenSeats();
    void setupSeats();
    void addPlayer(Player* player);
    void sendMessage();

private:
    Ui::Game *ui;
    Account* account;
    Client* client;

    QTimer nextRoundTimer;

    int num_players;
    int max_players;
    int chip_count;

    void positionSeats();
    void setBackground();
    void countdown();
    void hideBetMenu();
    void showBetMenu();
    void startRoundTimer();
};

#endif // GAME_H
