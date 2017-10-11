#include "packet.h"
#include <QByteArray>
#include <QString>
#include <string>

QByteArray Packet::package(){
    int packet_type = int(type);
    int packet_opcode = int(opcode);

    QString str_code = QString::number(packet_opcode);
    QString str_type = QString::number(packet_type);

    QString s = str_type.leftJustified(DEST_SIZE, '\0') + str_code.leftJustified(TYPE_SIZE, '\0') + payload.leftJustified(PAYLOAD_SIZE, '\0');

    arr.append(s);
    return arr;
}

void Packet::unpack(){
    QString temp;

    for(int i = 0; i < DEST_SIZE; i++){
        if(arr[i] == '\0') break;
        temp += arr[i];
    }

    type = Packet::Type(temp.toInt());
    qDebug() << "Packet Type: " << type;

    temp.clear();
    for(int i = DEST_SIZE; i < DEST_SIZE + TYPE_SIZE; i++){
        if(arr[i] == '\0') break;
        temp += arr[i];
    }

    opcode = Opcode(temp.toInt());

    for(int i = DEST_SIZE + TYPE_SIZE; i < PACKET_SIZE; i++){
        if(arr[i] == '\0') break;
        payload += arr[i];
    }

    if(this->type == Packet::Type::JSON){
        qDebug() << "Begin json payload.";

        json = QJsonDocument(QJsonDocument::fromJson(payload.toUtf8())).object();

        qDebug() << "username: " << json["username"].toString();
        qDebug() << "password: " << json["password"].toString();
        qDebug() << "email: " << json["email"].toString();
    }
}

void Packet::clear(){
    dest.clear();
    opcode = INCOMPLETE;
    payload.clear();
}
