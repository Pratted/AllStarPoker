#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"

class QLabel;
struct Player {
    Player(int id = 0):id(id){}

    QLabel* label;
    int id;
    Card card1;
    Card card2;
};

#endif // PLAYER_H
