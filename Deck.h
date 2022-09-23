#pragma once
#include <string>
#include <vector>

#include "Card.h"
#include "Player.h"

class Deck
{
public:
	//Deck();
private:
	std::vector<Card> _deck; // creat the deck of cards (52 cards)
	//std::vector<Player> _playersNames;

public:
	//std::vector<Card> GetDeck();
	//void CreatePlayers();
	std::vector<Player> GetPlayersNames();
	void AddCardsToDeck();
	void ShuffleDeck();
	Card GiveACard(); // method which return a specific card
	void DistributeCards(Deck &deck, std::vector<Player> &playersNames);
	void ShowPlayersHands(std::vector<Player> &playersNames);
	void ClearDeck();
};
