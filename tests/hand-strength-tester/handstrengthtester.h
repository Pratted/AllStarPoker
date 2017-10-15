#ifndef HANDSTRENGTHTESTER_H
#define HANDSTRENGTHTESTER_H

#include <QMainWindow>

class Player;

namespace Ui {
class HandStrengthTester;
}

class HandStrengthTester : public QMainWindow
{
    Q_OBJECT

public:
    explicit HandStrengthTester(int players, QWidget *parent = 0);

    class Dealer {
      public:
        Dealer();
        QVector<int> deck;

        void findBestHand(Player* p);
    } dealer;

    void test();
    QVector<Player*> players;

    ~HandStrengthTester();

private:
    Ui::HandStrengthTester *ui;
};

#endif // HANDSTRENGTHTESTER_H
