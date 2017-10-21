#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>

#include "hand.h"
#include "player.h"

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



Hand::Community::Community(int small_blind, int big_blind):
    current_bet(0),
    pot(0),
    min_bet(0),
    max_bet(0),
    small_blind(small_blind),
    big_blind(big_blind){

}

Hand::ranked_hand::ranked_hand(Hand::Type type, std::vector<Card> hand): type(type), hand(hand){}

bool operator>(const Card& lhs, const Card& rhs){
    return lhs.rank > rhs.rank;
}

/**********************************************************************
operator==(std::vector<Card>, std::vector<Card>)

Returns true if lhs is equivalent to rhs by comparing the ranks of each
card.
**********************************************************************/
bool operator==(const std::vector<Card> &lhs, const std::vector<Card> &rhs){
    if(lhs.size() != rhs.size()) return false;

    for(int i = 0; i < lhs.size(); i++){
        if(lhs[i].rank != rhs[i].rank) return false;
    }

    return true;
}


/**********************************************************************
operator>(std::vector<Card>, std::vector<Card>)

Compares the i'th indices of both hands. Returns turn if lhs card rank
if higher than rhs card rank.
**********************************************************************/
bool operator>(const std::vector<Card> &a, const std::vector<Card> &b){
    for(int i = 0; i < std::min(a.size(), b.size()); i++){
        if(a[i].rank != b[i].rank){
            return a[i].rank > b[i].rank;
        }
    }
    return false;
}

/**********************************************************************
operator>(Hand::ranked_hand &lhs, Hand::ranked_hand &rhs)

Returns true if lhs is 'stronger' hand than rhs.
**********************************************************************/
bool operator>(const Hand::ranked_hand &lhs, const Hand::ranked_hand &rhs){
    if(lhs.type == rhs.type){ //same hand type.
        return lhs.hand > rhs.hand;
    }
    else{
        return lhs.type > rhs.type;
    }
}


/**********************************************************************
operator==(Hand::ranked_hand &lhs, Hand::Type &rhs)

Returns true if two hands are of the same Hand::Type.

2 2 and 4 4 are different, both they are both hands of type Hand::Pair
**********************************************************************/
bool operator==(const Hand::ranked_hand &lhs , const Hand::Type &rhs){
    return lhs.type == rhs;
}

std::ostream& operator<<(std::ostream& out, Hand::ranked_hand &hand){
    if(hand.type == Hand::STRAIGHT_FLUSH) out << "Straight flush\n";
    else if(hand.type == Hand::FOUR_KIND) out << "Four kind\n";
    else if(hand.type == Hand::FULL_HOUSE) out << "Full house\n";
    else if(hand.type == Hand::FLUSH) out << "Flush\n";
    else if(hand.type == Hand::STRAIGHT) out << "Straight\n";
    else if(hand.type == Hand::THREE_KIND) out << "Three kind\n";
    else if(hand.type == Hand::TWO_PAIR) out << "Two pair\n";
    else if(hand.type == Hand::PAIR) out << "Pair\n";
    else if(hand.type == Hand::HIGH_CARD) out << "High Cards\n";
    else out << "Could not validate hand. FUCK.\n";
}

/**********************************************************************
Hand::toString(Hand::ranked_hand)

Convert Hand::Type to string using Hand::ranked_hand.
**********************************************************************/
QString Hand::toString(Hand::ranked_hand hand){
    if(hand.type == Hand::STRAIGHT_FLUSH) return "Straight flush";
    else if(hand.type == Hand::FOUR_KIND) return "Four kind";
    else if(hand.type == Hand::FULL_HOUSE) return "Full house";
    else if(hand.type == Hand::FLUSH) return "Flush";
    else if(hand.type == Hand::STRAIGHT) return "Straight";
    else if(hand.type == Hand::THREE_KIND) return "Three kind";
    else if(hand.type == Hand::TWO_PAIR) return "Two pair";
    else if(hand.type == Hand::PAIR) return "Pair";
    else if(hand.type == Hand::HIGH_CARD) return "High Cards";
    else return "Unknown";
}

