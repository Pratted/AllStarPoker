#include "mainmenu.h"
#include <QApplication>

#include "client.h"
#include "loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow login;
    Client client(&login);

    login.show();

    return a.exec();
}
