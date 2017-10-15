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

//same person is given the option to bet twice.
bool Hand::hasRoundFinished(){
    return prev_lead_better == lead_better;
}

void Hand::removePlayer(Player *player){
    auto it = std::find_if(current_players.begin(), current_players.end(), [player](const Player* p){
        return p == player;
    });

    current_players.erase(it);
    folded_players.push_back(player);

    //remove from winnings. no longer eligable.
    player_potential_winnings.remove(player);
}
