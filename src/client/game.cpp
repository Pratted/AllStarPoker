#include <QJsonDocument>
#include <QJsonObject>
#include <QPalette>
#include <QDebug>
#include <QInputDialog>
#include <QLabel>

#include "../packet.h"
#include "player.h"
#include "community.h"

#include "game.h"
#include "seat.h"
#include "countdowntimer.h"
#include "account.h"
#include "client.h"

#include "ui_game.h"

Game::Game(QWidget *parent) :
    QMainWindow(parent)
    //ui(new Ui::Game)
{
    //ui->setupUi(this);
}

Game::Game(Client* client):
    client(client)
{


}


Game::Game(Client * client, JsonString str_game) :
    client(client),
    QMainWindow(0)
    //ui(new Ui::Game)
{
    QJsonObject json = QJsonDocument::fromJson(str_game.toUtf8()).object();

    this->max_players = json["max_players"].toInt();
    this->chip_count = json["chip_count"].toInt();
    this->status = Game::Status(json["status"].toInt());
    this->id = json["id"].toInt();
}

QString Game::statusToString(){
    switch(status){
        case IN_PROGRESS:
            return "In Progress";
        case WAITING_FOR_PLAYERS:
            return "Waiting for players";
        case STARTING:
            return "Starting";
        default:
            return "Unknown";
    }
}

int Game::chooseSeat(int seat_id){
    qDebug() << "Seat " << seat_id << " selected!";

    QJsonObject json;
    json.insert("seat_id", seat_id);
    json.insert("game_id", this->id);
    json.insert("username", client->account.username);

    QJsonDocument doc(json);
    Packet outgoing(Packet::Opcode::C2S_CHOSE_SEAT, QString(doc.toJson(QJsonDocument::Compact)));
    client->sendPacket(outgoing);
}

void Game::removePlayer(QString payload){
    int seat_id = payload.toInt();

    qDebug() << "Removing player in seat: " << seat_id;
    auto it = std::find_if(players.begin(), players.end(), [seat_id](const Player* p){
        return p->getId() == seat_id;
    });

    Player* p = *it;

    delete p;
    players.erase(it);

    seats[seat_id].clear();
}

void Game::peek(){
    client->game = this;

    Packet packet(Packet::C2S_PEEK_GAME, QString::number(this->id));
    emit packetReady(packet);
}

void Game::sendMessage(){
    qDebug() << "Sending message....\n";
    QString message = ui->messageBox->text();

    //empty or message full of whitespace...
    if(message.isEmpty() || message.trimmed().isEmpty()) return;
    ui->messageBox->clear();

    message = client->player->getName() + ": " + message;

    Packet packet(Packet::Opcode::C2S_MESSAGE, message);
    client->sendPacket(packet);
}

void Game::displayMessage(QString message){
    ui->messageBrowser->append(message);
}

QString Game::promptName(){
    return QInputDialog::getText(this, "Enter your name", tr("Enter your name")).trimmed();
}

void Game::startNewGameTimer(){
    new_game_timer.start(1000);
}

void Game::countdown(){
    static int seconds_left = 4;

    QString msg = "The next round begins in: ";
    msg += QString::number(seconds_left);

    if(seconds_left--){
        ui->labelBottomRight->setText(msg);
        ui->labelBottomRight->show();
    }
    else{
        seconds_left = 5;
        new_game_timer.stop();
        ui->labelBottomRight->hide();
    }
}


Player* Game::getPlayerFromId(int id){
    return *std::find_if(players.begin(), players.end(), [id](const Player* p){
        return p->getId() == id;
    });
}

void Game::setPlayerTurn(QString payload){
    qDebug() << "SETTING PLAYER TURN.\n";
    int id = payload.toInt();

    Player* p = getPlayerFromId(id);
    p->startCountdownTimer();
}

