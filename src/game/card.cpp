#include "../card.h"

Card::Card(){}
Card::Card(int id):_id(id), _rank(id % 13), _suit(Suit(id / 13)){}
Card::Card(int id, QImage* card_sheet){} //this constructor should never be invoked in project game.

Card::~Card(){}

void Card::showFront(){}
void Card::showBack(){}
void Card::hide(){}