/**********************************************************************
Hand::toString(std::vector<Card>)

Output the n-card hand as space delimited ranks.
**********************************************************************/
QString Hand::toString(std::vector<Card> hand){
    QString ans;
    for(auto &c: hand){
        ans += QString::number(c.rank) + " ";
    }
    return ans;
}

/**********************************************************************
Hand::emptyHand

Return Hand::ranked_hand of type Hand::None to indicate the target
hand wasn't found. (i.e searching for a full house, but none found)
**********************************************************************/
Hand::ranked_hand Hand::emptyHand(){
    return ranked_hand(NONE, std::vector<Card> ());
}

/**********************************************************************
Hand::build7CardHand

Helper function for Hand::best5CardHand.

Builds a 7 card hand by copying the community and appending the players
cards.
**********************************************************************/
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


/**********************************************************************
Hand::best5CardHand

Constructs the best possible Hand::ranked_hand for a player.

Uses a greedy approach by checking from strongest hands first.
Returns the first match.
**********************************************************************/
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

/**********************************************************************
Hand::getNthHighCard

Sorts hand in descending order and returns the n'th index from the
beginning. HIGH ACES should already be in hand.
**********************************************************************/
Card Hand::getNthHighCard(std::vector<Card> hand, int n){
    std::sort(hand.begin(), hand.end(), sort_rank_desc);
    return hand[n];
}

/**********************************************************************
Hand::sort_rank_desc

Predicate for std::sort(begin,end,predicate)
sort cards in descending order of rank.
**********************************************************************/
bool Hand::sort_rank_desc(Card &a, Card &b){
   return a.rank > b.rank;
}


/**********************************************************************
Hand::is_ace_low

Predicate for std::replace_if(begin,end,predicate,replacement)
**********************************************************************/
bool Hand::is_ace_low(Card& a){
    return a.rank == ACE_LOW;
}

QVector<Player*> Hand::getHandWinners(){
    ranks.clear();
    for(auto &player: current_players){
        auto hand = best5CardHand(player);
        ranks[hand].push_back(player);
    }

    auto winning_hand = ranks.begin()->first;
    auto winning_players = ranks[winning_hand];

    return winning_players;
}


/**********************************************************************
Hand::straightFlush

Uses a map to count the number of occurances of each rank, but stores
the cards as the value in key-value pair to preserve the rank. If 5 or
more cards are in a key-value pair, the value (std::vector<Card>), is
passed to Hand::straight to check for a straight. If the call returns
a Hand::Straight, then there is straight flush since those cards also
made up a flush in the intial analysis.

**Note we can't call Hand::flush here because it returns the 5 highest
ranks that make up a flush. The 5 highest ranks of a flush do not
nessecarily make up the straight flush if there is one.
**********************************************************************/
Hand::ranked_hand Hand::straightFlush(std::vector<Card> hand){
    //group cards by suit.
    std::map<int, std::vector<Card>> counts;

    for(auto &card: hand){
        counts[card.suit].push_back(card);
    }

    for(auto &p: counts){
        if(p.second.size() >= 5){ //flush
            //check if flush cards are also a straight.
            ranked_hand temp = straight(p.second);

            if(temp.type == STRAIGHT){
                temp.type = STRAIGHT_FLUSH;
                return temp;
            }
        }
    }

    return emptyHand();
}


/**********************************************************************
Hand::fourKind

Uses a map to count the number of occurances of each rank. If 4
occurances are found, those 4 cards + next highest card is returned
in Hand::ranked_hand.
**********************************************************************/
 Hand::ranked_hand Hand::fourKind(std::vector<Card> hand){
    std::map<int, int> counts;
    std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));

    for(auto &card: hand){
        counts[card.rank]++;
    }

    for(auto &p: counts){
        if(p.second == 4){
            std::vector<Card> ans;

            //remove the 4 kind of hand
            hand.erase(std::remove_if(hand.begin(), hand.end(),[&](const Card& c){
                return c.rank == p.first;
            }), hand.end());

            ans.insert(ans.begin(), 4, Card(p.first));

            //search for the remaining high card.
            ans.push_back(getNthHighCard(hand, 0));
            return ranked_hand(FOUR_KIND, ans);
        }
    }

    return emptyHand();
}

