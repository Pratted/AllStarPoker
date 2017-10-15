#include "handstrengthtester.h"
#include "ui_handstrengthtester.h"
#include <random>
#include <QVector>
#include <QDebug>

#include "player.h"

HandStrengthTester::HandStrengthTester(int num_players, QWidget *parent) :
    QMainWindow(parent),
    hand(nullptr),
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

    players[3]->card1.setLabel(ui->player3_card1);
    players[3]->card2.setLabel(ui->player3_card2);

    players[4]->card1.setLabel(ui->player4_card1);
    players[4]->card2.setLabel(ui->player4_card2);

    players[5]->card1.setLabel(ui->player5_card1);
    players[5]->card2.setLabel(ui->player5_card2);

    players[6]->card1.setLabel(ui->player6_card1);
    players[6]->card2.setLabel(ui->player6_card2);

    players[7]->card1.setLabel(ui->player7_card1);
    players[7]->card2.setLabel(ui->player7_card2);

    connect(ui->button_test_again, &QPushButton::clicked, this, &HandStrengthTester::test);
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

void HandStrengthTester::showAllCards(){
    for(auto &p: players){
        p->card1.showFront();
        p->card2.showFront();
    }

    hand->community.flop1.showFront();
    hand->community.flop2.showFront();
    hand->community.flop3.showFront();
    hand->community.turn.showFront();
    hand->community.river.showFront();

}

void HandStrengthTester::test(){
    dealer = Dealer();
    hand = new Hand(players, nullptr);

    hand->community.flop1.setLabel(ui->card1);
    hand->community.flop2.setLabel(ui->card2);
    hand->community.flop3.setLabel(ui->card3);
    hand->community.turn.setLabel(ui->card4);
    hand->community.river.setLabel(ui->card5);

    for(auto &player: players){
        player->card1 = Card(dealer.deck.back(), player->card1.img());
        dealer.deck.pop_back();

        player->card2 = Card(dealer.deck.back(), player->card2.img());
        dealer.deck.pop_back();
    }

    hand->community.flop1 = Card(dealer.deck.back(), ui->card1);
    dealer.deck.pop_back();
    hand->community.flop2 = Card(dealer.deck.back(), ui->card2);
    dealer.deck.pop_back();
    hand->community.flop3 = Card(dealer.deck.back(), ui->card3);
    dealer.deck.pop_back();
    hand->community.turn = Card(dealer.deck.back(), ui->card4);
    dealer.deck.pop_back();
    hand->community.river = Card(dealer.deck.back(), ui->card5);
    dealer.deck.pop_back();

    showAllCards();
    delete hand;
}
