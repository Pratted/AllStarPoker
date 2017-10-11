#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include <QDialog>
#include <QCompleter>
#include <QCheckBox>
#include <QTcpSocket>

#include <set>
#include "packet.h"

namespace Ui {
class Account;
class LoginWindow;
}

class Client;

class Account : public QDialog
{
    Q_OBJECT
    friend class Client;
    friend class Game;
public:
    explicit Account(Client* client, QWidget *parent = 0);

    double winPercentage() { return hands_played / double(hands_won); }

    bool created(){ return true; }
    ~Account();

public slots:
    void create();
    void login();

private:
    Ui::Account *ui;
    Ui::LoginWindow* login_ui;

    QCompleter *completer;
    Client* client;
    QTcpSocket* socket;

    QString display_name;
    QString username;
    QString password;
    QString email;

    int hands_played;
    int hands_won;
    int chip_count;

    std::map<QString, Account*> friends;
    std::set<QString> usernames;

    bool validateUsername();
    bool validatePassword();
    bool validatePassword2();
    bool validateEmail();

    bool check(QCheckBox* checkbox, bool checked = true);

    void promptAccountSuccess();
};

#endif // ACCOUNT_H
