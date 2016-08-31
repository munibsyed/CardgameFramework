#ifndef CARD_H
#define CARD_H

#include <memory>

enum SUITS;
enum VALUES;

class Card
{
public:
	Card();
	Card(SUITS suit, VALUES value);
	~Card();

	SUITS GetSuit();

	VALUES GetValue();

	static SUITS suitsArray[4];
	static VALUES valuesArray[13];

protected:

private:
	

	SUITS m_suit;
	VALUES m_value;
	
};

typedef std::shared_ptr<Card> CardPtr;


#endif