#include <QTableWidget>
#include <QRadioButton>
#include <QString>

#include "../packet.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "game.h"
#include "client.h"

MainMenu::MainMenu(Client* client, QWidget *parent) :
    QMainWindow(parent),
    client(client),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    game_list.widget = ui->wiget_table;
    game_list.headers << "Players" << "Max Players" << "Chip Count" << "Blinds" << "Status" << "Type";

    game_list.widget->horizontalHeader()->setStyleSheet("color: white");
    game_list.widget->setHorizontalHeaderLabels(game_list.headers);
    game_list.widget->horizontalHeader()->setStretchLastSection(true);
}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::updateGame(QString str_game){
    Game* game = new Game(client, str_game);

    qDebug() << "This games id: " << game->id;

    if(games.find(game->id) == games.end()){
        //add to table.
        games[game->id] = game;
        game_list.addGame(game);

        //game->setupSeats(); //initialize seats.

        connect(game, &Game::packetReady, client, &Client::sendPacket); //send packets through client interface
        connect(game->push_button, &QPushButton::clicked, game, &Game::peek); //show players already at table
    }
    else{
        //games[game->id]-> = game;

        //update existing...
    }

}

void MainMenu::Table::addGame(Game* game){
    qDebug() << "Adding game...";

    int row_id = this->games.size();

    this->widget->insertRow(row_id);

    game->push_button = new QPushButton(this->widget);
    game->push_button->setText("Join");
    game->push_button->setStyleSheet("border-radius: 20px;background-color: green");

    this->widget->setCellWidget(row_id, COL_SELECT_BUTTON, game->push_button);

    this->widget->setItem(row_id, COL_MAX_PLAYERS, new QTableWidgetItem(QString::number(game->maxPlayers())));
    this->widget->setItem(row_id, COL_CURRENT_PLAYERS, new QTableWidgetItem(QString::number(game->numPlayers())));
    this->widget->setItem(row_id, COL_STATUS, new QTableWidgetItem(game->statusToString()));
    this->widget->setItem(row_id, COL_CHIP_COUNT, new QTableWidgetItem(QString::number(game->chipCount())));

    game->table_row.item_max_players =this->widget->item(row_id, COL_MAX_PLAYERS);
    game->table_row.item_curr_players =this->widget->item(row_id, COL_CURRENT_PLAYERS);
    game->table_row.item_chip_count =this->widget->item(row_id, COL_CHIP_COUNT);
    game->table_row.item_status =this->widget->item(row_id, COL_STATUS);
}
