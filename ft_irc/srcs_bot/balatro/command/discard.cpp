
#include "Table.hpp"
#include "Screen.hpp"

void	discard(Screen &screen, Table &table, Player &player)
{
	table.playHandClear();
	table.removeDiscardRemains();
	table.addCardtoHand(player.getHandSize() - table.getHand().size());
	screen.clear();
	screen.putTable(table, player);

}
