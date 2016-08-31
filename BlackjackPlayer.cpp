#include "BlackjackPlayer.h"

BlackjackPlayer::BlackjackPlayer(char* name, int startingChips)
{
	m_name = name;
	m_chipsLeft = startingChips;
	m_hasLost = false;
	m_hasStood = false;
	
	m_cardVals[Card::valuesArray[0]] = 2;
	m_cardVals[Card::valuesArray[1]] = 3;
	m_cardVals[Card::valuesArray[2]] = 4;
	m_cardVals[Card::valuesArray[3]] = 5;
	m_cardVals[Card::valuesArray[4]] = 6;
	m_cardVals[Card::valuesArray[5]] = 7;
	m_cardVals[Card::valuesArray[6]] = 8;
	m_cardVals[Card::valuesArray[7]] = 9;
	m_cardVals[Card::valuesArray[8]] = 10;
	m_cardVals[Card::valuesArray[9]] = 10;
	m_cardVals[Card::valuesArray[10]] = 10;
	m_cardVals[Card::valuesArray[11]] = 10;
	m_cardVals[Card::valuesArray[12]] = 11;

	m_suitVals[Card::suitsArray[0]] = 0;
	m_suitVals[Card::suitsArray[1]] = 1;
	m_suitVals[Card::suitsArray[2]] = 2;
	m_suitVals[Card::suitsArray[3]] = 3;



}
int BlackjackPlayer::GetHandStrength()
{
	int sum = 0;
	for (int i = 0; i < m_hand.size(); i++)
	{
		sum += m_cardVals[m_hand[i]->GetValue()];
	}

	if (sum > 21)
	{
		for (int i = 0; i < m_hand.size(); i++)
		{
			if (m_hand[i]->GetValue() == Card::valuesArray[12])
			{
				sum -= 10;
				if (sum <= 21)
				{
					break;
				}
			}
		}

		if (sum > 21)
		{
			std::cout << m_name << " has busted!" << std::endl;
			sum = 0;
		}

	}
	return sum;
}
int BlackjackPlayer::GetPlayerBet(int minimum)
{
	std::cout << "Name: " << m_name << " | " << "Chips left: " << m_chipsLeft << std::endl;
	std::cout << "_____________________" << std::endl;
	std::cout << "Minimum bet for this round is " << minimum << std::endl;
	std::cout << "What is your bet for this round? " << std::endl;

	int bet;
	bool valid = false;
	while (valid == false)
	{
		
			std::cin >> bet;
			
			if (std::cin.fail())
			{
				std::cout << "Not an integer. Try again." << std::endl;
				std::cin.clear();
			}


			else
			{
				if (bet < minimum)
					std::cout << "Bet is too low. Minimum is " << minimum << "." << std::endl;
				else if (bet > m_chipsLeft)
					std::cout << "Bet is too high." << std::endl;
				else
					valid = true;
			}
			
		
	}

	return bet;
	
}
char BlackjackPlayer::GetPlayerAction()
{
	std::cout << "Your hand's value is " << GetHandStrength() << ". Choose your next action: " << std::endl;
	std::cout << "(H) - Hit" << std::endl;
	std::cout << "(S) - Stand" << std::endl;
	char action;
	bool valid = false;

	while (!valid)
	{
		std::cin >> action;

		if (action == 'H' || action == 'S' || action == 'h' || action == 's')
			valid = true;
		else
		{
			std::cout << "That does not appear to be a valid action. Try again." << std::endl;
		}
	}

	if (action == 'S' || action == 's')
		m_hasStood = true;

	return action;

}

bool BlackjackPlayer::GetHasStood()
{
	return m_hasStood;
}


Player::~Player()
{
}