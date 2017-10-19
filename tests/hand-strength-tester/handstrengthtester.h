#ifndef HANDSTRENGTHTESTER_H
#define HANDSTRENGTHTESTER_H

#include <QMainWindow>
#include <vector>
#include "hand.h"

class Player;

namespace Ui {
class HandStrengthTester;
}

class HandStrengthTester : public QMainWindow
{
    Q_OBJECT

public:
    HandStrengthTester(int players, QWidget *parent = 0);

    class Dealer {
      public:
        Dealer();
        QVector<int> deck;

        void findBestHand(Player* p);
    } dealer;

    void showAllCards();
    void test();
    void test_custom(QVector<int> &cards);

    ~HandStrengthTester();

private:
    QVector<Player*> players;
    Hand* hand;
    Ui::HandStrengthTester *ui;
};

#endif // HANDSTRENGTHTESTER_H
