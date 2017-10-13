#ifndef GLOBALS_H
#define GLOBALS_H

#include <QByteArray>
#include <QCryptographicHash>
#include <QString>

#include <random>

typedef QString JsonString;

namespace crypto {

    //random len digit salt containing chars [0-z]
    inline QString salt(int len = 8){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis('0', 'z');

        QByteArray salt;

        for(int i = 0; i < len; i++){
            salt += dis(rd);
        }

        return salt;
    }

    //SHA1 hash of salt + password base64 encoded.
    inline QString hash(QString salt, QString password){
        password = salt + password;

        QByteArray ba;
        ba.append(password);

        return QCryptographicHash::hash(ba, QCryptographicHash::Algorithm::Sha1).toBase64();
    }
}

inline QString formatWithComma(long val) {
    QString num = QString::number(val);
    int pos = num.length() - 3;

    while (pos > 0) {
        num.insert(pos, ',');
        pos -= 3;
    }
    return num;
}

#endif
