#include "hand.h"
#include "player.h"
#include <algorithm>
#include <unordered_map>
#include <map>

bool operator>(const Card& lhs, const Card& rhs){
    return lhs.rank() > rhs.rank();
}

bool operator==(const std::vector<Card> &lhs, const std::vector<Card> &rhs){
    if(lhs.size() != rhs.size()) return false;

    for(int i = 0; i < lhs.size(); i++){
        if(lhs[i].rank() != rhs[i].rank()) return false;
    }

    return true;
}

bool operator>(const std::vector<Card> &a, const std::vector<Card> &b){
    for(int i = 0; i < std::min(a.size(), b.size()); i++){
        if(a[i].rank() != b[i].rank()){
            return a[i].rank() > b[i].rank();
        }
    }
    return false;
}


bool operator>(const Hand::ranked_hand &a, const Hand::ranked_hand &b){
    if(a.type == b.type){ //same hand type.
        return a.hand > b.hand;
    }
    else{
        return a.hand > b.hand;
    }
}

bool operator==(const Hand::ranked_hand &lhs , const Hand::Type &rhs){
    return lhs.type == rhs;
}

std::ostream& operator<<(std::ostream& out, std::vector<Card> &hand){
    out << "ids : ";
    for(auto &c: hand){
        out << c.id() << "\t";
    }
    out << "\nrank: ";
    for(auto &c: hand){
        out << c.rank() << "\t";
    }
    out << "\nsuit: ";
    for(auto &c: hand){
        out << c.suit() << "\t";
    }
    out << "\n";

    return out;
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



std::vector<Card> Hand::removeDuplicateRanks(std::vector<Card> hand){
    auto it = std::unique(hand.begin(), hand.end(), [](const Card &a, const Card &b){
        return a.rank() == b.rank();
    });

    hand.erase(it, hand.end());
    return hand;
}


Card Hand::getNthHighCard(std::vector<Card> hand, int n){
    std::sort(hand.begin(), hand.end(), sort_straight);
    return hand[n];
}


//Sort descending order. With aces toward beginning.
bool Hand::sort_straight(Card &a, Card &b){
    if(a.rank() == ACE_LOW) return true;
    if(b.rank() == ACE_LOW) return false;
   return a.rank() > b.rank();
}

bool Hand::is_ace_low(Card& a){
    return a.rank() == ACE_LOW;
}





Hand::ranked_hand Hand::straightFlush(std::vector<Card> hand){
    //std::sort(hand.begin(), hand.end(), sort_flush);
    return emptyHand();
}


// Finds a four of a kind.
//
// The std::vector is ordered with the 4 kind, followed by the high card.
//
// i.e
// {FOUR_KIND, {9,9,9,9,6}};
 Hand::ranked_hand Hand::fourKind(std::vector<Card> hand){
    std::map<int, int> counts;
    std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));

    for(auto &card: hand){
        counts[card.rank()]++;
    }

    for(auto &p: counts){
        if(p.second == 4){
            std::vector<Card> ans;

            //remove the 4 kind of hand
            hand.erase(hand.begin(), std::remove_if(hand.begin(), hand.end(),[&](const Card& c){
                return c.rank() == p.first;
            }));

            std::fill_n(ans.begin(), 4, Card(p.first));

            //search for the remaining high card.
            ans.push_back(getNthHighCard(hand, 0));
            return ranked_hand(FOUR_KIND, ans);
        }
    }

    return emptyHand();
}


 Hand::ranked_hand Hand::fullHouse(std::vector<Card> hand){
     std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));

     std::vector<Card> solution;
     ranked_hand trips = threeKind(hand);

     //include the 3 kind in this solution.
     if(trips.type == THREE_KIND){
         solution.insert(solution.begin(), trips.hand.begin(), trips.hand.begin() + 3);

         //eliminate those 3 cards to make 4 card hand.
         hand = std::vector<Card> (trips.hand.begin() + 3, trips.hand.end());
     }

     ranked_hand p = pair(hand);
     if(p.type == PAIR){
         solution.insert(solution.begin(), p.hand.begin(), p.hand.begin() + 2);
     }

     if(solution.size() == 5){
         ranked_hand(FULL_HOUSE, solution);
     }

     return emptyHand();
 }



