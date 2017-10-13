#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include "game.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
    if(argc < 9){
        std::cout << "Usage: <name> <id> <size> <chip count> <small blind> <big blind> <timer> <port>\n";
        return 1;
    }

    QString name = argv[1];
    QString id = argv[2];
    QString size = argv[3];
    QString chip_count = argv[4];
    QString small_blind = argv[5];
    QString big_blind = argv[6];
    QString timer = argv[7];
    QString port = argv[8];
    */
    QString name = "eric2";
    QString id = "1";
    QString size = "2";
    QString chip_count = "50000";
    QString small_blind = "0";
    QString big_blind = "0";
    QString timer = "30";
    QString port = "45454";

    printf("Starting game...\n");
    printf("%-20s%20s\n", "Name:", name.toStdString().c_str());
    printf("%-20s%20d\n", "Id:", id.toInt());
    printf("%-20s%20d\n", "Capacity:", size.toInt());
    printf("%-20s%20d\n", "Chip Start Amount:", chip_count.toInt());
    printf("%-20s%20d\n", "Small Blind:", small_blind.toInt());
    printf("%-20s%20d\n", "Big Blind:", big_blind.toInt());
    printf("%-20s%20d\n", "Timer Length:", timer.toInt());
    printf("%-20s%20d\n", "Port:", port.toInt());

    Game game(name, id.toInt(),size.toInt(),chip_count.toInt(),small_blind.toInt(),big_blind.toInt(),timer.toInt(), port.toInt());

    if(!game.start()){
        std::cout << "Failed to start game.\n";
        return 1;
    }

    return a.exec();
}
