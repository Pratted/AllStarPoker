#include "mainwindow.h"
#include "loginwindow.h"
#include "account.h"
#include "client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    LoginWindow login;
    Client client(&login);

    login.show();


    return a.exec();
}
