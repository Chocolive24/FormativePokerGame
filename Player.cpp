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
	if (_hand.size() < 5)
	{
		_hand.emplace_back(Card(card));
	}
}

void Player::SortHand()
{
	struct Xgreater
	{
		bool operator()(Card& lx, Card& rx) const
		{
			return lx.CardValue < rx.CardValue;
		}
	};
	std::sort(_hand.begin(), _hand.end(), Xgreater());
}

int Player::CountValue(CardValue cardValue)
{
	int valueCounted = 0;
	for (auto& card : _hand)
	{
		if (cardValue == card.CardValue)
		{
			valueCounted++;
		}
	}
	return valueCounted;
}

int Player::CountSuit(CardSuit cardSuit)
{
	int suitCounted = 0;
	for (auto& card : _hand)
	{
		if (cardSuit == card.CardSuit)
		{
			suitCounted++;
		}
	}
	return suitCounted;
}

bool Player::IsPair(Pattern& pattern)
{
	for (auto& card : _hand)
	{
		if (CountValue(card.CardValue) == 2)
		{
			pattern._patternValue = PatternValue::Pair;
			pattern._bestCard = card.CardValue;

			for (int i = static_cast<int>(_hand.size()) - 1; i >= 0; i--)
			{
				if(_hand[i].CardValue != pattern._bestCard)
				{
					pattern._secondBestCard = _hand[i].CardValue;
					break;
				}
			}
			return true;
		}
	}
	return false;
}

bool Player::IsTwoPair(Pattern& pattern)
{
	CardValue cardValue = CardValue::VALUEEND;

	for (auto& card : _hand)
	{
		if (CountValue(card.CardValue) == 2 && card.CardValue != cardValue)
		{
			
			if (cardValue == CardValue::VALUEEND)
			{
				pattern._secondBestCard = card.CardValue;
				cardValue = card.CardValue;
			}
			else
			{
				pattern._patternValue = PatternValue::TwoPairs;
				pattern._bestCard = card.CardValue;
				
				return true;
			}

		}
	}
	return false;

	/*Pattern result;

	std::map<CardValue, int> countValues;

	for (auto card : _hand)
	{
		countValues[card.CardValue] = 0;
		int count = std::count_if(_hand.begin(), _hand.end(), CountValues());
		countValues[card.CardValue] = count;
	}*/
}

bool Player::IsThreeOfAKind(Pattern& pattern)
{
	for (auto& card : _hand)
	{
		if (CountValue(card.CardValue) == 3)
		{
			pattern._patternValue = PatternValue::ThreeOfAKind;
			pattern._bestCard = card.CardValue;
			return true;
		}
	}
	return false;
}

bool Player::IsStraight(Pattern& pattern)
{
	bool straight = false;
	for (int i = 0; i < 4; i++)
	{
		if (static_cast<int>(_hand[i].CardValue) == static_cast<int>(_hand[i + 1].CardValue ) - 1)
		{
			pattern._patternValue = PatternValue::Straight;
			pattern._bestCard = _hand[_hand.size() - 1].CardValue;
			straight = true;
		}
		else
		{
			return false;
		}
	}
	return straight;
}

bool Player::IsFlush(Pattern& pattern)
{
	for (auto& card : _hand)
	{
		if (CountSuit(card.CardSuit) == 5)
		{
			pattern._patternValue = PatternValue::Flush;
			pattern._bestCard = _hand[_hand.size() - 1].CardValue;
			return true;
		}
	}
	return false;
}


bool Player::IsFullHouse(Pattern& pattern)
{
	Pattern one;
	Pattern two;

	if (IsThreeOfAKind(one) && IsPair(two))
	{
		pattern._patternValue = PatternValue::FullHouse;
		pattern._bestCard = one._bestCard;
		return true;
	}
	return false;
}

bool Player::IsFourOfAKind(Pattern& pattern)
{
	for (auto& card : _hand)
	{
		if (CountValue(card.CardValue) == 4)
		{
			pattern._patternValue = PatternValue::FourOfAKind;
			pattern._bestCard = card.CardValue;
			return true;
		}
	}
	return false;
}

bool Player::IsStraightFlush(Pattern& pattern)
{
	Pattern one;
	Pattern two;
	if (IsStraight(one) && IsFlush(two))
	{
		pattern._patternValue = PatternValue::StraightFlush;
		pattern._bestCard = two._bestCard;
		return true;
	}

	return false;
}


bool Player::IsRoyalFlush(Pattern& pattern)
{
	Pattern one;
	Pattern two;
	if (static_cast<int>(_hand[0].CardValue) == 10)
	{
		if (IsStraight(one) && IsFlush(two))
		{
			pattern._patternValue = PatternValue::RoyalFlush;
			pattern._bestCard = two._bestCard;
			return true;
		}
	}
	return false;
}


Pattern Player::TestPattern()  //  afficher le type de pair etc. (pair de Jack)... -> public: _hand -> std::cout << _hand[]
{
	Pattern result;

	if (IsRoyalFlush(result))
	{
		return result;
	}
	
	if (IsStraightFlush(result))
	{
		return result;
	}
	
	if (IsFourOfAKind(result))
	{
		return result;
	}
	
	if (IsFullHouse(result))
	{
		return result;
	}
	
	if (IsFlush(result))
	{
		return result;
	}

	if (IsStraight(result))
	{
		return result;
	}

	if (IsThreeOfAKind(result))
	{
		return result;
	}

	if (IsTwoPair(result))
	{
		return result;
	}

	if(IsPair(result))
	{
		return result;
	}

	result._patternValue = PatternValue::HighCard;
	result._bestCard = _hand[_hand.size() -1].CardValue;
	result._secondBestCard = _hand[_hand.size() - 2].CardValue;
	
	return result;

}

void Player::ShowPattern(Pattern& pattern)
{
	std::cout << pattern.GetPattern() << " of " << Card::getCardValueAsString(pattern._bestCard) << std::endl;
}

void Player::ClearHand()
{
	_hand.clear();
}

void Player::PlayerHand()
{
	for (auto card : _hand)
	{
		//std::cout << _name << " Hand : / ";
		std::cout << card.ToString() << std::endl;
	}
}

