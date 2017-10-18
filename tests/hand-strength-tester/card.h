#ifndef CARD_H
#define CARD_H

#define CARD_WIDTH 44
#define CARD_HEIGHT 63
#define ACE_LOW 0

#define ACE_HIGH 99 // used to construct a high ace when suit is negligable.
#define ACE_HIGH_RANK 13 //used to change rank to high ace while perserving suit.

class QLabel;
class QImage;

class Card
{

public:
    Card();
    Card(int id); //:_id(id), _rank(id % 13), _suit(Suit(id / 13)){}
    Card(int id, QLabel* label);

    Card(const Card &rhs);
    Card(Card &&rhs);

    Card& operator=(const Card &rhs);
    Card& operator=(Card &&rhs);

    ~Card();
    enum Suit{ HEART=0, DIAMOND=1, CLUB=2, SPADE=3 };

    int id() const{return _id;}
    int rank() const{return _rank;}
    Suit suit() const {return _suit; }
    QLabel* img() const {return _img; }

    void showFront();
    void showBack();

    void show();
    void hide();

    void setId(int id);
    void setLabel(QLabel* label);
    void setRank(int rank);
    void setSuit(Suit suit);

    static QImage card_sheet;
private:
    int _id;
    int _rank;
    Suit _suit;

    QLabel* _img = nullptr;
    QImage* card_front = nullptr;
    QImage* card_back = nullptr;
};

#endif
