#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QRadioButton>

#define COL_CURRENT_PLAYERS 0
#define COL_MAX_PLAYERS 1
#define COL_CHIP_COUNT 2
#define COL_BLINDS 3
#define COL_STATUS 4
#define COL_GAME_TYPE 5
#define COL_SELECT_BUTTON 6

namespace Ui {
class MainMenu;
}

class Game;
class Client;

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(Client* client, QWidget *parent = 0);

    ~MainMenu();

    Ui::MainMenu *ui;

    struct Table {
        QTableWidget* widget;
        QStandardItemModel model;
        QStringList headers;
        QMap<int, QRadioButton*> games;

        void addRow(int pos);
        void addGame(Game* game);
    } game_list;

    //update or add a game if not exist
    void updateGame(QString str_game);

    QMap<int, Game*> games;
    Client* client;
};

#endif // MAINMENU_H
