#include <QVector>
#include <QDebug>
#include <iostream>
#include <string>
#include <random>

#include "handstrengthtester.h"
#include "ui_handstrengthtester.h"
#include "player.h"
#include "hand.h"

HandStrengthTester::HandStrengthTester(int num_players, QWidget *parent) :
    QMainWindow(parent),
    hand(nullptr),
    ui(new Ui::HandStrengthTester)
{
    ui->setupUi(this);

    for(int i = 0; i < 8; i++){
        this->players.push_back(new Player(i));
    }

    players[0]->card1.setLabel(ui->player0_card1);
    players[0]->card2.setLabel(ui->player0_card2);
    players[0]->label = ui->player0;

    players[1]->card1.setLabel(ui->player1_card1);
    players[1]->card2.setLabel(ui->player1_card2);
    players[1]->label = ui->player1;

    players[2]->card1.setLabel(ui->player2_card1);
    players[2]->card2.setLabel(ui->player2_card2);
    players[2]->label = ui->player2;

    players[3]->card1.setLabel(ui->player3_card1);
    players[3]->card2.setLabel(ui->player3_card2);
    players[3]->label = ui->player3;

    players[4]->card1.setLabel(ui->player4_card1);
    players[4]->card2.setLabel(ui->player4_card2);
    players[4]->label = ui->player4;

    players[5]->card1.setLabel(ui->player5_card1);
    players[5]->card2.setLabel(ui->player5_card2);
    players[5]->label = ui->player5;

    players[6]->card1.setLabel(ui->player6_card1);
    players[6]->card2.setLabel(ui->player6_card2);
    players[6]->label = ui->player6;

    players[7]->card1.setLabel(ui->player7_card1);
    players[7]->card2.setLabel(ui->player7_card2);
    players[7]->label = ui->player7;

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

    std::cout << "---------------------------- New Hand ---------------------------\n";


    for(auto &player: players){
        Hand::ranked_hand player_hand = hand->best5CardHand(player);
        QString desc = Hand::toString(player_hand) + "\n";

        for(auto &c: player_hand.hand){
            desc += QString::number(c.rank()) + " ";
        }
        player->label->setText(desc);
        std::cout << player_hand.hand;
    }

    hand->getHandWinners(ui->description);

    showAllCards();
    delete hand;
}

void HandStrengthTester::test_custom(QVector<int> &cards){
    hand = new Hand(players, nullptr);

    hand->community.flop1.setLabel(ui->card1);
    hand->community.flop2.setLabel(ui->card2);
    hand->community.flop3.setLabel(ui->card3);
    hand->community.turn.setLabel(ui->card4);
    hand->community.river.setLabel(ui->card5);

    for(auto &player: players){
        player->card1 = Card(cards.back(), player->card1.img());
        cards.pop_back();

        player->card2 = Card(cards.back(), player->card2.img());
        cards.pop_back();
    }

    hand->community.flop1 = Card(cards.back(), ui->card1);
    cards.pop_back();
    hand->community.flop2 = Card(cards.back(), ui->card2);
    cards.pop_back();
    hand->community.flop3 = Card(cards.back(), ui->card3);
    cards.pop_back();
    hand->community.turn = Card(cards.back(), ui->card4);
    cards.pop_back();
    hand->community.river = Card(cards.back(), ui->card5);
    cards.pop_back();

    std::cout << "---------------------------- New Hand ---------------------------\n";

    for(auto &player: players){
        Hand::ranked_hand player_hand = hand->best5CardHand(player);
        QString desc = Hand::toString(player_hand) + "\n";

        for(auto &c: player_hand.hand){
            desc += QString::number(c.rank()) + " ";
        }
        player->label->setText(desc);
    }

    hand->getHandWinners(ui->description);
    std::string desc = ui->description->text().toStdString();
    std::cout << desc << std::endl;

    showAllCards();
    delete hand;
}

