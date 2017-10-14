#include <QImage>
#include <QPixmap>

#include "player.h"
#include "seat.h"
#include "countdowntimer.h"


QImage Seat::big_blind_img = QImage("images/big_blind.png");
QImage Seat::small_blind_img = QImage("images/small_blind.png");
QImage Seat::dealer_chip_img = QImage("images/dealer.png");

Seat::Seat(int id) :id(id), chipStacks(8) {}

void Seat::clear() {
    placeholder->hide();
    buttonSitInSeat->show();
    playerName->setText("");
    chipCount->setText("");
    playerName->hide();
    chipCount->hide();

    if (isTaken) {
        labelCard1->hide();
        labelCard2->hide();

        //this->timer->hide();
        //player->stopTimer();
        //player.reset();
    }

    isTaken = false;
}

void Seat::display() {
    this->isTaken = true;
    this->buttonSitInSeat->setVisible(false);
    this->placeholder->show();

    this->playerName->raise();
    this->playerName->show();

    this->chipCount->show();
}


//Place a player in this seat.
//Update player's pointers to point to seat's labels.
void Seat::seat(Player *player){
    qDebug() << "Seating player...\n";
    this->player = player;
    qDebug() << "Player: " << player;

    player->seat = this;

    player->seat->playerName->setText(player->getName());
    player->timer = this->timer;

    qDebug() << "About to show seat.\n";
    this->display();
    qDebug() << "showing seat...\n";
    qDebug() << "player " << player->getId() << ". labelCard1 " << this->labelCard1;
    player->card1.setLabel(this->labelCard1);
    player->card2.setLabel(this->labelCard2);

    qDebug() << "player " << player->getId() << ". labelCard1 " << player->card1.img();
}

