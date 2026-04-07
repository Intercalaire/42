
#include "Table.hpp"
#include "Screen.hpp"

void	Table::insertPlayCardinHand()
{
	for (int i = 0; i < (int)_playHand.size(); i ++)
	{
		_hand.push_back(_playHand[i]);	
	}
	_hand = sortValue(_hand);
	(*this).playHandClear();
}

void	deselect(Screen &screen, Table &table, Player &player)
{
	table.insertPlayCardinHand();
	screen.clear();
	table.setTokens(0);
	table.setMult(0);
	screen.putTable(table, player);
}
