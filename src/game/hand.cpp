#include "hand.h"

Hand::Hand(QVector<Player*> players, Player* lead_better, int big_blind, int small_blind):
    current_players(players),
    lead_better(lead_better),
    community(small_blind, big_blind)
{
    prev_lead_better = nullptr;
}



bool Hand::hasSingleWinner(){
    return current_players.size() == 1;
}

bool Hand::hasRoundFinished(){
    return prev_lead_better == lead_better;
}