/**********************************************************************
Hand::fullHouse

Calls Hand::threeKind to get the high 3kind if there is one. If there
is a 3kind, those 3 cards are removed and the leftover 4 card hand is
passed to Hand::pair to get the highest remaining pair. If both calls
return 3 and 2 cards, combine them and return as Hand::ranked_hand.
**********************************************************************/
Hand::ranked_hand Hand::fullHouse(std::vector<Card> hand){
     std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));

     std::vector<Card> solution;
     ranked_hand trips = threeKind(hand);
     //include the 3 kind in this solution.
     if(trips.type == THREE_KIND){
         solution.insert(solution.begin(), trips.hand.begin(), trips.hand.begin() + 3);

         //eliminate those 3 cards to make 4 card hand.
         hand.erase(std::remove_if(hand.begin(), hand.end(),[&](const Card& c){
             return c.rank == trips.hand.front().rank;
         }), hand.end());
     }

     //check if the 4 card hand has a pair.
     ranked_hand p = pair(hand);
     if(p.type == PAIR){
         solution.insert(solution.end(), p.hand.begin(), p.hand.begin() + 2);
     }

     if(solution.size() == 5) return ranked_hand(FULL_HOUSE, solution);
     return emptyHand();
 }


/**********************************************************************
Hand::flush

Maps each suit to the number of occurances of said suit. When there
are 5 or more cards of same suit, those cards are placed in a vector
and then sorted into descending order since. The first 5 cards are used
to return a Hand::ranked_hand.
**********************************************************************/
Hand::ranked_hand Hand::flush(std::vector<Card> hand){
     std::map<int, int, std::greater<int>> counts;

     for(auto &card: hand){
         counts[card.suit]++;
     }

     for(auto &p: counts){
         if(p.second >= 5){
             std::vector<Card> solution;

             //place of cards of same suit into solution vector.
             std::copy_if(hand.begin(), hand.end(), std::back_inserter(solution), [&](const Card& c){
                return c.suit == p.first;
             });

             std::sort(solution.begin(), solution.end(), sort_rank_desc);

             //insert a high ace in beginning if there's an ace.
             if(solution.back().rank == ACE_LOW){
                 solution.insert(solution.begin(), Card(ACE_HIGH));
             }

             solution.resize(5);
             return ranked_hand(FLUSH, solution);
         }
     }

     return emptyHand();
 }

/**********************************************************************
Hand::straight


Stores all 3kinds in a map ordered by rank of the 3kind. Uses the
highest 3kind the map along with the additional 2 high cards to
construct Hand::ranked_hand.
**********************************************************************/
Hand::ranked_hand Hand::straight(std::vector<Card> hand){
    std::sort(hand.begin(), hand.end(), sort_rank_desc); //sort descending

    //iterator one past all unique pairs.
    auto it = std::unique(hand.begin(), hand.end(), [](const Card &a, const Card &b){
        return a.rank == b.rank;
    });

    //remove all duplicates to make the hand contain unique ranks.
    hand.erase(it, hand.end());

    //insert a high ace to check for high end straight.
    if(hand.back().rank == ACE_LOW){
        hand.insert(hand.begin(),Card(ACE_HIGH));
        hand[0].rank = ACE_HIGH_RANK;
    }

    /************************************************************
    Use sliding window to check for straight.

                9 8 7 6 5 3 1
                ^_______^

    If two cards 5 cards apart have a difference in rank of 4,
    then there's a straight. (remember there are no duplicates)
    *************************************************************/
    for(int i = 0, j = 4; j < hand.size(); i++, j++){
        if(hand[i].rank - hand[j].rank == 4){
            return ranked_hand(STRAIGHT, std::vector<Card> (hand.begin() + i, hand.begin() + j + 1));
        }
    }

    return emptyHand();
}

