#pragma once

#include <vector>

#include "Card.h"

class Player
{
public:
	Player(std::string name);

private:
	std::string _name;
	std::vector<Card> _hand;

public:
	std::string GetName();
	void GetACard(const Card card);
	void PlayerHand();
	//Card GiveACard();
};