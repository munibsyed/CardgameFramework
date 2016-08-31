#include "Deck.h"





Deck::Deck()
{
	srand(time(NULL));

}


Deck::~Deck()
{
}

void Deck::InitializeDeck()
{
	for (int suit = 0; suit < 4; suit++)
	{
		for (int val = 0; val < 13; val++)
		{
			m_cards.push_back(CardPtr(new Card(Card::suitsArray[suit], Card::valuesArray[val])));
		}
	}
}

void Deck::Shuffle()
{
	std::vector<CardPtr> newDeck;


	int numCards = m_cards.size();
	for (int i = 0; i < numCards; i++)
	{
		//Random random(0, numCards);
		//int randomIndex = random.GetRand();
		//std::cout << randomIndex << std::endl;
		int randomIndex = rand() % m_cards.size();
		newDeck.push_back(m_cards[randomIndex]);
		m_cards.erase(m_cards.begin() + randomIndex);
	}

	m_cards = newDeck;
}

CardPtr Deck::GetRandomCard()
{
	//Random random(0, m_cards.size());
	//int randomIndex = random.GetRand();

	int randomIndex = rand() % m_cards.size();
	return m_cards[randomIndex];
}

std::vector<CardPtr> Deck::GetNCardsFromTop(int n)
{
	std::vector<CardPtr> result;

	for (int i = 0; i < n; i++)
	{
		result.push_back(m_cards[i]);
		m_cards.erase(m_cards.begin() + i);
	}

	return result;
}