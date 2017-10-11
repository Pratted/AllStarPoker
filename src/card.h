#ifndef CARD_H
#define CARD_H

#define CARD_WIDTH 44
#define CARD_HEIGHT 63

class Seat;

class Card
{
friend class Seat;

public:
    Card() = default;
    Card(int id):_id(id), _rank(id % 13), _suit(Suit(id / 13)){}
    enum Suit{ HEART=0, DIAMOND=1, CLUB=2, SPADE=3 };

    int id() const{return _id;}
    int rank() const{return _rank;}
    Suit suit() const {return _suit; }

private:
    int _id;
    int _rank;
    Suit _suit;

    //Qlabel* label;
};

#endif
