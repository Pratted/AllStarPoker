#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QSqlQuery>
#include <QFile>
#include <QDir>
#include <iostream>
#include <QTimer>

#include "game.h"
#include "dealer.h"

Game::Game(QString name, int id, int size, long chip_count, int small_blind, int big_blind, int timer_duration, int port):
    name(name),
    id(id),
    capacity(size),
    chip_start_amount(chip_count),
    small_blind(small_blind),
    big_blind(big_blind),
    timer_duration(timer_duration * 1000), //convert seconds to milliseconds.
    port(port),
    db(QSqlDatabase::addDatabase("QMYSQL")),
    dealer(this),
    player_timer(this),
    next_hand_timer(this),
    QObject(0)
{
    if(this->connectToDatabase()){
        std::cout << "Connected to database!\n";
    }
    else{
        std::cout << "Failed to connect to database\n";
    }

    connect(&next_hand_timer, &QTimer::timeout, this, [&](){std::cout << "READY TO DEAL NEW GAME!\n"; next_hand_timer.stop(); dealer.dealNewHand();});

    //std::cout << "Next Hand Timer: " << next_hand_timer << std::endl;
    //connect(&next_hand_timer, &QTimer::timeout, &dealer, &Dealer::dealNewHand);
    connect(this, &Game::ended, this, [&](){next_hand_timer.start(DEFAULT_COUNTDOWN);});
}


JsonString Game::toJsonString(){
    QJsonObject json;
    //json.insert("max_players", size);
    //json.insert("current_players", long(5));
    json.insert("chip_count", int(chip_start_amount));
    json.insert("id", int(id));
    json.insert("status", int(status));

    QJsonDocument doc(json);
    return QString(doc.toJson(QJsonDocument::Compact));
}

bool Game::start(){
    if(!dealer.listen(QHostAddress::AnyIPv4, port)){
        std::cout << "Failed to open listener on port: " << port << std::endl;
        return false;
    }
    else if(!this->connectToDatabase()){
        std::cout << "Failed to connect tot database\n";
        return false;
    }

    if(!QDir(this->name).exists()) QDir().mkdir(this->name);

    std::cout << "Game successfully started on port: " << port << std::endl;
    return true;
}

bool Game::connectToDatabase(){
    QFile file("db.json");
    if(!file.open(QIODevice::ReadOnly)){
        std::cout << "Failed to open file.\n";
        return false;
    }

    QString contents = file.readAll();
    file.close();

    QJsonObject settings = QJsonDocument::fromJson(contents.toUtf8()).object();

    db.setDatabaseName(settings["database"].toString());
    db.setHostName(settings["hostname"].toString());
    db.setUserName(settings["user"].toString());
    db.setPassword(settings["password"].toString());

    return db.open();
}
