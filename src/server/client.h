#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

#include "../packet.h"

class Account;

struct Client {
public:
    QTcpSocket* socket = nullptr;
    Account* account = nullptr;
};

#endif
