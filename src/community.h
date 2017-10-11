#ifndef COMMUNITY_H
#define COMMUNITY_H

struct Community {
    /*
    Card card1;


    */
    Community() = default;
    Community(int small_blind, int big_blind):small_blind(small_blind), big_blind(big_blind){}

    int current_bet = 0;
    int pot = 0;
    int min_bet = 0;
    int max_bet = 0;
    int big_blind = 0;
    int small_blind = 0;
};

#endif
