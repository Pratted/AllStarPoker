#ifndef CARD_H
#define CARD_H

#define CARD_WIDTH 44
#define CARD_HEIGHT 63

class Seat;
class QLabel;
class QImage;

class Card
{
friend class Seat;

public:
    Card();
    Card(int id); //:_id(id), _rank(id % 13), _suit(Suit(id / 13)){}
    Card(int id, QLabel* label);

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
    void setCardSheet(QImage* card_sheet);

    static QImage card_sheet2;
private:
    int _id;
    int _rank;
    Suit _suit;

    QLabel* _img = nullptr;
    QImage* card_front = nullptr;
    QImage* card_back = nullptr;
    QImage* card_sheet = nullptr;
};

#endif
