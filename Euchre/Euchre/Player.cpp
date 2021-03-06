#include "stdafx.h"
#include "Player.h"
#include "Deck.h"
#include "TurnEngine.h"
#include <vector>
#include <algorithm>

Player::Player()
{
	dealer = false;
}


Player::~Player() 
{
	
}

void Player::addToHand(Card &card)
{
	m_hand.push_back(card);
}

void Player::displayHand() {

	if (dealer) {
		std::cout << "(Dealer) ";
	}
	std::cout << m_name << "'s hand: ";
	for (auto &card : m_hand) {
		std::cout << card.getName() << " of " << card.getSuit();

		Card *a = &card;
		Card *b = &m_hand.back();
		if (a != b) { //if not last card in hand
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

void Player::rankHand(Deck &d)
{
	int strongCards = 0;
	for (auto &card : m_hand) {
		if (card.getName() == "Jack" && card.getColor() == d.getTrumpCard().getColor()) { //count jacks of trump color
			strongCards++;

			if (card.getSuit() == d.getTrumpSuit()) { //if the jack is trump suit
				card.setRank(1);
			}
			else { //same color jack, not trump
				card.setRank(2);
			}
			
		}
		else if (card.getSuit() == d.getTrumpCard().getSuit()) { //count other trump cards
			strongCards++;
			
			if (card.getName() == "Ace") { //sets trump card ranks based on value
				card.setRank(3);
			}
			else if (card.getName() == "King") {
				card.setRank(4);
			}
			else if (card.getName() == "Queen") {
				card.setRank(5);
			}
			else if (card.getName() == "Ten") {
				card.setRank(6);
			}
			else if (card.getName() == "Nine") {
				card.setRank(7);
			}
			else if (card.getName() == "Eight") {
				card.setRank(8);
			}
		}
		else {

			if (card.getName() == "Jack") { //sets non-trump ranks
				card.setRank(9);
			}
			else if (card.getName() == "Ace") { 
				card.setRank(10);
			}
			else if (card.getName() == "King") {
				card.setRank(11);
			}
			else if (card.getName() == "Queen") {
				card.setRank(12);
			}
			else if (card.getName() == "Ten") {
				card.setRank(13);
			}
			else if (card.getName() == "Nine") {
				card.setRank(14);
			}
			else if (card.getName() == "Eight") {
				card.setRank(15);
			}
		}
		
		if (strongCards >= 3) { //if hand has at least 3 strong cards
			d.setTrumpSuit(d.getTrumpCard().getSuit()); //set top card to trump suit
			d.setTrumpPicked(true);
			break;
		}

	}
}

void Player::setName(std::string name)
{
	m_name = name;
}

void Player::setDealer(bool d)
{
	dealer = d;
}

bool Player::isDealer() 
{
	return dealer;
}

std::string Player::getName()
{
	return m_name;
}

void Player::playCard(Card &card)
{
	Card *a = &card;
	Card *b;

	for (int i = 0; i < (int)(m_hand.size()); i++) { //for every card in hand
		b = &m_hand[i]; //get card at current index
		if (b == a) { //if card matches
			m_hand.erase(m_hand.begin() + i); //remove it by index
			break;
		}
	}
}

void Player::removeTopCard()
{
	m_hand.erase(m_hand.end()); //is this last index?
}

Card Player::getTrumpCard(Deck &d)
{
	Card trumpCard;
	trumpCard.setRank(100);

	for (auto &card : m_hand) {
		if (card.getSuit() == d.getTrumpSuit() || (card.getColor() == d.getTrumpCard().getColor() && card.getName() == "Jack")) {
			trumpCard = card;
		}
	}
	return trumpCard;
}

bool Player::hasTrumpCard(Deck &d)
{
	if (getTrumpCard(d).getRank() != 100) {
		return true;
	}
	else {
		return false;
	}
}

int Player::getHandTotal() {

	int count = 0;
	for (int i = 0; i < m_hand.size(); i++) {
		count++;
	}

	return count;
}

void Player::addPoint() {
	points++;
}

int Player::getPoints()
{
	return points;
}

void Player::setPoints(int p) {
	points = p;
}
