#ifndef HAND_H
#define HAND_H

#include <QVector>
#include <QMap>

#include "card.h"
class Player;


/********************************************************************
 * A hand is a Sequence betting events between the players.
 *
 * Each hand has 4 distinct betting 'rounds'.
 *   pre-flop, flop, turn, river
 *
 * The hand is over when there one non-folded player left or
 * all of the betting rounds have been completed.
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

    void save(); //save hand statistics in database.
};

#endif // HAND_H
