#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QDebug>

#include "card.h"

QImage Card::card_sheet = QImage("../images/cardDeck.png");

Card::Card():_id(-1), _rank(-1){
    card_back = nullptr;
    card_front = nullptr;
}
Card::Card(int id){
    card_back = nullptr;
    card_front = nullptr;

    if(id == ACE_HIGH){
        _rank = 13;
        _id = ACE_HIGH;
        _suit = CLUB;
    }
    else{
        _id = id;
        _rank = id % 13;
        _suit = Suit(id / 13);
    }
}

Card::Card(int id, QLabel* label){
    card_back = nullptr;
    card_front = nullptr;

    _img = label;

    if(id == ACE_HIGH){
        _rank = 13;
        _id = ACE_HIGH;
        _suit = CLUB;
    }
    else{
        _id = id;
        _rank = id % 13;
        _suit = Suit(id / 13);
    }
}

Card::Card(const Card &rhs){
    _rank = rhs._rank;
    _suit = rhs._suit;
    _id = rhs._id;
    _img = rhs._img;

    card_front = new QImage(card_sheet.copy(CARD_WIDTH * _rank, CARD_HEIGHT * _suit, CARD_WIDTH, CARD_HEIGHT));
    card_back = new QImage(card_sheet.copy(CARD_WIDTH * 0, CARD_HEIGHT * 4, CARD_WIDTH, CARD_HEIGHT));
}

Card::Card(Card &&rhs){
    _rank = rhs._rank;
    _suit = rhs._suit;
    _id = rhs._id;
    _img = rhs._img;

    card_front = new QImage(card_sheet.copy(CARD_WIDTH * _rank, CARD_HEIGHT * _suit, CARD_WIDTH, CARD_HEIGHT));
    card_back = new QImage(card_sheet.copy(CARD_WIDTH * 0, CARD_HEIGHT * 4, CARD_WIDTH, CARD_HEIGHT));
}

Card& Card::operator=(const Card &rhs){
    _rank = rhs._rank;
    _suit = rhs._suit;
    _id = rhs._id;
    _img = rhs._img;

    card_front = new QImage(card_sheet.copy(CARD_WIDTH * _rank, CARD_HEIGHT * _suit, CARD_WIDTH, CARD_HEIGHT));
    card_back = new QImage(card_sheet.copy(CARD_WIDTH * 0, CARD_HEIGHT * 4, CARD_WIDTH, CARD_HEIGHT));
}

Card& Card::operator=(Card &&rhs){
    _rank = rhs._rank;
    _suit = rhs._suit;
    _id = rhs._id;
    _img = rhs._img;

    card_front = new QImage(card_sheet.copy(CARD_WIDTH * _rank, CARD_HEIGHT * _suit, CARD_WIDTH, CARD_HEIGHT));
    card_back = new QImage(card_sheet.copy(CARD_WIDTH * 0, CARD_HEIGHT * 4, CARD_WIDTH, CARD_HEIGHT));
}



Card::~Card(){
    if(card_front) delete card_front;
    if(card_back) delete card_back;
}

void Card::setId(int id){
    _id = id;
    _rank = (id % 13);
    _suit = Suit(id / 13);
}

void Card::setRank(int rank){
    _rank = rank;
}

void Card::setLabel(QLabel *label){
    _img = label;
}


void Card::showFront(){
    if(!card_front){
        card_front = new QImage(card_sheet.copy(CARD_WIDTH * _rank, CARD_HEIGHT * _suit, CARD_WIDTH, CARD_HEIGHT));
    }

    _img->setPixmap(QPixmap::fromImage(*card_front));
    _img->show();
}

void Card::showBack(){
    if(!card_back){
        card_back = new QImage(card_sheet.copy(CARD_WIDTH * 0, CARD_HEIGHT * 4, CARD_WIDTH, CARD_HEIGHT));
    }

    _img->setPixmap(QPixmap::fromImage(*card_back));
    _img->show();
}

void Card::show(){
    if(_rank == -1)
        showBack();
    else
        showFront();
}

void Card::hide(){
    _img->hide();
}
