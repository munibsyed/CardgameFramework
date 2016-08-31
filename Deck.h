#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
#include <random>
#include <time.h>
#include "Random.h"

class Deck
{
public:
	Deck();
	~Deck();

	void InitializeDeck(); //add 52 cards

	void Shuffle();

	CardPtr GetRandomCard();

	std::vector<CardPtr> GetNCardsFromTop(int n);

	
protected:

private:
	std::vector<CardPtr> m_cards;

};

#endif // !DECK_H