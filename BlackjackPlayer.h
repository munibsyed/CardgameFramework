#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "Player.h"

class BlackjackPlayer : public Player
{
public:
	BlackjackPlayer(char* name, int startingChips);

	int GetHandStrength();

	int GetPlayerBet(int minimum);

	char GetPlayerAction();

	bool GetHasStood();

private:
	bool m_hasStood;
};

#endif