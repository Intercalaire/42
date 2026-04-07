

#pragma once
#include <stdint.h>
#include <vector>
#include <string>

enum	e_edition {
	NO_EDITION,
	FOIL,
	HOLOGRAPHIC,
	POLYCHROME,
	NEGATIVE,
};

enum	e_cardtype {
	SOLD_CARD,
	PLAYING_CARD,
	PLANET_CARD,
	TAROT_CARD,
	JOKER_CARD,
};

class	Card {
	protected:
		e_cardtype	_type;
		uint32_t	_price;
	public:
		Card(e_cardtype type, uint32_t price);
		virtual ~Card() {}

		e_cardtype	getType() const;
		uint32_t	getPrice() const;
		virtual Card *clone() const = 0;
		virtual std::vector<std::vector<std::string > > getImg() const = 0;
};

