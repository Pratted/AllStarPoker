#include "handstrengthtester.h"
#include <QApplication>
#include <random>
#include <QVector>

#include "card.h"





int main(int argc, char *argv[])
{
    int players = 8;

    if(argc > 1){
        players = argv[1][0] - '0';
    }

    QApplication a(argc, argv);
    HandStrengthTester hst(players);
    hst.show();

    hst.test();

    return a.exec();
}
