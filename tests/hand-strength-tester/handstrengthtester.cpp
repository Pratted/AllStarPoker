#include "handstrengthtester.h"
#include "ui_handstrengthtester.h"
#include <random>
#include <QVector>

#include "player.h"

HandStrengthTester::HandStrengthTester(int num_players, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HandStrengthTester)
{
    ui->setupUi(this);

    for(int i = 0; i < 8; i++){
        this->players.push_back(new Player);
    }

    players[0]->card1.setLabel(ui->player0_card1);
    players[0]->card2.setLabel(ui->player0_card2);

    players[1]->card1.setLabel(ui->player1_card1);
    players[1]->card2.setLabel(ui->player1_card2);

    players[2]->card1.setLabel(ui->player2_card1);
    players[2]->card2.setLabel(ui->player2_card2);

    players[3]->card1.setLabel(ui->player3_card3);
    players[3]->card2.setLabel(ui->player3_card2);

    players[4]->card1.setLabel(ui->player4_card1);
    players[4]->card2.setLabel(ui->player4_card2);

    players[5]->card1.setLabel(ui->player5_card1);
    players[5]->card2.setLabel(ui->player5_card2);

    players[6]->card1.setLabel(ui->player6_card1);
    players[6]->card2.setLabel(ui->player6_card2);

    players[7]->card1.setLabel(ui->player7_card1);
    players[7]->card2.setLabel(ui->player7_card2);
}

HandStrengthTester::~HandStrengthTester()
{
    for(auto &p: players){
        delete p;
    }

    delete ui;
}


//create and shuffle a new deck of cards.
HandStrengthTester::Dealer::Dealer(){
    for(int i = 0; i < 52; i++){
        deck.push_back(i);
    }

    std::default_random_engine rng(std::random_device{}());
    std::shuffle(deck.begin(), deck.end(), rng);
}



void HandStrengthTester::test(){
    for(auto &player: players){
        player->card1 = Card(dealer.deck.back());
        dealer.deck.pop_back();

        player->card2 = Card(dealer.deck.back());
        dealer.deck.pop_back();
    }

}