Hand::ranked_hand Hand::flush(std::vector<Card> hand){
     std::map<int, int, std::greater<int>> counts;

     for(auto &card: hand){
         counts[card.rank()]++;
     }

     for(auto &p: counts){
         if(p.second >= 5){
             std::vector<Card> solution;

             //place of cards of same suit into solution vector.
             std::copy_if(hand.begin(), hand.end(), solution.begin(), [&](const Card& c){
                return c.rank() == p.first;
             });

             std::sort(solution.begin(), solution.end(), sort_straight);

             if(solution.front().rank() == ACE_LOW){
                 solution[0].setRank(ACE_HIGH_RANK);
             }

             solution.resize(5);
             return ranked_hand(FLUSH, solution);
         }
     }

     return emptyHand();
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
            return ranked_hand(STRAIGHT, std::vector<Card> (hand.begin() + i, hand.begin() + j + 1));
        }
    }

    return ranked_hand(NONE, std::vector<Card>());
}


Hand::ranked_hand Hand::threeKind(std::vector<Card> hand){
    //Store in descending order. If there are 2, 3kinds, the higher 3kind will
    //been seen first when iterating through the map.
    std::map<int, int, std::greater<int>> counts;
    std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));

    for(auto &card: hand){
        counts[card.rank()]++;
    }

    for(auto &p: counts){
        if(p.second >= 3){
            std::vector<Card> ans;

            //remove the 3kind from hand
            hand.erase(hand.begin(), std::remove_if(hand.begin(), hand.end(),[&](const Card& c){
                return c.rank() == p.first;
            }));

            std::fill_n(ans.begin(), 3, Card(p.first));

            //search for the 2 remaining high cards.
            ans.push_back(getNthHighCard(hand, 0));
            ans.push_back(getNthHighCard(hand, 1));
            return ranked_hand(THREE_KIND, ans);
        }
    }

    return emptyHand();
}
Hand::ranked_hand Hand::twoPair(std::vector<Card> hand){
    std::map<int, int, std::greater<int>> counts;
    std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));

    for(auto &card: hand){
        counts[card.rank()]++;
    }

    std::vector<Card> ans;

    for(auto &p: counts){
        if(p.second >= 2){
            //remove the pair from hand
            hand.erase(hand.begin(), std::remove_if(hand.begin(), hand.end(),[&](const Card& c){
                return c.rank() == p.first;
            }));

            std::fill_n(ans.begin(), 2, Card(p.first));
        }

        //ans will have size 4 when 2 pairs have been found. now get the high card.
        if(ans.size() == 4){
            ans.push_back(getNthHighCard(hand, 0));
            return ranked_hand(TWO_PAIR, ans);
        }
    }

    return emptyHand();
}
Hand::ranked_hand Hand::pair(std::vector<Card> hand){
    std::map<int, int, std::greater<int>> counts;
    std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));

    for(auto &card: hand){
        counts[card.rank()]++;
    }

    std::vector<Card> ans;

    for(auto &p: counts){
        if(p.second >= 2){
            //remove the pair from hand
            hand.erase(hand.begin(), std::remove_if(hand.begin(), hand.end(),[&](const Card& c){
                return c.rank() == p.first;
            }));

            std::fill_n(ans.begin(), 2, Card(p.second));
            ans.push_back(getNthHighCard(hand, 0));
            ans.push_back(getNthHighCard(hand, 1));
            ans.push_back(getNthHighCard(hand, 2));
            return ranked_hand(PAIR, ans);
        }
    }

    return emptyHand();
}
Hand::ranked_hand Hand::highCard(std::vector<Card> hand){
    std::sort(hand.begin(), hand.end(), sort_straight);
    return ranked_hand(HIGH_CARD, std::vector<Card> (hand.begin(), hand.begin() + 5));
}


