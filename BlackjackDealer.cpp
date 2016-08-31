#include "BlackjackDealer.h"



BlackjackDealer::BlackjackDealer()
{
}

//BlackjackDealer::BlackjackDealer(int minimumBet) : Dealer()
//{
//	m_minimumBet = minimumBet;
//}


BlackjackDealer::~BlackjackDealer()
{
}

void BlackjackDealer::PlayGame(Deck & deck, std::vector<Player*>& players)
{
	deck.Shuffle();
	m_cards = deck.GetNCardsFromTop(2);

	Deal(deck, players);

	GetPlayerBets(players);

	std::cout << "Dealer's hand has a " << m_valueChar[m_cards[0]->GetValue()] << std::endl;

	GetPlayerActions(deck, players);

	Pay(deck, players);


}

void BlackjackDealer::Deal(Deck & deck, std::vector<Player*>& players)
{
	for (int i = 0; i < players.size(); i++)
	{
		/*Should automatically remove these cards from the deck*/
		players[i]->AddCardsToHand(deck.GetNCardsFromTop(2));


	}
}

int BlackjackDealer::GetOwnHandStrength(std::vector<Player*>& players)
{
	int sum = 0;
	for (int i = 0; i < m_cards.size(); i++)
	{
		sum += players[0]->GetCardVal(m_cards[i]->GetValue());
	}

	if (sum > 21)
	{
		for (int i = 0; i < m_cards.size(); i++)
		{
			if (m_cards[i]->GetValue() == Card::valuesArray[12])
			{
				sum -= 10;
				if (sum <= 21)
				{
					break;
				}
			}
		}

		if (sum > 21)
			sum = 0;

	}
	
	return sum;
}

void BlackjackDealer::GetPlayerBets(std::vector<Player*> &players)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->GetHandStrength() != 0)
		{
			int bet = players[i]->GetPlayerBet(m_minimumBet);
			players[i]->RemoveChips(bet);
			m_playerBets[players[i]] = bet;
		}
	}
}

void BlackjackDealer::GetPlayerActions(Deck & deck, std::vector<Player*> &players)
{
	for (int i = 0; i < players.size(); i++)
	{
		BlackjackPlayer *bPlayer = dynamic_cast<BlackjackPlayer*>(players[i]);

		

		while (players[i]->GetHandStrength() != 0 && bPlayer->GetHasStood() == false)
		{
			std::cout << "_________________________________" << std::endl;
			std::cout << bPlayer->GetName() << "'s current hand is ";

			for (int card = 0; card != players[i]->GetHand().size(); card++)
			{
				std::cout << m_valueChar[players[i]->GetHand()[card]->GetValue()] << " ";
			}

			std::cout << "\n_________________________________" << std::endl;

			char action = players[i]->GetPlayerAction();
			if (action == 'H' || action == 'h')
			{
				/*Print out name of new card*/
				std::vector<CardPtr> newCard = deck.GetNCardsFromTop(1);
				std::cout << "New card is a " << m_valueChar[newCard[0]->GetValue()] << std::endl;

				players[i]->AddCardsToHand(newCard);
			}

		}
	}
}

void BlackjackDealer::Pay(Deck &deck, std::vector<Player*>& players)
{
	int strength = GetOwnHandStrength(players);
	/*Make sure dealer has a chance to hit*/
	std::cout << "Dealer's other card was a " << m_valueChar[m_cards[1]->GetValue()] << std::endl;
	

	while (strength < 17)
	{
		std::cout << "Dealer hits!" << std::endl;
		CardPtr randomCard = deck.GetRandomCard();
		std::cout << "Dealer gets a " << m_valueChar[randomCard->GetValue()] << std::endl;
		m_cards.push_back(randomCard);
		strength = GetOwnHandStrength(players);
	}


	std::cout << "Dealer scored a total of " << strength << std::endl;


	for (int i = 0; i < players.size(); i++)
	{
		if (strength > 21)
		{
			std::cout << "Dealer busted!" << std::endl;
			m_totalChips -= m_playerBets[players[i]];
			std::cout << players[i]->GetName() << " wins " << m_playerBets[players[i]] << "!" << std::endl;

		}

		else if (strength > players[i]->GetHandStrength())
		{
			m_totalChips += m_playerBets[players[i]];
			std::cout << players[i]->GetName() << " loses " << m_playerBets[players[i]] << "!" << std::endl;
		}

		else if (strength < players[i]->GetHandStrength())
		{
			m_totalChips -= m_playerBets[players[i]];
			players[i]->AddChips(m_playerBets[players[i]] * 2);
			std::cout << players[i]->GetName() << " wins " << m_playerBets[players[i]] << "!" << std::endl;

		}

		else //tie
		{
			std::cout << players[i]->GetName() << " tied with the dealer!" << std::endl;
			players[i]->AddChips(m_playerBets[players[i]]);
			std::cout << players[i]->GetName() << " gets his bet of " << m_playerBets[players[i]] << " returned!" << std::endl;
		}
		
	}
}
