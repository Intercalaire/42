
#include "Player.hpp"
#include "color.hpp"
#include "PlanetCard.hpp"
#include <iostream>


Player::Player()
{
	std::vector<uint32_t> a;

	_money = 4;
	_handSize = 8;
	_handMax = 4;
	_discardMax = 4;
	_deck = defaultDeck();
	a.push_back(5); a.push_back(1); _pokerHandScore.push_back(a); a.clear();
	a.push_back(10); a.push_back(2); _pokerHandScore.push_back(a); a.clear();
	a.push_back(20); a.push_back(2); _pokerHandScore.push_back(a); a.clear();
	a.push_back(30); a.push_back(3); _pokerHandScore.push_back(a); a.clear();
	a.push_back(30); a.push_back(4); _pokerHandScore.push_back(a); a.clear();
	a.push_back(35); a.push_back(4); _pokerHandScore.push_back(a); a.clear();
	a.push_back(40); a.push_back(4); _pokerHandScore.push_back(a); a.clear();
	a.push_back(60); a.push_back(7); _pokerHandScore.push_back(a); a.clear();
	a.push_back(100); a.push_back(8); _pokerHandScore.push_back(a); a.clear();
	std::cout << YELLOW << "[System]: Player class created" << RESET << std::endl;
}

Player::~Player()
{
	std::cout << YELLOW << "[System]: Player class deleted" << RESET << std::endl;
}

uint32_t	Player::getMoney() const {
	return (_money);
}

uint8_t		Player::getHandSize() const {
	return (_handSize);
}

uint8_t		Player::getHandMax() const {
	return (_handMax);
}

uint8_t		Player::getDiscardMax() const {
	return (_discardMax);
}

std::vector<PlayingCard>	Player::getDeck() const {
	return (_deck);
}

std::vector<Card *>	Player::getConsomCard() const {
	return(_consomCard);
}

std::vector<std::vector<uint32_t > >	Player::getPokerHandScore() const {
	return (_pokerHandScore);
}

void	Player::addMoney(int32_t nb) {
	_money += nb;
}

void	Player::setMoney(int32_t nb) {
	_money = nb;
}


void	Player::addConsomCard(Card *card) {
	_consomCard.push_back(card);
}

void	Player::addPokerHandLevel(pokerHand ph, uint32_t token, uint32_t mult)
{
	_pokerHandScore[ph][0] += token;
	_pokerHandScore[ph][1] += mult;
	std::cerr << "ind "<< ph << std::endl;
}

void	Player::eraseConsomCard(uint32_t ind)
{
	if (ind >= _consomCard.size())
		return;
	_consomCard.erase(_consomCard.begin() + ind);
}

void Player::clearConsom() {
    for (size_t i = 0; i < _consomCard.size(); ++i) {
        delete _consomCard[i];
    }
    _consomCard.clear();
}

void	Player::free() {
	this->clearConsom();
}
