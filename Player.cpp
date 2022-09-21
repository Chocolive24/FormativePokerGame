#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>

#include "card.h"
#include "player.h"

Player::Player(std::string name)
{
	this->_name = name;
}

std::string Player::GetName()
{
	return _name;
}



void Player::GetACard(const Card card)
{
	if(_hand.size() < 5)
	{
		_hand.emplace_back(Card(card));
	}
}

void Player::PlayerHand()
{
	for (auto card : _hand)
	{
		//std::cout << _name << " Hand : / ";
		std::cout << card.ToString() << " / ";
	}
}