/**********************************************************************
Hand::threeKind

Stores all 3kinds in a map ordered by rank of the 3kind. Uses the
highest 3kind the map along with the additional 2 high cards to
construct Hand::ranked_hand.
**********************************************************************/
Hand::ranked_hand Hand::threeKind(std::vector<Card> hand){
    //Store in descending order. If there are 2, 3kinds, the higher 3kind will
    //been seen first when iterating through the map.
    std::map<int, int, std::greater<int>> counts;
    std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));

    for(auto &card: hand){
        counts[card.rank]++;
    }

    for(auto &p: counts){
        if(p.second >= 3){
            std::vector<Card> ans;

            std::copy_if(hand.begin(), hand.end(), std::back_inserter(ans), [&](const Card& c){
                return c.rank == p.first;
            });

            //remove the 3kind from hand
            hand.erase(std::remove_if(hand.begin(), hand.end(),[&](const Card& c){
                return c.rank == p.first;
            }),hand.end());

            //search for the 2 remaining high cards.
            ans.push_back(getNthHighCard(hand, 0));
            ans.push_back(getNthHighCard(hand, 1));
            return ranked_hand(THREE_KIND, ans);
        }
    }

    return emptyHand();
}


/**********************************************************************
Hand::twoPair

Stores all pairs in hand in map ordered by rank of pair. Uses the
two highest pairs (first two entries in map) and high card to
construct Hand::ranked_hand.
**********************************************************************/
Hand::ranked_hand Hand::twoPair(std::vector<Card> hand){
    std::map<int, int, std::greater<int>> counts;
    std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));

    for(auto &card: hand){
        counts[card.rank]++;
    }

    std::vector<Card> ans;

    for(auto &p: counts){
        if(p.second >= 2){
            //remove the pair from hand

            //copy pair to ans
            std::copy_if(hand.begin(), hand.end(), std::back_inserter(ans), [&](const Card& c){
                return c.rank == p.first;
            });

            //remove from original hand.
            hand.erase(std::remove_if(hand.begin(), hand.end(),[&](const Card& c){
                return c.rank == p.first;
            }), hand.end());
        }

        //ans will have size 4 when 2 pairs have been found. now get the high card.
        if(ans.size() == 4){
            ans.push_back(getNthHighCard(hand, 0));
            return ranked_hand(TWO_PAIR, ans);
        }
    }

    return emptyHand();
}

/**********************************************************************
Hand::pair

Searches for the first and only one pair in hand. Appends the 3 highest
remaining cards to Hand::ranked_hand.
**********************************************************************/
Hand::ranked_hand Hand::pair(std::vector<Card> hand){
    std::map<int, int, std::greater<int>> counts;
    std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));

    for(auto &card: hand){
        counts[card.rank]++;
    }

    std::vector<Card> ans;

    for(auto &p: counts){
        if(p.second >= 2){
            //remove the pair from hand
            std::copy_if(hand.begin(), hand.end(), std::back_inserter(ans), [&](const Card& c){
                return c.rank == p.first;
            });

            hand.erase(std::remove_if(hand.begin(), hand.end(),[&](const Card& c){
                return c.rank == p.first;
            }), hand.end());

            ans.push_back(getNthHighCard(hand, 0));
            ans.push_back(getNthHighCard(hand, 1));
            ans.push_back(getNthHighCard(hand, 2));
            return ranked_hand(PAIR, ans);
        }
    }

    return emptyHand();
}

/**********************************************************************
Hand::highCard

Sorts the 7 card hand in descender orders. Returns a Hand::ranked_hand
first 5 of highest cards.
**********************************************************************/
Hand::ranked_hand Hand::highCard(std::vector<Card> hand){
    std::replace_if(hand.begin(), hand.end(), is_ace_low, Card(ACE_HIGH));
    std::sort(hand.begin(), hand.end(), sort_rank_desc);
    return ranked_hand(HIGH_CARD, std::vector<Card> (hand.begin(), hand.begin() + 5));
}


