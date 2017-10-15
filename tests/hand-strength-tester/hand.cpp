#include "hand.h"
#include "player.h"
#include <algorithm>
#include <unordered_map>

bool operator==(std::vector<Card> &a, std::vector<Card> &b){
    for(int i = 0; i < std::min(a.size(), b.size()); i++){
        if(a[i].rank() != b[i].rank()) return false;
    }

    return true;
}

bool operator>(std::vector<Card> &a, std::vector<Card> &b){
    for(int i = 0; i < std::min(a.size(), b.size()); i++){
        if(a[i].rank() != b[i].rank()){
            return a[i].rank() > b[i].rank();
        }
    }
    return false;
}


bool operator>(Hand::ranked_hand &a, Hand::ranked_hand &b){
    if(a.first == b.first){ //same hand type.
        return a.second > b.second;
    }
    else{
        return a.second > b.second;
    }
}

bool operator==(Hand::ranked_hand lhs , Hand::Type rhs){
    return lhs.first == rhs;
}

Hand::ranked_hand Hand::emptyHand(){
    return ranked_hand(NONE, std::vector<Card> ());
}


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

std::vector<Card> Hand::build7CardHand(Card &c1, Card &c2){
    std::vector<Card> hand;

    hand.push_back(community.flop1);
    hand.push_back(community.flop2);
    hand.push_back(community.flop3);
    hand.push_back(community.turn);
    hand.push_back(community.river);
    hand.push_back(c1);
    hand.push_back(c2);

    return hand;
}

Hand::ranked_hand Hand::best5CardHand(Player* player){
    auto hand = build7CardHand(player->card1, player->card2);

    if(straightFlush(hand) == STRAIGHT_FLUSH) return straightFlush(hand);
    if(fourKind(hand) == FOUR_KIND) return fourKind(hand);
    if(fullHouse(hand) == FULL_HOUSE) return fullHouse(hand);
    if(flush(hand) == FLUSH) return flush(hand);
    if(straight(hand) == STRAIGHT) return straight(hand);
    if(threeKind(hand) == THREE_KIND) return threeKind(hand);
    if(twoPair(hand) == TWO_PAIR) return twoPair(hand);
    if(pair(hand) == PAIR) return pair(hand);

    return highCard(hand);
}



//sort by suit, then by rank in descending order.
bool Hand::sort_flush(Card &a, Card &b){
    if(a.suit() == b.suit()){
        if(a.rank() == ACE_LOW) return true;
        if(b.rank() == ACE_LOW) return false;
        else return a.rank() > b.rank();
    }
    else{
        if(a.rank() == ACE_LOW) return true;
        if(b.rank() == ACE_LOW) return false;
        else return a.rank() > b.rank();
    }
}

//Sort descending order. With aces toward beginning.
bool Hand::sort_straight(Card &a, Card &b){
    if(a.rank() == ACE_LOW) return true;
    if(b.rank() == ACE_LOW) return false;
   return a.rank() > b.rank();
}

Hand::ranked_hand Hand::straight(std::vector<Card> hand){
    hand = removeDuplicateRanks(hand);

    std::sort(hand.begin(), hand.end(), sort_straight);

    //append a high ace to check for high end straight.
    if(hand.back().rank() == ACE_LOW){
        hand.push_back(Card(ACE_LOW));
        hand[0] = Card(ACE_HIGH);
    }

    //if two cards 5 cards apart have a difference of 4, then
    //there must be a straight since (remember dups are removed).
    for(int i = 0, j = 4; j < hand.size(); i++, j++){
        if(hand[i].rank() - hand[j].rank() == 4){
            return ranked_hand(STRAIGHT, std::vector<Card> (hand.begin() + i, hand.begin() + j));
        }
    }

    return ranked_hand(NONE, std::vector<Card>());
}

std::vector<Card> Hand::removeDuplicateRanks(std::vector<Card> hand){
    auto it = std::unique(hand.begin(), hand.end(), [](const Card &a, const Card &b){
        return a.rank() == b.rank();
    });

    hand.erase(it, hand.end());
    return hand;
}


//get high card in the hand and remove it.
Card Hand::getHighCard(std::vector<Card> &hand){
    Card high_card = hand.front();

    auto runner = hand.begin() + 1;
    auto trailer = hand.begin();
    auto to_erase = trailer;

    while(runner != hand.end()){
        if(runner->rank() == ACE_LOW){
            high_card = *runner;
            hand.erase(runner);
            return high_card;
        }
        else if(runner->rank() > trailer->rank()){
            high_card = *runner;
            to_erase = runner;
        }
    }

    hand.erase(to_erase);
    return high_card;
}



Hand::ranked_hand Hand::straightFlush(std::vector<Card> hand){
    std::sort(hand.begin(), hand.end(), sort_flush);
    return emptyHand();
}

Hand::ranked_hand Hand::fourKind(std::vector<Card> hand){
    std::unordered_map<int, int> counts;
    for(auto &card: hand){
        counts[card.rank()]++;
    }

    for(auto &p: counts){
        if(p.second == 4){
            if(p.first == ACE_LOW){

            }

        }
    }

    return emptyHand();
}


Hand::ranked_hand Hand::fullHouse(std::vector<Card> hand){return emptyHand();}
Hand::ranked_hand Hand::flush(std::vector<Card> hand){return emptyHand();}
Hand::ranked_hand Hand::threeKind(std::vector<Card> hand){return emptyHand();}
Hand::ranked_hand Hand::twoPair(std::vector<Card> hand){return emptyHand();}
Hand::ranked_hand Hand::pair(std::vector<Card> hand){return emptyHand();}
Hand::ranked_hand Hand::highCard(std::vector<Card> hand){return emptyHand();}

