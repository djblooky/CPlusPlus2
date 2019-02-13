#pragma once
#include <vector>
#include "Card.h"
#include "Player.h"

class Deck
{
private:
	std::vector<Card*> *m_deck; //deck itself heap allocated
	Card *eight, *nine, *ten, *jack, *queen, *king, *ace; //cards in the deck are heap allocated
	bool isShuffled;
public:
	Deck();
	~Deck(); //free all cards and deck vector
	void createDeck(); //makes four of each card type for 24 card deck and adds each one to m_deck vector
	void deal(std::vector<Player> &players); //deals to each player
	void shuffle();

	void deal(Player player, const int numOfCards);
	
};

