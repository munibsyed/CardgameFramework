#ifndef DEALER_H
#define DEALER_H
#include "Player.h"
#include "Deck.h"
#include <map>
class Dealer
{
public:
	Dealer();
	
	virtual ~Dealer() = 0;

	virtual void PlayGame(Deck &deck, std::vector<Player*> &players) = 0;

	virtual void Deal(Deck &deck, std::vector<Player*> &players) = 0;

	virtual void GetPlayerActions(Deck & deck, std::vector<Player*> &players) = 0;

protected:
	std::map<VALUES, char*> m_valueChar;

private:
	
};

#endif // !DEALER_H