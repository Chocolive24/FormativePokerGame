#pragma once

#include "Card.h"
#include "Player.h"

#include <vector>

class Deck
{
private:
	std::vector<Card> _deck; 

public:
	// Methods link to the "dealer" part of the deck class
	void AddCardsToDeck();
	void ShuffleDeck();

	// Methods link to the "master of the game" part of the deck class
	static void CreatePlayers(std::vector<Player>& playersNames);
	Card GiveACard(); 
	void DistributeCards(Deck &deck, std::vector<Player> &playersNames);
	void ShowPlayersHands(std::vector<Player> &playersNames);
	void DetermineTheWinner(std::vector<Player> &playersNames);
	void PlayAgain(Deck &deck, std::vector<Player> &playersNames, bool &game);
	void ClearDeck();
};