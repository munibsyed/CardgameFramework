#include <iostream>
#include "Deck.h"
#include "BlackjackDealer.h"


void main() {

	Deck deck;
	deck.InitializeDeck();
	std::vector<Player*> players;

	players.push_back(new BlackjackPlayer("Al", 100));
	players.push_back(new BlackjackPlayer("Brad", 100));

	BlackjackDealer dealer(10);
	dealer.PlayGame(deck, players);

	
	
	

	system("pause");
}