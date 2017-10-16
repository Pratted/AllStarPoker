#ifndef HAND_H
#define HAND_H

#include <QVector>
#include <QMap>
#include <map>
#include <vector>

#include "card.h"
class Player;
class QLabel;



/********************************************************************
 * A hand is a Sequence betting events between the players.
 *
 * Each hand has 4 distinct betting 'rounds'.
 *   pre-flop, flop, turn, river
 *
 * The hand is over when there one non-folded player left or
 * all of the betting rounds have been completed.
 *
 *
 * Note std::vector is used instead of QVector since it supports
 * iterator range constructors.
 *******************************************************************/
class Hand {
public:
    Hand(QVector<Player*> players, Player* lead_better, int big_blind = 0, int small_blind = 0);

    QVector<Player*> current_players;
    QVector<Player*> folded_players;

    // amount each player can win this hand.
    // since a hand may have multiple winners, winnings may not be evenly distributed.
    QMap<Player*, int> player_potential_winnings;

    Player* button;
    Player* small_blind;
    Player* big_blind;
    Player* lead_better;
    Player* prev_lead_better;
    Player* current_player;

    struct Community {
        Community(int small_blind = 0, int big_blind = 0):
            current_bet(0),
            pot(0),
            min_bet(0),
            max_bet(0),
            small_blind(small_blind),
            big_blind(big_blind){}

        int current_bet;
        int pot;
        int min_bet;
        int max_bet;
        int big_blind;
        int small_blind;

        Card flop1;
        Card flop2;
        Card flop3;
        Card turn;
        Card river;
    } community;

    enum State{PRE_FLOP, FLOP, TURN, RIVER, FINISHED} state;

    bool hasSingleWinner(); //1 player left (1 AND ONLY 1 winner)
    bool hasRoundFinished(); //end of flop, turn, etc.

    std::vector<Card> build7CardHand(Card &c1, Card &c2);

    QVector<Player*> getHandWinners(QLabel* label = nullptr);

    void removePlayer(Player* player);
    void save(); //save hand statistics in database.

    enum Type {NONE, HIGH_CARD, PAIR, TWO_PAIR, THREE_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_KIND, STRAIGHT_FLUSH};



    struct ranked_hand {
        ranked_hand(Hand::Type type, std::vector<Card> hand);
        bool operator()(const Hand::ranked_hand& a, const Hand::ranked_hand &b) const;

        Hand::Type type;
        std::vector<Card> hand;
    };

    ranked_hand best5CardHand(Player* player);

    static QString toString(Hand::ranked_hand hand);
    static QString toString(std::vector<Card> hand);
    static Hand::ranked_hand emptyHand();

    //should be private....
    static bool sort_straight(Card &a, Card &b);
    static bool is_ace_low(Card& a);


    static std::vector<Card> removeDuplicateRanks(std::vector<Card> hand);
    static Card getNthHighCard(std::vector<Card> hand, int n);

    ranked_hand straightFlush(std::vector<Card> hand);
    ranked_hand fourKind(std::vector<Card> hand);
    ranked_hand fullHouse(std::vector<Card> hand);
    ranked_hand flush(std::vector<Card> hand);

    ranked_hand straight(std::vector<Card> hand);
    ranked_hand threeKind(std::vector<Card> hand);
    ranked_hand twoPair(std::vector<Card> hand);
    ranked_hand pair(std::vector<Card> hand);
    ranked_hand highCard(std::vector<Card> hand);
private:
    std::map<Hand::ranked_hand, QVector<Player*>, std::greater<Hand::ranked_hand>> ranks;
};

bool operator>(const Card& lhs, const Card& rhs);
bool operator==(const std::vector<Card> &lhs, const std::vector<Card> &rhs);
bool operator>(const std::vector<Card> &lhs, const std::vector<Card> &rhs);
bool operator>(const Hand::ranked_hand &lhs, const Hand::ranked_hand &rhs);
std::ostream& operator<<(std::ostream& out, std::vector<Card> &hand);
std::ostream& operator<<(std::ostream& out, Hand::ranked_hand &hand);



#endif // HAND_H
