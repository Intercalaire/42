
#include "Card.hpp"

class	SoldCard : public Card {
	public:
		SoldCard();
		~SoldCard() {}

		SoldCard *clone() const;
		std::vector<std::vector<std::string > > getImg() const;
};
