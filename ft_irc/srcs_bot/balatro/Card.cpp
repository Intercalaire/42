
#include "Card.hpp"
#include "bot.hpp"

Card::Card(e_cardtype type, uint32_t price) {
	_type = type;
	_price = price;
}

e_cardtype	Card::getType() const {
	return (_type);
}

uint32_t	Card::getPrice() const {
	return (_price);
}


