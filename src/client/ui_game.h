/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QAction *actionLeave_Game;
    QAction *actionQuit_AllStarPoker;
    QWidget *centralwidget;
    QLabel *labelTable;
    QLabel *labelBottomLeft;
    QLabel *labelBottomRight;
    QLabel *placeholder0;
    QLabel *placeholder6;
    QLabel *placeholder5;
    QLabel *placeholder7;
    QLabel *placeholder4;
    QLabel *placeholder3;
    QLabel *placeholder2;
    QLabel *placeholder1;
    QLabel *labelPotHolder;
    QLabel *labelCommunityCard1;
    QLabel *labelCommunityCard2;
    QLabel *labelCommunityCard3;
    QLabel *labelCommunityCard4;
    QLabel *labelCommunityCard5;
    QLabel *Player3Card2;
    QLabel *Player3Card1;
    QLabel *Player2Card2;
    QLabel *Player2Card1;
    QLabel *Player1Card2;
    QLabel *Player1Card1;
    QLabel *Player0Card2;
    QLabel *Player0Card1;
    QLabel *Player7Card2;
    QLabel *Player7Card1;
    QLabel *Player6Card2;
    QLabel *Player6Card1;
    QLabel *Player5Card2;
    QLabel *Player5Card1;
    QLabel *Player4Card2;
    QLabel *Player4Card1;
    QLabel *labelCardHolder;
    QLabel *labelButtonHolder;
    QLabel *labelPlayerCard2;
    QLabel *labelPlayerCard1;
    QLabel *Player4Stack2;
    QLabel *Player4Stack0;
    QLabel *Player4Stack1;
    QLabel *Player4Stack3;
    QLabel *Player4Stack7;
    QLabel *Player4Stack6;
    QLabel *Player4Stack5;
    QLabel *Player4Stack4;
    QLabel *Player3Stack7;
    QLabel *Player3Stack4;
    QLabel *Player3Stack0;
    QLabel *Player3Stack6;
    QLabel *Player3Stack1;
    QLabel *Player3Stack5;
    QLabel *Player3Stack3;
    QLabel *Player3Stack2;
    QLabel *Player7Stack3;
    QLabel *Player7Stack0;
    QLabel *Player7Stack4;
    QLabel *Player7Stack2;
    QLabel *Player7Stack5;
    QLabel *Player7Stack1;
    QLabel *Player7Stack7;
    QLabel *Player7Stack6;
    QLabel *Player0Stack7;
    QLabel *Player0Stack3;
    QLabel *Player0Stack2;
    QLabel *Player0Stack5;
    QLabel *Player0Stack0;
    QLabel *Player0Stack1;
    QLabel *Player0Stack6;
    QLabel *Player0Stack4;
    QLabel *Player6Stack2;
    QLabel *Player6Stack1;
    QLabel *Player6Stack4;
    QLabel *Player6Stack0;
    QLabel *Player6Stack6;
    QLabel *Player6Stack3;
    QLabel *Player6Stack5;
    QLabel *Player6Stack7;
    QLabel *Player5Stack3;
    QLabel *Player5Stack1;
    QLabel *Player5Stack6;
    QLabel *Player5Stack4;
    QLabel *Player5Stack2;
    QLabel *Player5Stack0;
    QLabel *Player5Stack7;
    QLabel *Player5Stack5;
    QLabel *Player1Stack4;
    QLabel *Player1Stack1;
    QLabel *Player1Stack6;
    QLabel *Player1Stack2;
    QLabel *Player1Stack7;
    QLabel *Player1Stack3;
    QLabel *Player2Stack7;
    QLabel *Player2Stack5;
    QLabel *Player2Stack0;
    QLabel *Player2Stack1;
    QLabel *Player2Stack4;
    QLabel *Player2Stack6;
    QLabel *Player2Stack3;
    QLabel *Player2Stack2;
    QLabel *Player1Stack5;
    QLabel *Player1Stack0;
    QPushButton *buttonSitInSeat0;
    QPushButton *buttonSitInSeat1;
    QPushButton *buttonSitInSeat2;
    QPushButton *buttonSitInSeat3;
    QPushButton *buttonSitInSeat4;
    QPushButton *buttonSitInSeat5;
    QPushButton *buttonSitInSeat6;
    QPushButton *buttonSitInSeat7;
    QLabel *background;
    QLabel *Player0Name;
    QLabel *Player0ChipCount;
    QLabel *Player1Name;
    QLabel *Player1ChipCount;
    QLabel *Player2Name;
    QLabel *Player2ChipCount;
    QLabel *Player3Name;
    QLabel *Player3ChipCount;
    QLabel *Player7Name;
    QLabel *Player7ChipCount;
    QLabel *Player6Name;
    QLabel *Player6ChipCount;
    QLabel *Player5Name;
    QLabel *Player5ChipCount;
    QLabel *Player4Name;
    QLabel *Player4ChipCount;
    QLabel *label;
    QPushButton *buttonIncrementBet;
    QPushButton *buttonDecrementBet;
    QLabel *labelMessageBackground;
    QLineEdit *messageBox;
    QTextBrowser *messageBrowser;
    QLabel *labelPot;
    QPushButton *buttonBet;
    QPushButton *buttonCall;
    QPushButton *buttonFold;
    QPushButton *buttonCancel;
    QPushButton *buttonSubmit;
    QLineEdit *inputBet;
    QSlider *horizontalBetSlider;
    QLabel *player0_blind;
    QLabel *player1_blind;
    QLabel *player2_blind;
    QLabel *player3_blind;
    QLabel *player4_blind;
    QLabel *player5_blind;
    QLabel *player6_blind;
    QLabel *player7_blind;
    QMenuBar *menubar;
    QMenu *menuGame;

    void setupUi(QMainWindow *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QStringLiteral("Game"));
        Game->resize(1569, 800);
        actionLeave_Game = new QAction(Game);
        actionLeave_Game->setObjectName(QStringLiteral("actionLeave_Game"));
        actionQuit_AllStarPoker = new QAction(Game);
        actionQuit_AllStarPoker->setObjectName(QStringLiteral("actionQuit_AllStarPoker"));
        centralwidget = new QWidget(Game);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        labelTable = new QLabel(centralwidget);
        labelTable->setObjectName(QStringLiteral("labelTable"));
        labelTable->setGeometry(QRect(250, 60, 794, 547));
        labelTable->setPixmap(QPixmap(QString::fromUtf8("images/ft_green_poker_skin.png")));
        labelBottomLeft = new QLabel(centralwidget);
        labelBottomLeft->setObjectName(QStringLiteral("labelBottomLeft"));
        labelBottomLeft->setGeometry(QRect(20, 700, 591, 31));
        labelBottomLeft->setStyleSheet(QStringLiteral("color: white"));
        labelBottomRight = new QLabel(centralwidget);
        labelBottomRight->setObjectName(QStringLiteral("labelBottomRight"));
        labelBottomRight->setGeometry(QRect(1010, 700, 261, 51));
        labelBottomRight->setStyleSheet(QStringLiteral("color: white"));
        labelBottomRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelBottomRight->setWordWrap(true);
        placeholder0 = new QLabel(centralwidget);
        placeholder0->setObjectName(QStringLiteral("placeholder0"));
        placeholder0->setGeometry(QRect(740, 40, 240, 130));
        placeholder0->setPixmap(QPixmap(QString::fromUtf8("images/playerInfoButton1.2x2.png")));
        placeholder0->setScaledContents(true);
        placeholder6 = new QLabel(centralwidget);
        placeholder6->setObjectName(QStringLiteral("placeholder6"));
        placeholder6->setGeometry(QRect(80, 180, 240, 130));
        placeholder6->setPixmap(QPixmap(QString::fromUtf8("images/playerInfoButton2.2x2.png")));
        placeholder6->setScaledContents(true);
        placeholder5 = new QLabel(centralwidget);
        placeholder5->setObjectName(QStringLiteral("placeholder5"));
        placeholder5->setGeometry(QRect(100, 380, 240, 130));
        placeholder5->setPixmap(QPixmap(QString::fromUtf8("images/playerInfoButton2.2x2.png")));
        placeholder5->setScaledContents(true);
        placeholder7 = new QLabel(centralwidget);
        placeholder7->setObjectName(QStringLiteral("placeholder7"));
        placeholder7->setGeometry(QRect(290, 40, 240, 130));
        placeholder7->setPixmap(QPixmap(QString::fromUtf8("images/playerInfoButton2.2x2.png")));
        placeholder7->setScaledContents(true);
        placeholder4 = new QLabel(centralwidget);
        placeholder4->setObjectName(QStringLiteral("placeholder4"));
        placeholder4->setGeometry(QRect(370, 470, 240, 130));
        placeholder4->setPixmap(QPixmap(QString::fromUtf8("images/playerInfoButton2.2x2.png")));
        placeholder4->setScaledContents(true);
        placeholder3 = new QLabel(centralwidget);
        placeholder3->setObjectName(QStringLiteral("placeholder3"));
        placeholder3->setGeometry(QRect(680, 470, 240, 130));
        placeholder3->setPixmap(QPixmap(QString::fromUtf8("images/playerInfoButton1.2x2.png")));
        placeholder3->setScaledContents(true);
        placeholder2 = new QLabel(centralwidget);
        placeholder2->setObjectName(QStringLiteral("placeholder2"));
        placeholder2->setGeometry(QRect(950, 380, 240, 130));
        placeholder2->setPixmap(QPixmap(QString::fromUtf8("images/playerInfoButton1.2x2.png")));
        placeholder2->setScaledContents(true);
        placeholder1 = new QLabel(centralwidget);
        placeholder1->setObjectName(QStringLiteral("placeholder1"));
        placeholder1->setGeometry(QRect(980, 190, 240, 130));
        placeholder1->setPixmap(QPixmap(QString::fromUtf8("images/playerInfoButton1.2x2.png")));
        placeholder1->setScaledContents(true);
        labelPotHolder = new QLabel(centralwidget);
        labelPotHolder->setObjectName(QStringLiteral("labelPotHolder"));
        labelPotHolder->setGeometry(QRect(560, 340, 160, 30));
        labelPotHolder->setPixmap(QPixmap(QString::fromUtf8("images/PotHolder.png")));
        labelPotHolder->setScaledContents(true);
        labelCommunityCard1 = new QLabel(centralwidget);
        labelCommunityCard1->setObjectName(QStringLiteral("labelCommunityCard1"));
        labelCommunityCard1->setGeometry(QRect(521, 270, 44, 63));
        labelCommunityCard1->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        labelCommunityCard2 = new QLabel(centralwidget);
        labelCommunityCard2->setObjectName(QStringLiteral("labelCommunityCard2"));
        labelCommunityCard2->setGeometry(QRect(573, 270, 44, 63));
        labelCommunityCard2->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        labelCommunityCard3 = new QLabel(centralwidget);
        labelCommunityCard3->setObjectName(QStringLiteral("labelCommunityCard3"));
        labelCommunityCard3->setGeometry(QRect(626, 270, 44, 63));
        labelCommunityCard3->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        labelCommunityCard4 = new QLabel(centralwidget);
        labelCommunityCard4->setObjectName(QStringLiteral("labelCommunityCard4"));
        labelCommunityCard4->setGeometry(QRect(679, 270, 44, 63));
        labelCommunityCard4->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        labelCommunityCard5 = new QLabel(centralwidget);
        labelCommunityCard5->setObjectName(QStringLiteral("labelCommunityCard5"));
        labelCommunityCard5->setGeometry(QRect(730, 270, 44, 63));
        labelCommunityCard5->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player3Card2 = new QLabel(centralwidget);
        Player3Card2->setObjectName(QStringLiteral("Player3Card2"));
        Player3Card2->setGeometry(QRect(860, 430, 44, 63));
        Player3Card2->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player3Card1 = new QLabel(centralwidget);
        Player3Card1->setObjectName(QStringLiteral("Player3Card1"));
        Player3Card1->setGeometry(QRect(820, 430, 44, 63));
        Player3Card1->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player2Card2 = new QLabel(centralwidget);
        Player2Card2->setObjectName(QStringLiteral("Player2Card2"));
        Player2Card2->setGeometry(QRect(1110, 340, 44, 63));
        Player2Card2->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player2Card1 = new QLabel(centralwidget);
        Player2Card1->setObjectName(QStringLiteral("Player2Card1"));
        Player2Card1->setGeometry(QRect(1070, 340, 51, 63));
        Player2Card1->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player1Card2 = new QLabel(centralwidget);
        Player1Card2->setObjectName(QStringLiteral("Player1Card2"));
        Player1Card2->setGeometry(QRect(1130, 150, 44, 63));
        Player1Card2->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player1Card1 = new QLabel(centralwidget);
        Player1Card1->setObjectName(QStringLiteral("Player1Card1"));
        Player1Card1->setGeometry(QRect(1090, 150, 44, 63));
        Player1Card1->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player0Card2 = new QLabel(centralwidget);
        Player0Card2->setObjectName(QStringLiteral("Player0Card2"));
        Player0Card2->setGeometry(QRect(890, 0, 44, 63));
        Player0Card2->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player0Card1 = new QLabel(centralwidget);
        Player0Card1->setObjectName(QStringLiteral("Player0Card1"));
        Player0Card1->setGeometry(QRect(850, 0, 44, 63));
        Player0Card1->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player7Card2 = new QLabel(centralwidget);
        Player7Card2->setObjectName(QStringLiteral("Player7Card2"));
        Player7Card2->setGeometry(QRect(370, 0, 44, 63));
        Player7Card2->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player7Card1 = new QLabel(centralwidget);
        Player7Card1->setObjectName(QStringLiteral("Player7Card1"));
        Player7Card1->setGeometry(QRect(330, 0, 44, 63));
        Player7Card1->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player6Card2 = new QLabel(centralwidget);
        Player6Card2->setObjectName(QStringLiteral("Player6Card2"));
        Player6Card2->setGeometry(QRect(160, 140, 44, 63));
        Player6Card2->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player6Card1 = new QLabel(centralwidget);
        Player6Card1->setObjectName(QStringLiteral("Player6Card1"));
        Player6Card1->setGeometry(QRect(120, 140, 44, 63));
        Player6Card1->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player5Card2 = new QLabel(centralwidget);
        Player5Card2->setObjectName(QStringLiteral("Player5Card2"));
        Player5Card2->setGeometry(QRect(180, 340, 44, 63));
        Player5Card2->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player5Card1 = new QLabel(centralwidget);
        Player5Card1->setObjectName(QStringLiteral("Player5Card1"));
        Player5Card1->setGeometry(QRect(140, 340, 44, 63));
        Player5Card1->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player4Card2 = new QLabel(centralwidget);
        Player4Card2->setObjectName(QStringLiteral("Player4Card2"));
        Player4Card2->setGeometry(QRect(450, 430, 44, 63));
        Player4Card2->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player4Card1 = new QLabel(centralwidget);
        Player4Card1->setObjectName(QStringLiteral("Player4Card1"));
        Player4Card1->setGeometry(QRect(410, 430, 44, 63));
        Player4Card1->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        labelCardHolder = new QLabel(centralwidget);
        labelCardHolder->setObjectName(QStringLiteral("labelCardHolder"));
        labelCardHolder->setGeometry(QRect(270, 620, 739, 137));
        labelCardHolder->setPixmap(QPixmap(QString::fromUtf8("images/playerGUIBackground.png")));
        labelCardHolder->setScaledContents(true);
        labelButtonHolder = new QLabel(centralwidget);
        labelButtonHolder->setObjectName(QStringLiteral("labelButtonHolder"));
        labelButtonHolder->setGeometry(QRect(270, 620, 739, 137));
        labelButtonHolder->setPixmap(QPixmap(QString::fromUtf8("images/playerGUIOverlay.png")));
        labelButtonHolder->setScaledContents(true);
        labelPlayerCard2 = new QLabel(centralwidget);
        labelPlayerCard2->setObjectName(QStringLiteral("labelPlayerCard2"));
        labelPlayerCard2->setGeometry(QRect(640, 625, 44, 63));
        labelPlayerCard2->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        labelPlayerCard1 = new QLabel(centralwidget);
        labelPlayerCard1->setObjectName(QStringLiteral("labelPlayerCard1"));
        labelPlayerCard1->setGeometry(QRect(600, 625, 44, 63));
        labelPlayerCard1->setPixmap(QPixmap(QString::fromUtf8("images/cardDeck.png")));
        Player4Stack2 = new QLabel(centralwidget);
        Player4Stack2->setObjectName(QStringLiteral("Player4Stack2"));
        Player4Stack2->setGeometry(QRect(550, 440, 20, 24));
        Player4Stack2->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player4Stack2->setScaledContents(true);
        Player4Stack0 = new QLabel(centralwidget);
        Player4Stack0->setObjectName(QStringLiteral("Player4Stack0"));
        Player4Stack0->setGeometry(QRect(510, 440, 20, 24));
        Player4Stack0->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player4Stack0->setScaledContents(true);
        Player4Stack1 = new QLabel(centralwidget);
        Player4Stack1->setObjectName(QStringLiteral("Player4Stack1"));
        Player4Stack1->setGeometry(QRect(530, 440, 20, 24));
        Player4Stack1->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player4Stack1->setScaledContents(true);
        Player4Stack3 = new QLabel(centralwidget);
        Player4Stack3->setObjectName(QStringLiteral("Player4Stack3"));
        Player4Stack3->setGeometry(QRect(570, 440, 20, 24));
        Player4Stack3->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player4Stack3->setScaledContents(true);
        Player4Stack7 = new QLabel(centralwidget);
        Player4Stack7->setObjectName(QStringLiteral("Player4Stack7"));
        Player4Stack7->setGeometry(QRect(500, 420, 20, 24));
        Player4Stack7->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player4Stack7->setScaledContents(true);
        Player4Stack6 = new QLabel(centralwidget);
        Player4Stack6->setObjectName(QStringLiteral("Player4Stack6"));
        Player4Stack6->setGeometry(QRect(520, 420, 20, 24));
        Player4Stack6->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player4Stack6->setScaledContents(true);
        Player4Stack5 = new QLabel(centralwidget);
        Player4Stack5->setObjectName(QStringLiteral("Player4Stack5"));
        Player4Stack5->setGeometry(QRect(540, 420, 20, 24));
        Player4Stack5->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player4Stack5->setScaledContents(true);
        Player4Stack4 = new QLabel(centralwidget);
        Player4Stack4->setObjectName(QStringLiteral("Player4Stack4"));
        Player4Stack4->setGeometry(QRect(560, 420, 20, 24));
        Player4Stack4->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player4Stack4->setScaledContents(true);
        Player3Stack7 = new QLabel(centralwidget);
        Player3Stack7->setObjectName(QStringLiteral("Player3Stack7"));
        Player3Stack7->setGeometry(QRect(810, 420, 20, 24));
        Player3Stack7->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player3Stack7->setScaledContents(true);
        Player3Stack4 = new QLabel(centralwidget);
        Player3Stack4->setObjectName(QStringLiteral("Player3Stack4"));
        Player3Stack4->setGeometry(QRect(750, 420, 20, 24));
        Player3Stack4->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player3Stack4->setScaledContents(true);
        Player3Stack0 = new QLabel(centralwidget);
        Player3Stack0->setObjectName(QStringLiteral("Player3Stack0"));
        Player3Stack0->setGeometry(QRect(740, 440, 20, 24));
        Player3Stack0->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player3Stack0->setScaledContents(true);
        Player3Stack6 = new QLabel(centralwidget);
        Player3Stack6->setObjectName(QStringLiteral("Player3Stack6"));
        Player3Stack6->setGeometry(QRect(790, 420, 20, 24));
        Player3Stack6->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player3Stack6->setScaledContents(true);
        Player3Stack1 = new QLabel(centralwidget);
        Player3Stack1->setObjectName(QStringLiteral("Player3Stack1"));
        Player3Stack1->setGeometry(QRect(760, 440, 20, 24));
        Player3Stack1->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player3Stack1->setScaledContents(true);
        Player3Stack5 = new QLabel(centralwidget);
        Player3Stack5->setObjectName(QStringLiteral("Player3Stack5"));
        Player3Stack5->setGeometry(QRect(770, 420, 20, 24));
        Player3Stack5->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player3Stack5->setScaledContents(true);
        Player3Stack3 = new QLabel(centralwidget);
        Player3Stack3->setObjectName(QStringLiteral("Player3Stack3"));
        Player3Stack3->setGeometry(QRect(800, 440, 20, 24));
        Player3Stack3->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player3Stack3->setScaledContents(true);
        Player3Stack2 = new QLabel(centralwidget);
        Player3Stack2->setObjectName(QStringLiteral("Player3Stack2"));
        Player3Stack2->setGeometry(QRect(780, 440, 20, 24));
        Player3Stack2->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player3Stack2->setScaledContents(true);
        Player7Stack3 = new QLabel(centralwidget);
        Player7Stack3->setObjectName(QStringLiteral("Player7Stack3"));
        Player7Stack3->setGeometry(QRect(540, 160, 20, 24));
        Player7Stack3->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player7Stack3->setScaledContents(true);
        Player7Stack0 = new QLabel(centralwidget);
        Player7Stack0->setObjectName(QStringLiteral("Player7Stack0"));
        Player7Stack0->setGeometry(QRect(480, 160, 20, 24));
        Player7Stack0->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player7Stack0->setScaledContents(true);
        Player7Stack4 = new QLabel(centralwidget);
        Player7Stack4->setObjectName(QStringLiteral("Player7Stack4"));
        Player7Stack4->setGeometry(QRect(480, 180, 20, 24));
        Player7Stack4->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player7Stack4->setScaledContents(true);
        Player7Stack2 = new QLabel(centralwidget);
        Player7Stack2->setObjectName(QStringLiteral("Player7Stack2"));
        Player7Stack2->setGeometry(QRect(520, 160, 20, 24));
        Player7Stack2->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player7Stack2->setScaledContents(true);
        Player7Stack5 = new QLabel(centralwidget);
        Player7Stack5->setObjectName(QStringLiteral("Player7Stack5"));
        Player7Stack5->setGeometry(QRect(500, 180, 20, 24));
        Player7Stack5->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player7Stack5->setScaledContents(true);
        Player7Stack1 = new QLabel(centralwidget);
        Player7Stack1->setObjectName(QStringLiteral("Player7Stack1"));
        Player7Stack1->setGeometry(QRect(500, 160, 20, 24));
        Player7Stack1->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player7Stack1->setScaledContents(true);
        Player7Stack7 = new QLabel(centralwidget);
        Player7Stack7->setObjectName(QStringLiteral("Player7Stack7"));
        Player7Stack7->setGeometry(QRect(540, 180, 20, 24));
        Player7Stack7->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player7Stack7->setScaledContents(true);
        Player7Stack6 = new QLabel(centralwidget);
        Player7Stack6->setObjectName(QStringLiteral("Player7Stack6"));
        Player7Stack6->setGeometry(QRect(520, 180, 20, 24));
        Player7Stack6->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player7Stack6->setScaledContents(true);
        Player0Stack7 = new QLabel(centralwidget);
        Player0Stack7->setObjectName(QStringLiteral("Player0Stack7"));
        Player0Stack7->setGeometry(QRect(820, 180, 20, 24));
        Player0Stack7->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player0Stack7->setScaledContents(true);
        Player0Stack3 = new QLabel(centralwidget);
        Player0Stack3->setObjectName(QStringLiteral("Player0Stack3"));
        Player0Stack3->setGeometry(QRect(820, 160, 20, 24));
        Player0Stack3->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player0Stack3->setScaledContents(true);
        Player0Stack2 = new QLabel(centralwidget);
        Player0Stack2->setObjectName(QStringLiteral("Player0Stack2"));
        Player0Stack2->setGeometry(QRect(800, 160, 20, 24));
        Player0Stack2->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player0Stack2->setScaledContents(true);
        Player0Stack5 = new QLabel(centralwidget);
        Player0Stack5->setObjectName(QStringLiteral("Player0Stack5"));
        Player0Stack5->setGeometry(QRect(780, 180, 20, 24));
        Player0Stack5->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player0Stack5->setScaledContents(true);
        Player0Stack0 = new QLabel(centralwidget);
        Player0Stack0->setObjectName(QStringLiteral("Player0Stack0"));
        Player0Stack0->setGeometry(QRect(760, 160, 20, 24));
        Player0Stack0->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player0Stack0->setScaledContents(true);
        Player0Stack1 = new QLabel(centralwidget);
        Player0Stack1->setObjectName(QStringLiteral("Player0Stack1"));
        Player0Stack1->setGeometry(QRect(780, 160, 20, 24));
        Player0Stack1->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player0Stack1->setScaledContents(true);
        Player0Stack6 = new QLabel(centralwidget);
        Player0Stack6->setObjectName(QStringLiteral("Player0Stack6"));
        Player0Stack6->setGeometry(QRect(800, 180, 20, 24));
        Player0Stack6->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player0Stack6->setScaledContents(true);
        Player0Stack4 = new QLabel(centralwidget);
        Player0Stack4->setObjectName(QStringLiteral("Player0Stack4"));
        Player0Stack4->setGeometry(QRect(760, 180, 20, 24));
        Player0Stack4->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player0Stack4->setScaledContents(true);
        Player6Stack2 = new QLabel(centralwidget);
        Player6Stack2->setObjectName(QStringLiteral("Player6Stack2"));
        Player6Stack2->setGeometry(QRect(330, 230, 20, 24));
        Player6Stack2->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player6Stack2->setScaledContents(true);
        Player6Stack1 = new QLabel(centralwidget);
        Player6Stack1->setObjectName(QStringLiteral("Player6Stack1"));
        Player6Stack1->setGeometry(QRect(320, 250, 20, 24));
        Player6Stack1->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player6Stack1->setScaledContents(true);
        Player6Stack4 = new QLabel(centralwidget);
        Player6Stack4->setObjectName(QStringLiteral("Player6Stack4"));
        Player6Stack4->setGeometry(QRect(340, 250, 20, 24));
        Player6Stack4->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player6Stack4->setScaledContents(true);
        Player6Stack0 = new QLabel(centralwidget);
        Player6Stack0->setObjectName(QStringLiteral("Player6Stack0"));
        Player6Stack0->setGeometry(QRect(310, 270, 20, 24));
        Player6Stack0->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player6Stack0->setScaledContents(true);
        Player6Stack6 = new QLabel(centralwidget);
        Player6Stack6->setObjectName(QStringLiteral("Player6Stack6"));
        Player6Stack6->setGeometry(QRect(350, 270, 20, 24));
        Player6Stack6->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player6Stack6->setScaledContents(true);
        Player6Stack3 = new QLabel(centralwidget);
        Player6Stack3->setObjectName(QStringLiteral("Player6Stack3"));
        Player6Stack3->setGeometry(QRect(330, 270, 20, 24));
        Player6Stack3->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player6Stack3->setScaledContents(true);
        Player6Stack5 = new QLabel(centralwidget);
        Player6Stack5->setObjectName(QStringLiteral("Player6Stack5"));
        Player6Stack5->setGeometry(QRect(350, 230, 20, 24));
        Player6Stack5->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player6Stack5->setScaledContents(true);
        Player6Stack7 = new QLabel(centralwidget);
        Player6Stack7->setObjectName(QStringLiteral("Player6Stack7"));
        Player6Stack7->setGeometry(QRect(360, 250, 20, 24));
        Player6Stack7->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player6Stack7->setScaledContents(true);
        Player5Stack3 = new QLabel(centralwidget);
        Player5Stack3->setObjectName(QStringLiteral("Player5Stack3"));
        Player5Stack3->setGeometry(QRect(340, 350, 20, 24));
        Player5Stack3->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player5Stack3->setScaledContents(true);
        Player5Stack1 = new QLabel(centralwidget);
        Player5Stack1->setObjectName(QStringLiteral("Player5Stack1"));
        Player5Stack1->setGeometry(QRect(330, 370, 20, 24));
        Player5Stack1->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player5Stack1->setScaledContents(true);
        Player5Stack6 = new QLabel(centralwidget);
        Player5Stack6->setObjectName(QStringLiteral("Player5Stack6"));
        Player5Stack6->setGeometry(QRect(360, 350, 20, 24));
        Player5Stack6->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player5Stack6->setScaledContents(true);
        Player5Stack4 = new QLabel(centralwidget);
        Player5Stack4->setObjectName(QStringLiteral("Player5Stack4"));
        Player5Stack4->setGeometry(QRect(350, 370, 20, 24));
        Player5Stack4->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player5Stack4->setScaledContents(true);
        Player5Stack2 = new QLabel(centralwidget);
        Player5Stack2->setObjectName(QStringLiteral("Player5Stack2"));
        Player5Stack2->setGeometry(QRect(320, 350, 20, 24));
        Player5Stack2->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player5Stack2->setScaledContents(true);
        Player5Stack0 = new QLabel(centralwidget);
        Player5Stack0->setObjectName(QStringLiteral("Player5Stack0"));
        Player5Stack0->setGeometry(QRect(340, 390, 20, 24));
        Player5Stack0->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player5Stack0->setScaledContents(true);
        Player5Stack7 = new QLabel(centralwidget);
        Player5Stack7->setObjectName(QStringLiteral("Player5Stack7"));
        Player5Stack7->setGeometry(QRect(370, 370, 20, 24));
        Player5Stack7->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player5Stack7->setScaledContents(true);
        Player5Stack5 = new QLabel(centralwidget);
        Player5Stack5->setObjectName(QStringLiteral("Player5Stack5"));
        Player5Stack5->setGeometry(QRect(360, 390, 20, 24));
        Player5Stack5->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player5Stack5->setScaledContents(true);
        Player1Stack4 = new QLabel(centralwidget);
        Player1Stack4->setObjectName(QStringLiteral("Player1Stack4"));
        Player1Stack4->setGeometry(QRect(930, 250, 20, 24));
        Player1Stack4->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player1Stack4->setScaledContents(true);
        Player1Stack1 = new QLabel(centralwidget);
        Player1Stack1->setObjectName(QStringLiteral("Player1Stack1"));
        Player1Stack1->setGeometry(QRect(950, 250, 20, 24));
        Player1Stack1->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player1Stack1->setScaledContents(true);
        Player1Stack6 = new QLabel(centralwidget);
        Player1Stack6->setObjectName(QStringLiteral("Player1Stack6"));
        Player1Stack6->setGeometry(QRect(910, 250, 20, 24));
        Player1Stack6->setPixmap(QPixmap(QString::fromUtf8("BlueChipStack.png")));
        Player1Stack6->setScaledContents(true);
        Player1Stack2 = new QLabel(centralwidget);
        Player1Stack2->setObjectName(QStringLiteral("Player1Stack2"));
        Player1Stack2->setGeometry(QRect(940, 230, 20, 24));
        Player1Stack2->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player1Stack2->setScaledContents(true);
        Player1Stack7 = new QLabel(centralwidget);
        Player1Stack7->setObjectName(QStringLiteral("Player1Stack7"));
        Player1Stack7->setGeometry(QRect(900, 230, 20, 24));
        Player1Stack7->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player1Stack7->setScaledContents(true);
        Player1Stack3 = new QLabel(centralwidget);
        Player1Stack3->setObjectName(QStringLiteral("Player1Stack3"));
        Player1Stack3->setGeometry(QRect(920, 230, 20, 24));
        Player1Stack3->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player1Stack3->setScaledContents(true);
        Player2Stack7 = new QLabel(centralwidget);
        Player2Stack7->setObjectName(QStringLiteral("Player2Stack7"));
        Player2Stack7->setGeometry(QRect(890, 390, 20, 24));
        Player2Stack7->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player2Stack7->setScaledContents(true);
        Player2Stack5 = new QLabel(centralwidget);
        Player2Stack5->setObjectName(QStringLiteral("Player2Stack5"));
        Player2Stack5->setGeometry(QRect(910, 390, 20, 24));
        Player2Stack5->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player2Stack5->setScaledContents(true);
        Player2Stack0 = new QLabel(centralwidget);
        Player2Stack0->setObjectName(QStringLiteral("Player2Stack0"));
        Player2Stack0->setGeometry(QRect(930, 390, 20, 24));
        Player2Stack0->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player2Stack0->setScaledContents(true);
        Player2Stack1 = new QLabel(centralwidget);
        Player2Stack1->setObjectName(QStringLiteral("Player2Stack1"));
        Player2Stack1->setGeometry(QRect(940, 370, 20, 24));
        Player2Stack1->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player2Stack1->setScaledContents(true);
        Player2Stack4 = new QLabel(centralwidget);
        Player2Stack4->setObjectName(QStringLiteral("Player2Stack4"));
        Player2Stack4->setGeometry(QRect(920, 370, 20, 24));
        Player2Stack4->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player2Stack4->setScaledContents(true);
        Player2Stack6 = new QLabel(centralwidget);
        Player2Stack6->setObjectName(QStringLiteral("Player2Stack6"));
        Player2Stack6->setGeometry(QRect(900, 370, 20, 24));
        Player2Stack6->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player2Stack6->setScaledContents(true);
        Player2Stack3 = new QLabel(centralwidget);
        Player2Stack3->setObjectName(QStringLiteral("Player2Stack3"));
        Player2Stack3->setGeometry(QRect(930, 350, 20, 24));
        Player2Stack3->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player2Stack3->setScaledContents(true);
        Player2Stack2 = new QLabel(centralwidget);
        Player2Stack2->setObjectName(QStringLiteral("Player2Stack2"));
        Player2Stack2->setGeometry(QRect(950, 350, 20, 24));
        Player2Stack2->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player2Stack2->setScaledContents(true);
        Player1Stack5 = new QLabel(centralwidget);
        Player1Stack5->setObjectName(QStringLiteral("Player1Stack5"));
        Player1Stack5->setGeometry(QRect(930, 270, 20, 24));
        Player1Stack5->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player1Stack5->setScaledContents(true);
        Player1Stack0 = new QLabel(centralwidget);
        Player1Stack0->setObjectName(QStringLiteral("Player1Stack0"));
        Player1Stack0->setGeometry(QRect(950, 270, 20, 24));
        Player1Stack0->setPixmap(QPixmap(QString::fromUtf8("images/BlueChipStack.png")));
        Player1Stack0->setScaledContents(true);
        buttonSitInSeat0 = new QPushButton(centralwidget);
        buttonSitInSeat0->setObjectName(QStringLiteral("buttonSitInSeat0"));
        buttonSitInSeat0->setGeometry(QRect(750, 50, 104, 104));
        buttonSitInSeat0->setStyleSheet(QLatin1String("background-color: rgb(182,171,171);\n"
"border-style: solid;\n"
"border-width:2px;\n"
"border-radius:50px;\n"
"border-color: rgb(73,22,22);\n"
"max-width:100px;\n"
"max-height:100px;\n"
"min-width:100px;\n"
"min-height:100px;"));
        buttonSitInSeat1 = new QPushButton(centralwidget);
        buttonSitInSeat1->setObjectName(QStringLiteral("buttonSitInSeat1"));
        buttonSitInSeat1->setGeometry(QRect(990, 200, 104, 104));
        buttonSitInSeat1->setStyleSheet(QLatin1String("background-color: rgb(182,171,171);\n"
"border-style: solid;\n"
"border-width:2px;\n"
"border-radius:50px;\n"
"border-color: rgb(73,22,22);\n"
"max-width:100px;\n"
"max-height:100px;\n"
"min-width:100px;\n"
"min-height:100px;"));
        buttonSitInSeat2 = new QPushButton(centralwidget);
        buttonSitInSeat2->setObjectName(QStringLiteral("buttonSitInSeat2"));
        buttonSitInSeat2->setGeometry(QRect(960, 390, 104, 104));
        buttonSitInSeat2->setStyleSheet(QLatin1String("background-color: rgb(182,171,171);\n"
"border-style: solid;\n"
"border-width:2px;\n"
"border-radius:50px;\n"
"border-color: rgb(73,22,22);\n"
"max-width:100px;\n"
"max-height:100px;\n"
"min-width:100px;\n"
"min-height:100px;"));
        buttonSitInSeat3 = new QPushButton(centralwidget);
        buttonSitInSeat3->setObjectName(QStringLiteral("buttonSitInSeat3"));
        buttonSitInSeat3->setGeometry(QRect(690, 480, 104, 104));
        buttonSitInSeat3->setStyleSheet(QLatin1String("background-color: rgb(182,171,171);\n"
"border-style: solid;\n"
"border-width:2px;\n"
"border-radius:50px;\n"
"border-color: rgb(73,22,22);\n"
"max-width:100px;\n"
"max-height:100px;\n"
"min-width:100px;\n"
"min-height:100px;"));
        buttonSitInSeat4 = new QPushButton(centralwidget);
        buttonSitInSeat4->setObjectName(QStringLiteral("buttonSitInSeat4"));
        buttonSitInSeat4->setGeometry(QRect(490, 480, 104, 104));
        buttonSitInSeat4->setStyleSheet(QLatin1String("background-color: rgb(182,171,171);\n"
"border-style: solid;\n"
"border-width:2px;\n"
"border-radius:50px;\n"
"border-color: rgb(73,22,22);\n"
"max-width:100px;\n"
"max-height:100px;\n"
"min-width:100px;\n"
"min-height:100px;"));
        buttonSitInSeat5 = new QPushButton(centralwidget);
        buttonSitInSeat5->setObjectName(QStringLiteral("buttonSitInSeat5"));
        buttonSitInSeat5->setGeometry(QRect(220, 390, 104, 104));
        buttonSitInSeat5->setStyleSheet(QLatin1String("background-color: rgb(182,171,171);\n"
"border-style: solid;\n"
"border-width:2px;\n"
"border-radius:50px;\n"
"border-color: rgb(73,22,22);\n"
"max-width:100px;\n"
"max-height:100px;\n"
"min-width:100px;\n"
"min-height:100px;"));
        buttonSitInSeat6 = new QPushButton(centralwidget);
        buttonSitInSeat6->setObjectName(QStringLiteral("buttonSitInSeat6"));
        buttonSitInSeat6->setGeometry(QRect(210, 190, 104, 104));
        buttonSitInSeat6->setStyleSheet(QLatin1String("background-color: rgb(182,171,171);\n"
"border-style: solid;\n"
"border-width:2px;\n"
"border-radius:50px;\n"
"border-color: rgb(73,22,22);\n"
"max-width:100px;\n"
"max-height:100px;\n"
"min-width:100px;\n"
"min-height:100px;"));
        buttonSitInSeat7 = new QPushButton(centralwidget);
        buttonSitInSeat7->setObjectName(QStringLiteral("buttonSitInSeat7"));
        buttonSitInSeat7->setGeometry(QRect(410, 50, 104, 104));
        buttonSitInSeat7->setStyleSheet(QLatin1String("background-color: rgb(182,171,171);\n"
"border-style: solid;\n"
"border-width:2px;\n"
"border-radius:50px;\n"
"border-color: rgb(73,22,22);\n"
"max-width:100px;\n"
"max-height:100px;\n"
"min-width:100px;\n"
"min-height:100px;"));
        background = new QLabel(centralwidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 1571, 769));
        background->setPixmap(QPixmap(QString::fromUtf8("images/background.jpg")));
        background->setScaledContents(false);
        Player0Name = new QLabel(centralwidget);
        Player0Name->setObjectName(QStringLiteral("Player0Name"));
        Player0Name->setGeometry(QRect(870, 70, 100, 23));
        Player0Name->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player0Name->setTextFormat(Qt::PlainText);
        Player0Name->setScaledContents(false);
        Player0ChipCount = new QLabel(centralwidget);
        Player0ChipCount->setObjectName(QStringLiteral("Player0ChipCount"));
        Player0ChipCount->setGeometry(QRect(870, 100, 100, 23));
        Player0ChipCount->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player1Name = new QLabel(centralwidget);
        Player1Name->setObjectName(QStringLiteral("Player1Name"));
        Player1Name->setGeometry(QRect(1110, 220, 100, 23));
        Player1Name->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player1Name->setTextFormat(Qt::PlainText);
        Player1Name->setScaledContents(false);
        Player1ChipCount = new QLabel(centralwidget);
        Player1ChipCount->setObjectName(QStringLiteral("Player1ChipCount"));
        Player1ChipCount->setGeometry(QRect(1110, 250, 100, 23));
        Player1ChipCount->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player2Name = new QLabel(centralwidget);
        Player2Name->setObjectName(QStringLiteral("Player2Name"));
        Player2Name->setGeometry(QRect(1080, 410, 100, 23));
        Player2Name->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player2Name->setTextFormat(Qt::PlainText);
        Player2Name->setScaledContents(false);
        Player2ChipCount = new QLabel(centralwidget);
        Player2ChipCount->setObjectName(QStringLiteral("Player2ChipCount"));
        Player2ChipCount->setGeometry(QRect(1080, 440, 100, 23));
        Player2ChipCount->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player3Name = new QLabel(centralwidget);
        Player3Name->setObjectName(QStringLiteral("Player3Name"));
        Player3Name->setGeometry(QRect(810, 500, 100, 23));
        Player3Name->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player3Name->setTextFormat(Qt::PlainText);
        Player3Name->setScaledContents(false);
        Player3ChipCount = new QLabel(centralwidget);
        Player3ChipCount->setObjectName(QStringLiteral("Player3ChipCount"));
        Player3ChipCount->setGeometry(QRect(810, 530, 100, 23));
        Player3ChipCount->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player7Name = new QLabel(centralwidget);
        Player7Name->setObjectName(QStringLiteral("Player7Name"));
        Player7Name->setGeometry(QRect(300, 70, 100, 23));
        Player7Name->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player7Name->setTextFormat(Qt::PlainText);
        Player7Name->setScaledContents(false);
        Player7Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Player7ChipCount = new QLabel(centralwidget);
        Player7ChipCount->setObjectName(QStringLiteral("Player7ChipCount"));
        Player7ChipCount->setGeometry(QRect(300, 100, 100, 23));
        Player7ChipCount->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player7ChipCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Player6Name = new QLabel(centralwidget);
        Player6Name->setObjectName(QStringLiteral("Player6Name"));
        Player6Name->setGeometry(QRect(90, 210, 100, 23));
        Player6Name->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player6Name->setTextFormat(Qt::PlainText);
        Player6Name->setScaledContents(false);
        Player6Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Player6ChipCount = new QLabel(centralwidget);
        Player6ChipCount->setObjectName(QStringLiteral("Player6ChipCount"));
        Player6ChipCount->setGeometry(QRect(90, 240, 100, 23));
        Player6ChipCount->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player6ChipCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Player5Name = new QLabel(centralwidget);
        Player5Name->setObjectName(QStringLiteral("Player5Name"));
        Player5Name->setGeometry(QRect(110, 410, 100, 23));
        Player5Name->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player5Name->setTextFormat(Qt::PlainText);
        Player5Name->setScaledContents(false);
        Player5Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Player5ChipCount = new QLabel(centralwidget);
        Player5ChipCount->setObjectName(QStringLiteral("Player5ChipCount"));
        Player5ChipCount->setGeometry(QRect(110, 440, 100, 23));
        Player5ChipCount->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player5ChipCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Player4Name = new QLabel(centralwidget);
        Player4Name->setObjectName(QStringLiteral("Player4Name"));
        Player4Name->setGeometry(QRect(380, 500, 100, 23));
        Player4Name->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player4Name->setTextFormat(Qt::PlainText);
        Player4Name->setScaledContents(false);
        Player4Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Player4ChipCount = new QLabel(centralwidget);
        Player4ChipCount->setObjectName(QStringLiteral("Player4ChipCount"));
        Player4ChipCount->setGeometry(QRect(380, 530, 100, 23));
        Player4ChipCount->setStyleSheet(QStringLiteral("color: rgb(248, 248, 248)"));
        Player4ChipCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 170, 661, 121));
        QFont font;
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("color: white\n"
""));
        label->setAlignment(Qt::AlignCenter);
        buttonIncrementBet = new QPushButton(centralwidget);
        buttonIncrementBet->setObjectName(QStringLiteral("buttonIncrementBet"));
        buttonIncrementBet->setGeometry(QRect(670, 690, 31, 31));
        QFont font1;
        font1.setPointSize(16);
        buttonIncrementBet->setFont(font1);
        buttonIncrementBet->setStyleSheet(QLatin1String("background-color: rgb(88, 32, 32);\n"
"color: white;\n"
"border-style: solid;\n"
"border-width:0px;\n"
"border-radius:15px;\n"
"border-color: rgb(73,22,22);\n"
"max-width:31px;\n"
"max-height:31px;\n"
"min-width:31px;\n"
"min-height:31px"));
        buttonDecrementBet = new QPushButton(centralwidget);
        buttonDecrementBet->setObjectName(QStringLiteral("buttonDecrementBet"));
        buttonDecrementBet->setGeometry(QRect(460, 690, 31, 31));
        buttonDecrementBet->setFont(font1);
        buttonDecrementBet->setStyleSheet(QLatin1String("background-color: rgb(88, 32, 32);\n"
"color: white;\n"
"border-style: solid;\n"
"border-width:0px;\n"
"border-radius:15px;\n"
"border-color: rgb(73,22,22);\n"
"max-width:31px;\n"
"max-height:31px;\n"
"min-width:31px;\n"
"min-height:31px"));
        labelMessageBackground = new QLabel(centralwidget);
        labelMessageBackground->setObjectName(QStringLiteral("labelMessageBackground"));
        labelMessageBackground->setGeometry(QRect(1230, 10, 321, 701));
        labelMessageBackground->setPixmap(QPixmap(QString::fromUtf8("images/chatBox2.1x2.png")));
        labelMessageBackground->setScaledContents(true);
        messageBox = new QLineEdit(centralwidget);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        messageBox->setGeometry(QRect(1240, 620, 291, 51));
        messageBox->setStyleSheet(QLatin1String("background: transparent;\n"
"border: transparent;\n"
"icon: blafdsf; \n"
""));
        messageBox->setMaxLength(48);
        messageBrowser = new QTextBrowser(centralwidget);
        messageBrowser->setObjectName(QStringLiteral("messageBrowser"));
        messageBrowser->setGeometry(QRect(1250, 50, 281, 531));
        messageBrowser->setStyleSheet(QLatin1String("background: transparent;\n"
"border: transparent;"));
        messageBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        messageBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        labelPot = new QLabel(centralwidget);
        labelPot->setObjectName(QStringLiteral("labelPot"));
        labelPot->setGeometry(QRect(600, 345, 121, 23));
        QFont font2;
        font2.setPointSize(10);
        labelPot->setFont(font2);
        labelPot->setCursor(QCursor(Qt::ArrowCursor));
        buttonBet = new QPushButton(centralwidget);
        buttonBet->setObjectName(QStringLiteral("buttonBet"));
        buttonBet->setGeometry(QRect(573, 691, 131, 31));
        buttonBet->setStyleSheet(QLatin1String("background-color: rgb(88, 32, 32);\n"
"color: white"));
        buttonCall = new QPushButton(centralwidget);
        buttonCall->setObjectName(QStringLiteral("buttonCall"));
        buttonCall->setGeometry(QRect(397, 691, 131, 31));
        buttonCall->setStyleSheet(QLatin1String("background-color: rgb(88, 32, 32);\n"
"color: white"));
        buttonFold = new QPushButton(centralwidget);
        buttonFold->setObjectName(QStringLiteral("buttonFold"));
        buttonFold->setGeometry(QRect(750, 691, 131, 31));
        buttonFold->setStyleSheet(QLatin1String("background-color: rgb(88, 32, 32);\n"
"color: white"));
        buttonCancel = new QPushButton(centralwidget);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(320, 690, 131, 31));
        buttonCancel->setStyleSheet(QLatin1String("background-color: rgb(88, 32, 32);\n"
"color: white"));
        buttonSubmit = new QPushButton(centralwidget);
        buttonSubmit->setObjectName(QStringLiteral("buttonSubmit"));
        buttonSubmit->setGeometry(QRect(849, 691, 131, 31));
        buttonSubmit->setStyleSheet(QLatin1String("background-color: rgb(88, 32, 32);\n"
"color: white"));
        inputBet = new QLineEdit(centralwidget);
        inputBet->setObjectName(QStringLiteral("inputBet"));
        inputBet->setGeometry(QRect(708, 691, 131, 31));
        horizontalBetSlider = new QSlider(centralwidget);
        horizontalBetSlider->setObjectName(QStringLiteral("horizontalBetSlider"));
        horizontalBetSlider->setGeometry(QRect(500, 690, 161, 31));
        horizontalBetSlider->setStyleSheet(QStringLiteral(""));
        horizontalBetSlider->setOrientation(Qt::Horizontal);
        player0_blind = new QLabel(centralwidget);
        player0_blind->setObjectName(QStringLiteral("player0_blind"));
        player0_blind->setGeometry(QRect(850, 180, 31, 31));
        player0_blind->setPixmap(QPixmap(QString::fromUtf8("images/big_blind.png")));
        player1_blind = new QLabel(centralwidget);
        player1_blind->setObjectName(QStringLiteral("player1_blind"));
        player1_blind->setGeometry(QRect(950, 290, 31, 31));
        player1_blind->setPixmap(QPixmap(QString::fromUtf8("images/big_blind.png")));
        player2_blind = new QLabel(centralwidget);
        player2_blind->setObjectName(QStringLiteral("player2_blind"));
        player2_blind->setGeometry(QRect(900, 410, 31, 31));
        player2_blind->setPixmap(QPixmap(QString::fromUtf8("images/big_blind.png")));
        player3_blind = new QLabel(centralwidget);
        player3_blind->setObjectName(QStringLiteral("player3_blind"));
        player3_blind->setGeometry(QRect(710, 430, 31, 31));
        player3_blind->setPixmap(QPixmap(QString::fromUtf8("images/big_blind.png")));
        player4_blind = new QLabel(centralwidget);
        player4_blind->setObjectName(QStringLiteral("player4_blind"));
        player4_blind->setGeometry(QRect(470, 410, 31, 31));
        player4_blind->setPixmap(QPixmap(QString::fromUtf8("images/big_blind.png")));
        player5_blind = new QLabel(centralwidget);
        player5_blind->setObjectName(QStringLiteral("player5_blind"));
        player5_blind->setGeometry(QRect(380, 390, 31, 31));
        player5_blind->setPixmap(QPixmap(QString::fromUtf8("images/big_blind.png")));
        player6_blind = new QLabel(centralwidget);
        player6_blind->setObjectName(QStringLiteral("player6_blind"));
        player6_blind->setGeometry(QRect(310, 290, 31, 31));
        player6_blind->setPixmap(QPixmap(QString::fromUtf8("images/big_blind.png")));
        player7_blind = new QLabel(centralwidget);
        player7_blind->setObjectName(QStringLiteral("player7_blind"));
        player7_blind->setGeometry(QRect(450, 170, 31, 31));
        player7_blind->setPixmap(QPixmap(QString::fromUtf8("images/big_blind.png")));
        Game->setCentralWidget(centralwidget);
        buttonCancel->raise();
        buttonSubmit->raise();
        inputBet->raise();
        background->raise();
        labelCardHolder->raise();
        labelTable->raise();
        labelPlayerCard1->raise();
        labelPlayerCard2->raise();
        labelBottomLeft->raise();
        labelBottomRight->raise();
        labelPotHolder->raise();
        labelCommunityCard1->raise();
        labelCommunityCard2->raise();
        labelCommunityCard3->raise();
        labelCommunityCard4->raise();
        labelCommunityCard5->raise();
        Player5Card2->raise();
        Player5Card1->raise();
        Player4Card2->raise();
        Player4Card1->raise();
        Player4Stack7->raise();
        Player4Stack6->raise();
        Player4Stack5->raise();
        Player4Stack4->raise();
        Player4Stack0->raise();
        Player4Stack1->raise();
        Player4Stack3->raise();
        Player4Stack2->raise();
        Player3Stack7->raise();
        Player3Stack4->raise();
        Player3Stack0->raise();
        Player3Stack6->raise();
        Player3Stack1->raise();
        Player3Stack5->raise();
        Player3Stack3->raise();
        Player3Stack2->raise();
        Player7Stack3->raise();
        Player7Stack2->raise();
        Player7Stack1->raise();
        Player7Stack7->raise();
        Player7Stack5->raise();
        Player7Stack6->raise();
        Player7Stack4->raise();
        Player6Stack2->raise();
        Player6Stack1->raise();
        Player6Stack4->raise();
        Player6Stack0->raise();
        Player6Stack6->raise();
        Player6Stack3->raise();
        Player6Stack5->raise();
        Player6Stack7->raise();
        Player5Stack3->raise();
        Player5Stack1->raise();
        Player5Stack6->raise();
        Player5Stack4->raise();
        Player5Stack2->raise();
        Player5Stack0->raise();
        Player5Stack7->raise();
        Player5Stack5->raise();
        Player3Card2->raise();
        Player3Card1->raise();
        Player1Stack4->raise();
        Player1Stack1->raise();
        Player1Stack6->raise();
        Player1Stack2->raise();
        Player1Stack7->raise();
        Player1Stack3->raise();
        Player2Stack7->raise();
        Player2Stack5->raise();
        Player2Stack0->raise();
        Player2Stack1->raise();
        Player2Stack4->raise();
        Player2Stack6->raise();
        Player2Stack3->raise();
        Player2Stack2->raise();
        Player1Stack5->raise();
        Player1Stack0->raise();
        buttonSitInSeat0->raise();
        buttonSitInSeat1->raise();
        buttonSitInSeat2->raise();
        buttonSitInSeat3->raise();
        buttonSitInSeat4->raise();
        buttonSitInSeat5->raise();
        buttonSitInSeat6->raise();
        buttonSitInSeat7->raise();
        Player6Card2->raise();
        Player6Card1->raise();
        Player7Card1->raise();
        Player7Card2->raise();
        placeholder4->raise();
        placeholder5->raise();
        Player0Card1->raise();
        Player0Card2->raise();
        Player1Card1->raise();
        Player1Card2->raise();
        Player2Card1->raise();
        Player2Card2->raise();
        placeholder6->raise();
        placeholder7->raise();
        placeholder0->raise();
        placeholder1->raise();
        placeholder2->raise();
        placeholder3->raise();
        Player0ChipCount->raise();
        Player0Name->raise();
        Player1Name->raise();
        Player1ChipCount->raise();
        Player2Name->raise();
        Player2ChipCount->raise();
        Player3Name->raise();
        Player3ChipCount->raise();
        Player7Name->raise();
        Player7ChipCount->raise();
        Player6Name->raise();
        Player6ChipCount->raise();
        Player5Name->raise();
        Player5ChipCount->raise();
        Player4Name->raise();
        Player4ChipCount->raise();
        Player7Stack0->raise();
        Player0Stack0->raise();
        Player0Stack2->raise();
        Player0Stack1->raise();
        Player0Stack3->raise();
        Player0Stack7->raise();
        Player0Stack5->raise();
        Player0Stack4->raise();
        Player0Stack6->raise();
        label->raise();
        labelButtonHolder->raise();
        buttonBet->raise();
        buttonCall->raise();
        buttonFold->raise();
        horizontalBetSlider->raise();
        buttonIncrementBet->raise();
        buttonDecrementBet->raise();
        labelMessageBackground->raise();
        messageBox->raise();
        messageBrowser->raise();
        labelPot->raise();
        player0_blind->raise();
        player1_blind->raise();
        player2_blind->raise();
        player3_blind->raise();
        player4_blind->raise();
        player5_blind->raise();
        player6_blind->raise();
        player7_blind->raise();
        menubar = new QMenuBar(Game);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1569, 20));
        menuGame = new QMenu(menubar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        Game->setMenuBar(menubar);

        menubar->addAction(menuGame->menuAction());
        menuGame->addAction(actionLeave_Game);
        menuGame->addAction(actionQuit_AllStarPoker);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "MainWindow", Q_NULLPTR));
        actionLeave_Game->setText(QApplication::translate("Game", "Leave Game", Q_NULLPTR));
        actionQuit_AllStarPoker->setText(QApplication::translate("Game", "Quit AllStarPoker", Q_NULLPTR));
        labelTable->setText(QString());
        labelBottomLeft->setText(QApplication::translate("Game", "TextLabel", Q_NULLPTR));
        labelBottomRight->setText(QApplication::translate("Game", "TextLabel", Q_NULLPTR));
        placeholder0->setText(QString());
        placeholder6->setText(QString());
        placeholder5->setText(QString());
        placeholder7->setText(QString());
        placeholder4->setText(QString());
        placeholder3->setText(QString());
        placeholder2->setText(QString());
        placeholder1->setText(QString());
        labelPotHolder->setText(QString());
        labelCommunityCard1->setText(QString());
        labelCommunityCard2->setText(QString());
        labelCommunityCard3->setText(QString());
        labelCommunityCard4->setText(QString());
        labelCommunityCard5->setText(QString());
        Player3Card2->setText(QString());
        Player3Card1->setText(QString());
        Player2Card2->setText(QString());
        Player2Card1->setText(QString());
        Player1Card2->setText(QString());
        Player1Card1->setText(QString());
        Player0Card2->setText(QString());
        Player0Card1->setText(QString());
        Player7Card2->setText(QString());
        Player7Card1->setText(QString());
        Player6Card2->setText(QString());
        Player6Card1->setText(QString());
        Player5Card2->setText(QString());
        Player5Card1->setText(QString());
        Player4Card2->setText(QString());
        Player4Card1->setText(QString());
        labelCardHolder->setText(QString());
        labelButtonHolder->setText(QString());
        labelPlayerCard2->setText(QString());
        labelPlayerCard1->setText(QString());
        Player4Stack2->setText(QString());
        Player4Stack0->setText(QString());
        Player4Stack1->setText(QString());
        Player4Stack3->setText(QString());
        Player4Stack7->setText(QString());
        Player4Stack6->setText(QString());
        Player4Stack5->setText(QString());
        Player4Stack4->setText(QString());
        Player3Stack7->setText(QString());
        Player3Stack4->setText(QString());
        Player3Stack0->setText(QString());
        Player3Stack6->setText(QString());
        Player3Stack1->setText(QString());
        Player3Stack5->setText(QString());
        Player3Stack3->setText(QString());
        Player3Stack2->setText(QString());
        Player7Stack3->setText(QString());
        Player7Stack0->setText(QString());
        Player7Stack4->setText(QString());
        Player7Stack2->setText(QString());
        Player7Stack5->setText(QString());
        Player7Stack1->setText(QString());
        Player7Stack7->setText(QString());
        Player7Stack6->setText(QString());
        Player0Stack7->setText(QString());
        Player0Stack3->setText(QString());
        Player0Stack2->setText(QString());
        Player0Stack5->setText(QString());
        Player0Stack0->setText(QString());
        Player0Stack1->setText(QString());
        Player0Stack6->setText(QString());
        Player0Stack4->setText(QString());
        Player6Stack2->setText(QString());
        Player6Stack1->setText(QString());
        Player6Stack4->setText(QString());
        Player6Stack0->setText(QString());
        Player6Stack6->setText(QString());
        Player6Stack3->setText(QString());
        Player6Stack5->setText(QString());
        Player6Stack7->setText(QString());
        Player5Stack3->setText(QString());
        Player5Stack1->setText(QString());
        Player5Stack6->setText(QString());
        Player5Stack4->setText(QString());
        Player5Stack2->setText(QString());
        Player5Stack0->setText(QString());
        Player5Stack7->setText(QString());
        Player5Stack5->setText(QString());
        Player1Stack4->setText(QString());
        Player1Stack1->setText(QString());
        Player1Stack6->setText(QString());
        Player1Stack2->setText(QString());
        Player1Stack7->setText(QString());
        Player1Stack3->setText(QString());
        Player2Stack7->setText(QString());
        Player2Stack5->setText(QString());
        Player2Stack0->setText(QString());
        Player2Stack1->setText(QString());
        Player2Stack4->setText(QString());
        Player2Stack6->setText(QString());
        Player2Stack3->setText(QString());
        Player2Stack2->setText(QString());
        Player1Stack5->setText(QString());
        Player1Stack0->setText(QString());
        buttonSitInSeat0->setText(QApplication::translate("Game", "Sit", Q_NULLPTR));
        buttonSitInSeat1->setText(QApplication::translate("Game", "Sit", Q_NULLPTR));
        buttonSitInSeat2->setText(QApplication::translate("Game", "Sit", Q_NULLPTR));
        buttonSitInSeat3->setText(QApplication::translate("Game", "Sit", Q_NULLPTR));
        buttonSitInSeat4->setText(QApplication::translate("Game", "Sit", Q_NULLPTR));
        buttonSitInSeat5->setText(QApplication::translate("Game", "Sit", Q_NULLPTR));
        buttonSitInSeat6->setText(QApplication::translate("Game", "Sit", Q_NULLPTR));
        buttonSitInSeat7->setText(QApplication::translate("Game", "Sit", Q_NULLPTR));
        background->setText(QString());
        Player0Name->setText(QApplication::translate("Game", "Name", Q_NULLPTR));
        Player0ChipCount->setText(QApplication::translate("Game", "ChipCount", Q_NULLPTR));
        Player1Name->setText(QApplication::translate("Game", "Name", Q_NULLPTR));
        Player1ChipCount->setText(QApplication::translate("Game", "ChipCount", Q_NULLPTR));
        Player2Name->setText(QApplication::translate("Game", "Name", Q_NULLPTR));
        Player2ChipCount->setText(QApplication::translate("Game", "ChipCount", Q_NULLPTR));
        Player3Name->setText(QApplication::translate("Game", "Name", Q_NULLPTR));
        Player3ChipCount->setText(QApplication::translate("Game", "ChipCount", Q_NULLPTR));
        Player7Name->setText(QApplication::translate("Game", "Name", Q_NULLPTR));
        Player7ChipCount->setText(QApplication::translate("Game", "ChipCount", Q_NULLPTR));
        Player6Name->setText(QApplication::translate("Game", "Name", Q_NULLPTR));
        Player6ChipCount->setText(QApplication::translate("Game", "ChipCount", Q_NULLPTR));
        Player5Name->setText(QApplication::translate("Game", "Name", Q_NULLPTR));
        Player5ChipCount->setText(QApplication::translate("Game", "ChipCount", Q_NULLPTR));
        Player4Name->setText(QApplication::translate("Game", "Name", Q_NULLPTR));
        Player4ChipCount->setText(QApplication::translate("Game", "ChipCount", Q_NULLPTR));
        label->setText(QApplication::translate("Game", "Welcome Text", Q_NULLPTR));
        buttonIncrementBet->setText(QApplication::translate("Game", "+", Q_NULLPTR));
        buttonDecrementBet->setText(QApplication::translate("Game", "-", Q_NULLPTR));
        labelMessageBackground->setText(QString());
        messageBox->setInputMask(QString());
        messageBox->setText(QApplication::translate("Game", "Enter your message", Q_NULLPTR));
        labelPot->setText(QApplication::translate("Game", "TextLabel", Q_NULLPTR));
        buttonBet->setText(QApplication::translate("Game", "Bet", Q_NULLPTR));
        buttonCall->setText(QApplication::translate("Game", "Call", Q_NULLPTR));
        buttonFold->setText(QApplication::translate("Game", "Fold", Q_NULLPTR));
        buttonCancel->setText(QApplication::translate("Game", "Cancel", Q_NULLPTR));
        buttonSubmit->setText(QApplication::translate("Game", "Submit", Q_NULLPTR));
        player0_blind->setText(QString());
        player1_blind->setText(QString());
        player2_blind->setText(QString());
        player3_blind->setText(QString());
        player4_blind->setText(QString());
        player5_blind->setText(QString());
        player6_blind->setText(QString());
        player7_blind->setText(QString());
        menuGame->setTitle(QApplication::translate("Game", "Game", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
