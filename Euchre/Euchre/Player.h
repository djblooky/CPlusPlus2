#pragma once
#include <iostream>
#include <vector>
class Card;
class Deck;

class Player
{
private:
	bool dealer;
	int points;
	std::string m_name;
	std::vector<Card> m_hand;
public:
	Player();
	~Player();
	void addToHand(Card &card);
	void displayHand();
	void rankHand(Deck &d);
	void setName(std::string name);
	void setDealer(bool d);
	bool isDealer();
	std::string getName();
	void playCard(Card &card);
	void removeTopCard();
	Card getTrumpCard(Deck &d);
	bool hasTrumpCard(Deck &d);
	int getHandTotal();
	void addPoint();
	int getPoints();
	void setPoints(int p);
};