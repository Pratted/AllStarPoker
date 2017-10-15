/********************************************************************************
** Form generated from reading UI file 'handstrengthtester.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDSTRENGTHTESTER_H
#define UI_HANDSTRENGTHTESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandStrengthTester
{
public:
    QWidget *centralWidget;
    QLabel *background;
    QLabel *player0_card1;
    QLabel *player0_card2;
    QLabel *player1_card2;
    QLabel *player1_card1;
    QLabel *player2_card2;
    QLabel *player2_card1;
    QLabel *player3_card2;
    QLabel *player3_card1;
    QLabel *player4_card2;
    QLabel *player4_card1;
    QLabel *player5_card2;
    QLabel *player5_card1;
    QLabel *player6_card2;
    QLabel *player6_card1;
    QLabel *player7_card2;
    QLabel *player7_card1;
    QTextEdit *player0;
    QTextEdit *player1;
    QTextEdit *player2;
    QTextEdit *player3;
    QTextEdit *player7;
    QTextEdit *player6;
    QTextEdit *player5;
    QTextEdit *player4;
    QLabel *card1;
    QLabel *card4;
    QLabel *card3;
    QLabel *card2;
    QLabel *card5;
    QLabel *description;
    QPushButton *button_test_again;

    void setupUi(QMainWindow *HandStrengthTester)
    {
        if (HandStrengthTester->objectName().isEmpty())
            HandStrengthTester->setObjectName(QStringLiteral("HandStrengthTester"));
        HandStrengthTester->resize(1049, 539);
        centralWidget = new QWidget(HandStrengthTester);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        background = new QLabel(centralWidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-40, 0, 1121, 541));
        background->setPixmap(QPixmap(QString::fromUtf8("../images/background.jpg")));
        player0_card1 = new QLabel(centralWidget);
        player0_card1->setObjectName(QStringLiteral("player0_card1"));
        player0_card1->setGeometry(QRect(170, 60, 44, 63));
        player0_card1->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player0_card2 = new QLabel(centralWidget);
        player0_card2->setObjectName(QStringLiteral("player0_card2"));
        player0_card2->setGeometry(QRect(220, 60, 44, 63));
        player0_card2->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player1_card2 = new QLabel(centralWidget);
        player1_card2->setObjectName(QStringLiteral("player1_card2"));
        player1_card2->setGeometry(QRect(220, 170, 44, 63));
        player1_card2->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player1_card1 = new QLabel(centralWidget);
        player1_card1->setObjectName(QStringLiteral("player1_card1"));
        player1_card1->setGeometry(QRect(170, 170, 44, 63));
        player1_card1->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player2_card2 = new QLabel(centralWidget);
        player2_card2->setObjectName(QStringLiteral("player2_card2"));
        player2_card2->setGeometry(QRect(220, 280, 44, 63));
        player2_card2->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player2_card1 = new QLabel(centralWidget);
        player2_card1->setObjectName(QStringLiteral("player2_card1"));
        player2_card1->setGeometry(QRect(170, 280, 44, 63));
        player2_card1->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player3_card2 = new QLabel(centralWidget);
        player3_card2->setObjectName(QStringLiteral("player3_card2"));
        player3_card2->setGeometry(QRect(220, 390, 44, 63));
        player3_card2->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player3_card1 = new QLabel(centralWidget);
        player3_card1->setObjectName(QStringLiteral("player3_card1"));
        player3_card1->setGeometry(QRect(170, 390, 44, 63));
        player3_card1->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player4_card2 = new QLabel(centralWidget);
        player4_card2->setObjectName(QStringLiteral("player4_card2"));
        player4_card2->setGeometry(QRect(810, 60, 44, 63));
        player4_card2->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player4_card1 = new QLabel(centralWidget);
        player4_card1->setObjectName(QStringLiteral("player4_card1"));
        player4_card1->setGeometry(QRect(760, 60, 44, 63));
        player4_card1->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player5_card2 = new QLabel(centralWidget);
        player5_card2->setObjectName(QStringLiteral("player5_card2"));
        player5_card2->setGeometry(QRect(810, 160, 44, 63));
        player5_card2->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player5_card1 = new QLabel(centralWidget);
        player5_card1->setObjectName(QStringLiteral("player5_card1"));
        player5_card1->setGeometry(QRect(760, 160, 44, 63));
        player5_card1->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player6_card2 = new QLabel(centralWidget);
        player6_card2->setObjectName(QStringLiteral("player6_card2"));
        player6_card2->setGeometry(QRect(810, 270, 44, 63));
        player6_card2->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player6_card1 = new QLabel(centralWidget);
        player6_card1->setObjectName(QStringLiteral("player6_card1"));
        player6_card1->setGeometry(QRect(760, 270, 44, 63));
        player6_card1->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player7_card2 = new QLabel(centralWidget);
        player7_card2->setObjectName(QStringLiteral("player7_card2"));
        player7_card2->setGeometry(QRect(810, 390, 44, 63));
        player7_card2->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player7_card1 = new QLabel(centralWidget);
        player7_card1->setObjectName(QStringLiteral("player7_card1"));
        player7_card1->setGeometry(QRect(760, 390, 44, 63));
        player7_card1->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        player0 = new QTextEdit(centralWidget);
        player0->setObjectName(QStringLiteral("player0"));
        player0->setGeometry(QRect(60, 70, 31, 41));
        player1 = new QTextEdit(centralWidget);
        player1->setObjectName(QStringLiteral("player1"));
        player1->setGeometry(QRect(60, 180, 31, 41));
        player2 = new QTextEdit(centralWidget);
        player2->setObjectName(QStringLiteral("player2"));
        player2->setGeometry(QRect(60, 290, 31, 41));
        player3 = new QTextEdit(centralWidget);
        player3->setObjectName(QStringLiteral("player3"));
        player3->setGeometry(QRect(60, 400, 31, 41));
        player7 = new QTextEdit(centralWidget);
        player7->setObjectName(QStringLiteral("player7"));
        player7->setGeometry(QRect(900, 400, 31, 41));
        player6 = new QTextEdit(centralWidget);
        player6->setObjectName(QStringLiteral("player6"));
        player6->setGeometry(QRect(900, 290, 31, 41));
        player5 = new QTextEdit(centralWidget);
        player5->setObjectName(QStringLiteral("player5"));
        player5->setGeometry(QRect(900, 180, 31, 41));
        player4 = new QTextEdit(centralWidget);
        player4->setObjectName(QStringLiteral("player4"));
        player4->setGeometry(QRect(900, 70, 31, 41));
        card1 = new QLabel(centralWidget);
        card1->setObjectName(QStringLiteral("card1"));
        card1->setGeometry(QRect(370, 220, 44, 63));
        card1->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        card4 = new QLabel(centralWidget);
        card4->setObjectName(QStringLiteral("card4"));
        card4->setGeometry(QRect(550, 220, 44, 63));
        card4->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        card3 = new QLabel(centralWidget);
        card3->setObjectName(QStringLiteral("card3"));
        card3->setGeometry(QRect(490, 220, 44, 63));
        card3->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        card2 = new QLabel(centralWidget);
        card2->setObjectName(QStringLiteral("card2"));
        card2->setGeometry(QRect(430, 220, 44, 63));
        card2->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        card5 = new QLabel(centralWidget);
        card5->setObjectName(QStringLiteral("card5"));
        card5->setGeometry(QRect(610, 220, 44, 63));
        card5->setPixmap(QPixmap(QString::fromUtf8("../images/cardDeck.png")));
        description = new QLabel(centralWidget);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(330, 370, 371, 131));
        button_test_again = new QPushButton(centralWidget);
        button_test_again->setObjectName(QStringLiteral("button_test_again"));
        button_test_again->setGeometry(QRect(810, 490, 151, 23));
        HandStrengthTester->setCentralWidget(centralWidget);

        retranslateUi(HandStrengthTester);

        QMetaObject::connectSlotsByName(HandStrengthTester);
    } // setupUi

    void retranslateUi(QMainWindow *HandStrengthTester)
    {
        HandStrengthTester->setWindowTitle(QApplication::translate("HandStrengthTester", "HandStrengthTester", Q_NULLPTR));
        background->setText(QString());
        player0_card1->setText(QString());
        player0_card2->setText(QString());
        player1_card2->setText(QString());
        player1_card1->setText(QString());
        player2_card2->setText(QString());
        player2_card1->setText(QString());
        player3_card2->setText(QString());
        player3_card1->setText(QString());
        player4_card2->setText(QString());
        player4_card1->setText(QString());
        player5_card2->setText(QString());
        player5_card1->setText(QString());
        player6_card2->setText(QString());
        player6_card1->setText(QString());
        player7_card2->setText(QString());
        player7_card1->setText(QString());
        player0->setHtml(QApplication::translate("HandStrengthTester", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">0</span></p></body></html>", Q_NULLPTR));
        player1->setHtml(QApplication::translate("HandStrengthTester", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">1</span></p></body></html>", Q_NULLPTR));
        player2->setHtml(QApplication::translate("HandStrengthTester", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">2</span></p></body></html>", Q_NULLPTR));
        player3->setHtml(QApplication::translate("HandStrengthTester", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">3</span></p></body></html>", Q_NULLPTR));
        player7->setHtml(QApplication::translate("HandStrengthTester", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">7</span></p></body></html>", Q_NULLPTR));
        player6->setHtml(QApplication::translate("HandStrengthTester", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">6</span></p></body></html>", Q_NULLPTR));
        player5->setHtml(QApplication::translate("HandStrengthTester", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">5</span></p></body></html>", Q_NULLPTR));
        player4->setHtml(QApplication::translate("HandStrengthTester", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">4</span></p></body></html>", Q_NULLPTR));
        card1->setText(QString());
        card4->setText(QString());
        card3->setText(QString());
        card2->setText(QString());
        card5->setText(QString());
        description->setText(QApplication::translate("HandStrengthTester", "TextLabel", Q_NULLPTR));
        button_test_again->setText(QApplication::translate("HandStrengthTester", "Test Again", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HandStrengthTester: public Ui_HandStrengthTester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDSTRENGTHTESTER_H
