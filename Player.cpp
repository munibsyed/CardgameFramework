#include "Player.h"



bool Player::operator==(Player & other)
{
	std::string first = m_name;
	std::string second = other.m_name;

	if (first == second)
	{
		return true;
	}

	return false;
}

char * Player::GetName()
{
	return m_name;
}

std::vector<CardPtr> Player::GetHand()
{
	return m_hand;
}

void Player::AddCardToHand(CardPtr card)
{
	m_hand.push_back(card);
}

void Player::AddCardsToHand(std::vector<CardPtr> cards)
{
	for (int i = 0; i < cards.size(); i++)
	{
		m_hand.push_back(cards[i]);
	}
}

int Player::GetCardVal(VALUES val)
{
	return m_cardVals[val];
}

bool Player::CheckHasLost()
{
	if (m_chipsLeft <= 0) { return true; } return false;
}

void Player::AddChips(int amount)
{
	m_chipsLeft += 1;
}

void Player::RemoveChips(int amount)
{
	m_chipsLeft -= amount;
}