#ifndef SEAT_H
#define SEAT_H

#include <QPicture>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class CountdownTimer;
class Player;

typedef QString JsonString;

class Seat {
    friend class Player;
public:
    Seat() = default;
    Seat(int id);

    Player* player;

    int id;
    void clear();
    void display();

    bool isTaken = false;
    bool empty(){ return isTaken; }

    QPushButton* buttonSitInSeat;
    QLabel* playerName;
    QLabel* chipCount;
    QLabel* labelCard1;
    QLabel* labelCard2;
    QLabel* placeholder;
    QLabel* blind_chip;

    QLabel* labelTimer;
    CountdownTimer* timer;
    //std::unique_ptr<CountdownTimer> timer;
    //CountdownTimer timer;

    QVector<QLabel*> chipStacks;

    void seat(Player* player);

    static QImage big_blind_img;
    static QImage small_blind_img;
    static QImage dealer_chip_img;
};

#endif // SEAT_H
