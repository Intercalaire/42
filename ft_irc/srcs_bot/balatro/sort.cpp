
#include <Table.hpp>
#include <algorithm>

bool	compareValue(const PlayingCard &a, const PlayingCard &b)
{
	int	ax = a.getValue();
	int	bx = b.getValue();

	if (ax == 1)
		ax = 20;
	if (bx == 1)
		bx = 20;
	return (ax > bx);
}

bool	compareColor(const PlayingCard &a, const PlayingCard &b)
{
	return (a.getColor() > b.getColor());
}

std::vector<PlayingCard>	sortValue(std::vector<PlayingCard> cards)
{
	std::sort(cards.begin(), cards.end(), compareValue);
	return (cards);
}
