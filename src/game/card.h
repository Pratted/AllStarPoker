#ifndef CARD_H
#define CARD_H

#define CARD_WIDTH 44
#define CARD_HEIGHT 63

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