bool Game::setup(){
    bool ok;

    QString name = QInputDialog::getText(this, "Enter your name", tr("Enter your name"), QLineEdit::Normal, "", &ok);
    while(name.isEmpty()){
        name = QInputDialog::getText(this, "Enter your name", tr("Enter your name"), QLineEdit::Normal, "", &ok);

        if(!ok) return ok;
    }

    if(!ok){
        qDebug() << "The user cancelled!\n";
        return ok;
    }

    client->account.username = name;

    for(int i = 0; i < MAX_TABLE_SIZE; i++){
        seats.push_back(Seat(i));
    }

    ui = new Ui::Game;
    ui->setupUi(this);

    connect(ui->messageBox, &QLineEdit::returnPressed, this, &Game::sendMessage);
    connect(ui->actionLeave_Game, &QAction::triggered, client, std::bind(&Client::leaveGame, client, this->id));

    this->setBackground();
    this->positionSeats();

    new_game_timer.setParent(this);
    connect(&new_game_timer, &QTimer::timeout, this, &Game::countdown);

    ui->labelCardHolder->show();
    ui->labelButtonHolder->show();
    ui->labelPotHolder->show();

    return ok;
}

void Game::addPlayer(Player* player){
    int seat_id = player->getId();

    qDebug() << "Seat id: " << seat_id;

    seats[seat_id].seat(player);


    this->players.push_back(player);
    std::sort(players.begin(), players.end(), [](const Player* a, const Player* b){
        return a->getId() < b->getId();
    });
}


void Game::setBlinds(QString payload){
    int dealer = payload.split(",")[0].toInt();
    int big_blind = payload.split(",")[1].toInt();
    int small_blind = payload.split(",")[2].toInt();

    Player* p = getPlayerFromId(dealer);
    p->seat->blind_chip->setPixmap(QPixmap::fromImage(Seat::dealer_chip_img));
    p->seat->blind_chip->show();

    p = getPlayerFromId(big_blind);
    p->seat->blind_chip->setPixmap(QPixmap::fromImage(Seat::big_blind_img));
    p->seat->blind_chip->show();

    qDebug() << "Showing big blind chip for player " << p->id;
    p = getPlayerFromId(small_blind);
    p->seat->blind_chip->setPixmap(QPixmap::fromImage(Seat::small_blind_img));
    p->seat->blind_chip->show();
}

void Game::refreshTable(){
    qDebug() << "CHECKING TABLE\n";
    qDebug() << "There are " << players.size() << " players";
    for(auto &player: players){
        qDebug() << "Checking player...\n";
        if(player->move != Player::FOLD){
            qDebug() << "SHOWING CARDS FOR PLAYER " << player->getId();
            qDebug() << "Card1: " << player->card1.id();
            qDebug() << "Card2: " << player->card2.id();

            player->displayCards();
            player->displayChips();
        }
        else{
            qDebug() << "IGNORING PLAYER " << player->id;
        }
    }
}

void Game::hideSeatButtons(){
    for(auto &seat: seats){
        seat.buttonSitInSeat->hide();
    }
}

void Game::showBetMenu(){
    ui->buttonCall->hide();
    ui->buttonFold->hide();
    ui->buttonBet->hide();

    ui->buttonSubmit->raise();
    ui->buttonSubmit->show();

    ui->buttonCancel->raise();
    ui->buttonCancel->show();

    ui->horizontalBetSlider->raise();
    ui->horizontalBetSlider->show();

    ui->inputBet->raise();
    ui->inputBet->show();

    ui->buttonIncrementBet->raise();
    ui->buttonDecrementBet->raise();
    ui->buttonIncrementBet->show();
    ui->buttonDecrementBet->show();
}

void Game::hideBetMenu() {
    ui->labelButtonHolder->hide();
    ui->labelCardHolder->hide();

    ui->buttonBet->hide();
    ui->buttonCall->hide();
    ui->buttonFold->hide();
    ui->buttonCancel->hide();
    ui->buttonSubmit->hide();
    ui->inputBet->hide();
    ui->horizontalBetSlider->hide();
}

void Game::startRoundTimer() {
    new_game_timer.start(1000);
}

