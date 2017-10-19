#include <QApplication>
#include <QVector>
#include <QDebug>
#include <random>
#include <iostream>
#include <fstream>

#include "handstrengthtester.h"
#include "card.h"

/**********************************************************************
QVector<QVector<int>> load_test_cases(std::string filename)

This function loads test cases into a vector containing a vector of 21
cards. The 21-card vectors are passed to HandStrengthTest::test_custom
and used as 21-card deck, instead of creating a 52 card deck and
shuffling it like HandStrengthTest::test. 21 Cards are used because
there are 5 community cards + 16 player cards (8 players * 2 card/each).
Each case should contain unique card ids in range [0,51].

The first five cards in the file will go the community.
The following 16 will go to players 7 thru 0 in that order.

Sample file format: cases.txt

14 2 7 45 23        <- community
3 6                 <- player 7
41 46
29 39
24 0
13 26
12 25
37 19
50 40               <- player 0

The deck is dealt from the back, it functions like a stack.
Therefore, 14 in the community will be the river, not the first flop
card.
**********************************************************************/
QVector<QVector<int>> load_test_cases(std::string filename){
    const int MAX_CARDS = 21;
    std::ifstream infile(filename);
    QVector<QVector<int>> ans(1);

    if(!infile.is_open()){
       std::cerr << "Failed to open " << filename << std::endl;
       exit(1);
    }

    int card_id;
    int cards_read = 0;
    while(infile >> card_id){
        if(cards_read % MAX_CARDS == 0){
            ans.push_back(QVector<int> ());
        }

        ans[cards_read / MAX_CARDS].push_back(card_id);
        cards_read++;
    }

    //not enough cards.
    if(ans.back().size() < MAX_CARDS){
        ans.pop_back();
    }

    if(ans.empty()){
        std::cerr << "Invalid file format\n";
        exit(1);
    }

    return ans;
}


/**********************************************************************
    usage
    $ hand-str-test --no-gui tests.txt      Output test case to console
    $ hand-str-test tests.txt               Display test cases in GUI.
    $ hand-str-test                         Use random test cases.
**********************************************************************/
int main(int argc, char *argv[])
{
    int players = 8;

    std::string test_file;
    bool display_gui = true;

    QVector<QVector<int>> test_cases;

    if(argc > 1){
        if(argv[1] == std::string("--no-gui")){
            if(argc <= 2){
                std::cerr << "Error: No input file provided.\n";
                return 1;
            }

            display_gui = false;
            if(argc > 2)
                test_cases = load_test_cases(argv[2]);
        }
        else
            test_cases = load_test_cases(argv[1]);
    }

    QApplication a(argc, argv);
    HandStrengthTester hst(players);

    if(display_gui)
        hst.show();

    QVector<int> cases;
    if(!test_cases.isEmpty()){
        for(auto &c: test_cases){
            hst.test_custom(c);
        }

        if(!display_gui)
            return 0;
    }
    else{
        hst.test();
    }

    return a.exec();
}
