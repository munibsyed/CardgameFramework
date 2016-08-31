#include "Card.h"

enum SUITS
{
	SPADE,
	DIAMOND,
	CLUB,
	HEART
};

enum VALUES
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};



Card::Card()
{
}

Card::Card(SUITS suit, VALUES value) : m_suit(suit), m_value(value)
{
}

Card::~Card()
{
}

SUITS Card::GetSuit()
{
	return m_suit;
}

VALUES Card::GetValue()
{
	return m_value;
}

SUITS Card::suitsArray[4] = { SPADE, DIAMOND, CLUB, HEART};
VALUES Card::valuesArray[13] = {
								TWO,
								THREE,
								FOUR,
								FIVE,
								SIX,
								SEVEN,
								EIGHT,
								NINE,
								TEN,
								JACK,
								QUEEN,
								KING,
								ACE
};