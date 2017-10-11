#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTcpSocket>
#include <QMessageBox>

#include "../packet.h"
#include "ui_account.h"
#include "ui_loginwindow.h"
#include "account.h"
#include "client.h"

Account::Account(Client* client, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Account)
{
    ui->setupUi(this);
    connect(ui->line_username, &QLineEdit::editingFinished, this, &Account::validateUsername);
    connect(ui->line_password, &QLineEdit::editingFinished, this, &Account::validatePassword);
    connect(ui->line_password2, &QLineEdit::editingFinished, this, &Account::validatePassword2);
    connect(ui->line_email, &QLineEdit::editingFinished, this, &Account::validateEmail);

    connect(ui->button_cancel, &QPushButton::clicked, this, [this](){this->close(); this->done(QDialog::Rejected);});
    connect(ui->button_create_account, &QPushButton::clicked, this, &Account::create);

    ui->checkbox_email->setEnabled(false);
    ui->checkbox_password->setEnabled(false);
    ui->checkbox_password2->setEnabled(false);
    ui->checkbox_username->setEnabled(false);
}

bool Account::check(QCheckBox* checkbox, bool checked){
    checkbox->setEnabled(true);
    checkbox->setChecked(checked);
    checkbox->setEnabled(false);
}

bool Account::validateUsername(){
    ui->checkbox_username->setText("");
    if(ui->line_username->text().isEmpty()){
        this->check(ui->checkbox_username, false);
        return false;
    }

    //if(usernames.find(ui->line_username->text()) == usernames.end()){
    if(1){
        this->check(ui->checkbox_username);
        return true;
    }
    else{
        ui->checkbox_username->setText("Username already taken.");

        this->check(ui->checkbox_username, false);
        return false;
    }
}

bool Account::validatePassword(){
    ui->checkbox_password->setText("");
    if(ui->line_password->text().isEmpty()){
        this->check(ui->checkbox_password, false);
        return false;
    }

    if(ui->line_password->text().length() > 5){
        this->check(ui->checkbox_password);
        return true;
    }
    else{
        ui->checkbox_password->setText("Password must be at least 5 characters.");
        this->check(ui->checkbox_password, false);
        return false;
    }
}

bool Account::validatePassword2(){
    ui->checkbox_password2->setText("");
    if(ui->line_password2->text().isEmpty()){
        this->check(ui->checkbox_password2, false);
        return false;
    }

    if(ui->line_password->text() == ui->line_password2->text()){
        this->check(ui->checkbox_password2);
        return true;
    }
    else{
        ui->checkbox_password2->setText("Passwords do not match.");

        this->check(ui->checkbox_password2, false);
        return false;
    }
}

bool Account::validateEmail(){
    ui->checkbox_email->setText("");
    if(ui->checkbox_email->text().isEmpty()){
        this->check(ui->checkbox_email, false);
        return false;
    }

    if(ui->line_email->text().contains('@')){
        this->check(ui->checkbox_email);
        return true;
    }
    else{
        ui->checkbox_email->setText("Not a valid email address.");

        this->check(ui->checkbox_email, false);
        return false;
    }
}


void Account::create(){
    if(validateUsername() && validatePassword() && validatePassword2()){
        Packet packet(Packet::Opcode::C2S_CREATE_ACCOUNT, Packet::Type::JSON);
        username = ui->line_username->text();
        password = ui->line_password->text();
        email = ui->line_email->text();

        QJsonObject json;
        json.insert("username", username);
        json.insert("password", password);
        json.insert("email", email);

        QJsonDocument doc(json);
        QString strJson(doc.toJson(QJsonDocument::Compact));

        packet.payload = strJson.leftJustified(240, '\0');
        socket->write(packet.package());
        ui->button_create_account->setEnabled(false);
    }
    else {
        QMessageBox::information(this, QString("Could not create account!"), QString("Please update the incorrect fields."));
    }
}

void Account::login(){
    username = login_ui->line_username->text();
    password = login_ui->line_password->text();

    Packet outgoing(Packet::Opcode::C2S_LOGIN, Packet::Type::JSON);

    QJsonObject json;
    json.insert("username", username);
    json.insert("password", password);

    QJsonDocument doc(json);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    outgoing.payload = strJson; //.leftJustified(240, '\0');
    socket->write(outgoing.package());
}

void Account::promptAccountSuccess(){
    QMessageBox::information(this, QString("Account Created!"), QString("Your account was successfully created. Please login."));
    this->hide();
}



Account::~Account()
{
    delete ui;
}
