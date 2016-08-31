#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H

#include "Dealer.h"
#include "BlackjackPlayer.h"
#include <map>

class BlackjackDealer : public Dealer
{
public:
	BlackjackDealer();
	BlackjackDealer(int minimumBet) : Dealer()
	{
		m_minimumBet = minimumBet;
	}

	~BlackjackDealer();

	void PlayGame(Deck &deck, std::vector<Player*> &players);

	void Deal(Deck &deck, std::vector<Player*> &players);

	int GetOwnHandStrength(std::vector<Player*>& players);

	void GetPlayerBets(std::vector<Player*> &players);

	void GetPlayerActions(Deck & deck, std::vector<Player*> &players);

	void Pay(Deck &deck, std::vector<Player*> &players);

private:
	int m_totalChips;
	int m_minimumBet;
	std::map<Player*, int> m_playerBets;
	std::vector<CardPtr> m_cards;
	int m_strength;
};

#endif
