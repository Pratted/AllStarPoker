#ifndef PACKET_H
#define PACKET_H

#define PACKET_SIZE 256
#define PAYLOAD_SIZE 240
#define DEST_SIZE 8
#define TYPE_SIZE 8

#include <QString>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

/********************************Packet Format**************************************
  XXXXXXXX      OOOOOOOO        XXXXXXXXXXXX....................................X
  8 byte dest   8 byte opcode                     240 Byte Payload.
  Package() returns a QByteArray of length PACKET_SIZE.
  unpack() places the dest, opcode and payload into their respective members.
 **********************************************************************************/

class Packet
{
public:
    enum Opcode {
        INCOMPLETE,
        S2C_GAME_INFO,
        S2C_ADD_PLAYER,
        C2S_CHOSE_SEAT,
        S2C_CARDSDEALT,
        C2S_MESSAGE,
        S2C_MESSAGE,
        S2C_PLAYER_TURN,
        C2S_PLAYER_MOVE,
        S2C_PLAYER_MOVE,
        S2C_BLINDS,
        S2C_DISCONNECT,
        C2S_DISCONNECT,
        S2C_NEW_GAME,
        S2C_ROUND_COUNTDOWN,
        S2C_REMOVE_PLAYER,
        C2S_MOVE_TYPE,
        C2S_JOIN_GAME,
        C2S_CREATE_ACCOUNT,
        S2C_ACCOUNT_ACCEPTED,
        S2C_ACCOUNT_REJECTED,
        C2S_LOGIN,
        S2C_LOGIN_SUCCESS,
        S2C_LOGIN_FAILURE,
        C2S_PEEK_GAME,
        C2S_KEY,
        C2S_CHOSE_NAME,
        S2C_SEAT_ACCEPT,
        S2C_SEAT_REJECT,
    } opcode;

    enum Type {
        FIXED_WIDTH,
        JSON
    } type;

    Packet(): type(Type::FIXED_WIDTH) {}
    Packet(Opcode code, Type type = FIXED_WIDTH):opcode(code), type(type){}
    Packet(Opcode code, QString contents, Type type = FIXED_WIDTH):opcode(code), payload(contents), type(type){}

    QByteArray package();

    void unpack();
    void clear();

    QString dest;
    QString payload;

    Packet& operator=(QByteArray rhs){this->arr = rhs; return *this; }

    //inline QByteArray& operator >> (QByteArray& str, Packet &packet);

    QByteArray arr;
    QJsonObject json;
};


#endif // PACKET_H
