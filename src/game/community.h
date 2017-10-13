#ifndef COMMUNITY_H
#define COMMUNITY_H

#include "card.h"

struct Community {
    Community() = default;
    Community(int small_blind, int big_blind):small_blind(small_blind), big_blind(big_blind){}

    int current_bet = 0;
    int pot = 0;
    int min_bet = 0;
    int max_bet = 0;
    int big_blind = 0;
    int small_blind = 0;

    Card flop1;
    Card flop2;
    Card flop3;
    Card turn;
    Card river;
};

#endif // COMMUNITY_H
