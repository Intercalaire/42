
#include "Table.hpp"
#include "Player.hpp"
#include "Screen.hpp"

void	play(Screen &screen, Table &table, Player &player)
{
	handValue(table, table.getPlayHand(), getPokerHand(table.getPlayHand()));
	table.playHandClear();
	table.calculateUserScore();
	table.setMult(0);
	table.setTokens(0);
	table.removeHandRemains();
	table.addCardtoHand(player.getHandSize() - table.getHand().size());
	screen.clear();
	screen.putTable(table, player);
}
