#include "handstrengthtester.h"
#include <QApplication>
#include <random>
#include <QVector>
#include <iostream>
#include <fstream>
#include <QDebug>

#include "card.h"


QVector<QVector<int>> load_test_cases(std::string filename){
    std::ifstream infile(filename);
    QVector<QVector<int>> ans(1);

    if(!infile.is_open()){
        qDebug() << "Failed to open " << QString::fromStdString(filename);
        exit(1);
    }

    int card_id;
    int cards_read = 0;
    while(infile >> card_id){
        if(cards_read % 21 == 0){
            ans.push_back(QVector<int> ());
        }

        ans[cards_read / 21].push_back(card_id);
        cards_read++;
    }

    //not enough cards.
    if(ans.back().size() < 21){
        ans.pop_back();
    }

    return ans;
}



int main(int argc, char *argv[])
{
    int players = 8;

    std::string test_file;
    bool display_gui = true;

    QVector<QVector<int>> test_cases;

    qDebug() << "Args: " << argc;

    //usage
    //$ hand-str-test --no-gui tests.txt
    //$ hand-str-test --no-gui
    //$ hand-str-test tests.txt
    if(argc > 1){
        for(int i = 1; i < argc; i++){
            qDebug() << argv[i];
        }

        if(argv[1] == "--no-gui")
            display_gui = false;
        if(argc > 2)
            test_cases = load_test_cases(argv[2]);
        else
            test_cases = load_test_cases(argv[1]);
    }

    if(!test_cases.isEmpty())
        qDebug() << "Cards: " << test_cases[0].size();

    QApplication a(argc, argv);
    HandStrengthTester hst(players);

    if(!test_cases.isEmpty()){
        for(auto &cas: test_cases){
            //hst.test(cas);
        }
    }
    else{
        //hst.test(QVector<int> ());
    }

    hst.test();
    //if(!display_gui)
    //    hst.hide();


    return a.exec();
}