void Game::setBackground() {

    ui->labelBottomLeft->hide();
    ui->labelBottomRight->hide();

    ui->buttonBet->hide();
    ui->buttonCall->hide();
    ui->buttonCancel->hide();
    ui->buttonFold->hide();
    ui->buttonSubmit->hide();
    ui->horizontalBetSlider->hide();
    ui->inputBet->hide();
    ui->buttonIncrementBet->hide();
    ui->buttonDecrementBet->hide();

    ui->labelButtonHolder->hide();
    ui->labelCardHolder->hide();
    ui->labelPlayerCard1->hide();
    ui->labelPlayerCard2->hide();

    ui->labelCommunityCard1->hide();
    ui->labelCommunityCard2->hide();
    ui->labelCommunityCard3->hide();
    ui->labelCommunityCard4->hide();
    ui->labelCommunityCard5->hide();

    ui->placeholder0->hide();
    ui->placeholder6->hide();
    ui->placeholder5->hide();
    ui->placeholder7->hide();
    ui->placeholder4->hide();
    ui->placeholder3->hide();
    ui->placeholder2->hide();
    ui->placeholder1->hide();

    ui->player0_blind->hide();
    ui->player1_blind->hide();
    ui->player2_blind->hide();
    ui->player3_blind->hide();
    ui->player4_blind->hide();
    ui->player5_blind->hide();
    ui->player6_blind->hide();
    ui->player7_blind->hide();

    ui->labelPotHolder->hide();
    ui->labelPot->setText("");
    ui->label->hide();

}

