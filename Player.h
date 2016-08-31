#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include <vector>
#include <iostream>
#include "Card.h"

class Player
{
public:
	virtual ~Player() = 0;

	virtual int GetHandStrength() = 0;

	virtual char GetPlayerAction() = 0;

	virtual int GetPlayerBet(int minimum) = 0; //minimum should be provided by Dealer object

	bool operator == (Player &other);

	char* GetName();

	std::vector<CardPtr> GetHand();

	void AddCardToHand(CardPtr card);

	void AddCardsToHand(std::vector<CardPtr> cards);

	int GetCardVal(VALUES val);
	
	bool CheckHasLost();

	void AddChips(int amount);

	void RemoveChips(int amount);

protected:

	int m_chipsLeft;
	bool m_hasLost;
	std::vector<CardPtr> m_hand;
	std::map<VALUES, int> m_cardVals;
	std::map<SUITS, int> m_suitVals;
	char* m_name;


private:

};

#endif