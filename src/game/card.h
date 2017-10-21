#ifndef CARD_H
#define CARD_H

#define ACE_LOW 0
#define ACE_HIGH 99 // used to construct a high ace when suit is negligable.
#define ACE_HIGH_RANK 13 //used to change rank to high ace while perserving suit.

struct Card
{
public:
    Card():id(0),rank(0),suit(Suit(0)){}
    Card(int id):id(id), rank(id % 13), suit(Suit(id / 13)){}

    enum Suit{ HEART=0, DIAMOND=1, CLUB=2, SPADE=3 };

    int id;
    int rank;
    Suit suit;
};

#endif