void Game::positionSeats(){
    QPalette whiteText;
    whiteText.setColor(QPalette::WindowText, Qt::white);

    QFont labelFont;
    labelFont.setPixelSize(24);

    ui->labelBottomLeft->setPalette(whiteText);
    ui->labelBottomLeft->setFont(labelFont);

    ui->labelBottomRight->setPalette(whiteText);
    ui->labelBottomRight->setFont(labelFont);

    QFont font;
    font.setPixelSize(20);

    //Seat 0
    {
        seats[0].buttonSitInSeat = ui->buttonSitInSeat0;
        seats[0].placeholder = ui->placeholder0;
        seats[0].playerName = ui->Player0Name;
        seats[0].chipCount = ui->Player0ChipCount;
        seats[0].labelCard1 = ui->Player0Card1;
        seats[0].labelCard2 = ui->Player0Card2;
        seats[0].timer = new CountdownTimer(ui->centralwidget);
        seats[0].timer->setGeometry(735, 25, 150, 150);
        seats[0].blind_chip = ui->player0_blind;

        seats[0].chipStacks[0] = ui->Player0Stack0;
        seats[0].chipStacks[1] = ui->Player0Stack1;
        seats[0].chipStacks[2] = ui->Player0Stack2;
        seats[0].chipStacks[3] = ui->Player0Stack3;
        seats[0].chipStacks[4] = ui->Player0Stack4;
        seats[0].chipStacks[5] = ui->Player0Stack5;
        seats[0].chipStacks[6] = ui->Player0Stack6;
        seats[0].chipStacks[7] = ui->Player0Stack7;
    }
    //Seat 1
    {
        seats[1].buttonSitInSeat = ui->buttonSitInSeat1;
        seats[1].placeholder = ui->placeholder1;
        seats[1].playerName = ui->Player1Name;
        seats[1].chipCount = ui->Player1ChipCount;
        seats[1].labelCard1 = ui->Player1Card1;
        seats[1].labelCard2 = ui->Player1Card2;
        seats[1].timer = new CountdownTimer(ui->centralwidget);
        seats[1].timer->setGeometry(975, 175, 150, 150);
        seats[1].timer->hide();
        seats[1].timer->setProgress(500);
        seats[1].blind_chip = ui->player1_blind;

        seats[1].chipStacks[0] = ui->Player1Stack0;
        seats[1].chipStacks[1] = ui->Player1Stack1;
        seats[1].chipStacks[2] = ui->Player1Stack2;
        seats[1].chipStacks[3] = ui->Player1Stack3;
        seats[1].chipStacks[4] = ui->Player1Stack4;
        seats[1].chipStacks[5] = ui->Player1Stack5;
        seats[1].chipStacks[6] = ui->Player1Stack6;
        seats[1].chipStacks[7] = ui->Player1Stack7;
    }
    //Seat 2
    {
        seats[2].buttonSitInSeat = ui->buttonSitInSeat2;
        seats[2].placeholder = ui->placeholder2;
        seats[2].playerName = ui->Player2Name;
        seats[2].chipCount = ui->Player2ChipCount;
        seats[2].labelCard1 = ui->Player2Card1;
        seats[2].labelCard2 = ui->Player2Card2;
        seats[2].timer = new CountdownTimer(ui->centralwidget);
        seats[2].timer->setGeometry(945, 365, 150, 150);
        seats[2].timer->hide();
        seats[2].blind_chip = ui->player2_blind;

        seats[2].chipStacks[0] = ui->Player2Stack0;
        seats[2].chipStacks[1] = ui->Player2Stack1;
        seats[2].chipStacks[2] = ui->Player2Stack2;
        seats[2].chipStacks[3] = ui->Player2Stack3;
        seats[2].chipStacks[4] = ui->Player2Stack4;
        seats[2].chipStacks[5] = ui->Player2Stack5;
        seats[2].chipStacks[6] = ui->Player2Stack6;
        seats[2].chipStacks[7] = ui->Player2Stack7;
    }
    //Seat 3
    {
        seats[3].buttonSitInSeat = ui->buttonSitInSeat3;
        seats[3].placeholder = ui->placeholder3;
        seats[3].playerName = ui->Player3Name;
        seats[3].chipCount = ui->Player3ChipCount;
        seats[3].labelCard1 = ui->Player3Card1;
        seats[3].labelCard2 = ui->Player3Card2;
        seats[3].timer = new CountdownTimer(ui->centralwidget);
        seats[3].timer->setGeometry(675, 455, 150, 150);
        seats[3].timer->hide();
        seats[3].blind_chip = ui->player3_blind;

        seats[3].chipStacks[0] = ui->Player3Stack0;
        seats[3].chipStacks[1] = ui->Player3Stack1;
        seats[3].chipStacks[2] = ui->Player3Stack2;
        seats[3].chipStacks[3] = ui->Player3Stack3;
        seats[3].chipStacks[4] = ui->Player3Stack4;
        seats[3].chipStacks[5] = ui->Player3Stack5;
        seats[3].chipStacks[6] = ui->Player3Stack6;
        seats[3].chipStacks[7] = ui->Player3Stack7;
    }
    //Seat 4
    {
        seats[4].buttonSitInSeat = ui->buttonSitInSeat4;
        seats[4].placeholder = ui->placeholder4;
        seats[4].playerName = ui->Player4Name;
        seats[4].chipCount = ui->Player4ChipCount;
        seats[4].labelCard1 = ui->Player4Card1;
        seats[4].labelCard2 = ui->Player4Card2;
        seats[4].timer = new CountdownTimer(ui->centralwidget);
        seats[4].timer->setGeometry(478, 455, 150, 150);
        seats[4].timer->hide();
        seats[4].blind_chip = ui->player4_blind;

        seats[4].chipStacks[0] = ui->Player4Stack0;
        seats[4].chipStacks[1] = ui->Player4Stack1;
        seats[4].chipStacks[2] = ui->Player4Stack2;
        seats[4].chipStacks[3] = ui->Player4Stack3;
        seats[4].chipStacks[4] = ui->Player4Stack4;
        seats[4].chipStacks[5] = ui->Player4Stack5;
        seats[4].chipStacks[6] = ui->Player4Stack6;
        seats[4].chipStacks[7] = ui->Player4Stack7;
    }

    //Seat 5
    {
        seats[5].buttonSitInSeat = ui->buttonSitInSeat5;
        seats[5].placeholder = ui->placeholder5;
        seats[5].playerName = ui->Player5Name;
        seats[5].chipCount = ui->Player5ChipCount;
        seats[5].labelCard1 = ui->Player5Card1;
        seats[5].labelCard2 = ui->Player5Card2;
        seats[5].timer = new CountdownTimer(ui->centralwidget);
        seats[5].timer->setGeometry(208, 365, 150, 150);
        seats[5].timer->hide();
        seats[5].blind_chip = ui->player5_blind;

        seats[5].chipStacks[0] = ui->Player5Stack0;
        seats[5].chipStacks[1] = ui->Player5Stack1;
        seats[5].chipStacks[2] = ui->Player5Stack2;
        seats[5].chipStacks[3] = ui->Player5Stack3;
        seats[5].chipStacks[4] = ui->Player5Stack4;
        seats[5].chipStacks[5] = ui->Player5Stack5;
        seats[5].chipStacks[6] = ui->Player5Stack6;
        seats[5].chipStacks[7] = ui->Player5Stack7;
    }

    //Seat 6
    {
        seats[6].buttonSitInSeat = ui->buttonSitInSeat6;
        seats[6].placeholder = ui->placeholder6;
        seats[6].playerName = ui->Player6Name;
        seats[6].chipCount = ui->Player6ChipCount;
        seats[6].labelCard1 = ui->Player6Card1;
        seats[6].labelCard2 = ui->Player6Card2;
        seats[6].timer = new CountdownTimer(ui->centralwidget);
        seats[6].timer->setGeometry(188, 165, 150, 150);
        seats[6].timer->hide();
        seats[6].blind_chip = ui->player6_blind;

        seats[6].chipStacks[0] = ui->Player6Stack0;
        seats[6].chipStacks[1] = ui->Player6Stack1;
        seats[6].chipStacks[2] = ui->Player6Stack2;
        seats[6].chipStacks[3] = ui->Player6Stack3;
        seats[6].chipStacks[4] = ui->Player6Stack4;
        seats[6].chipStacks[5] = ui->Player6Stack5;
        seats[6].chipStacks[6] = ui->Player6Stack6;
        seats[6].chipStacks[7] = ui->Player6Stack7;
    }
    //Seat 7
    {
        seats[7].buttonSitInSeat = ui->buttonSitInSeat7;
        seats[7].placeholder = ui->placeholder7;
        seats[7].playerName = ui->Player7Name;
        seats[7].chipCount = ui->Player7ChipCount;
        seats[7].labelCard1 = ui->Player7Card1;
        seats[7].labelCard2 = ui->Player7Card2;
        seats[7].timer = new CountdownTimer(ui->centralwidget);
        seats[7].timer->setGeometry(398, 25, 150, 150);
        seats[7].timer->hide();
        seats[7].blind_chip = ui->player7_blind;

        seats[7].chipStacks[0] = ui->Player7Stack0;
        seats[7].chipStacks[1] = ui->Player7Stack1;
        seats[7].chipStacks[2] = ui->Player7Stack2;
        seats[7].chipStacks[3] = ui->Player7Stack3;
        seats[7].chipStacks[4] = ui->Player7Stack4;
        seats[7].chipStacks[5] = ui->Player7Stack5;
        seats[7].chipStacks[6] = ui->Player7Stack6;
        seats[7].chipStacks[7] = ui->Player7Stack7;
    }

    //community.card1.label = ui->labelCommunityCard1;
    //community.card2.label = ui->labelCommunityCard2;
    //community.card3.label = ui->labelCommunityCard3;
    //community.card4.label = ui->labelCommunityCard4;
    //community.card5.label = ui->labelCommunityCard5;

    for (auto &seat : seats) {
        seat.playerName->hide();
        seat.chipCount->hide();
        seat.labelCard1->hide();
        seat.labelCard2->hide();

        for (auto &stack : seat.chipStacks) {
            stack->hide();
        }
    }

    for(int i = 0; i < 8; i++){
        connect(seats[i].buttonSitInSeat, &QPushButton::clicked, this, std::bind(&Game::chooseSeat, this, i));
    }
}


Game::~Game()
{
    delete ui;
}
