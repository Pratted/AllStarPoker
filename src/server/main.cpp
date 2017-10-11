#include <QCoreApplication>
#include <iostream>

#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    if(!server.start()){
        std::cerr << "Server failed to start.\n";
    }

    return a.exec();
}
