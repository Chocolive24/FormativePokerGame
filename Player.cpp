#include "Card.h"
#include "Player.h"

#include <iostream>
#include <algorithm>

Player::Player(std::string name)
{
	this->_name = name;
}

std::string Player::GetName()
{
	return _name;
}

// Put the first card of the deck at the end of the player's hand, if the player doesn't have 5 cards.
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

void Player::PlayerHand()
{
	for (auto card : _hand)
	{
		std::cout << card.ToString() << std::endl;
	}
}

void Player::ClearHand()
{
	_hand.clear();
}

// For each card in the player's hand, count how many times it's value reappear.
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

// For each card in the player's hand, count how many times it's suit reappear.
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

// All the next methods check each card of the player's hand and return pattern's hand.
// All methods have the logic of analysing the player's hand after it has been sorted in ascending order.
bool Player::IsPair(Pattern& pattern)
{
	for (auto& card : _hand)
	{
		// If there is 2 times the same card value, then there is a "pair" and the best card is equal to the pair's value.
		if (CountValue(card.CardValue) == 2)
		{
			pattern._patternValue = PatternValue::PAIR;
			pattern._bestCard = card.CardValue;

			// Check the player's hand backward to find the highest card outside the pattern, which is the second best card.
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
		// If there is a "pair" and there is other cards to check, then the second best card is equal to the pair's value
		if (CountValue(card.CardValue) == 2 && card.CardValue != cardValue)
		{
			if (cardValue == CardValue::VALUEEND)
			{
				pattern._secondBestCard = card.CardValue;
				cardValue = card.CardValue;
			}

			// There is a "two pairs", so the best card is equal to the second pair's value.
			else
			{
				pattern._patternValue = PatternValue::TWOPAIRS;
				pattern._bestCard = card.CardValue;
				
				return true;
			}
		}
	}
	return false;
}

bool Player::IsThreeOfAKind(Pattern& pattern)
{
	for (auto& card : _hand)
	{
		// If there is 3 times the same card value, then there is a "three of a kind" and the best card has the pattern's value.
		if (CountValue(card.CardValue) == 3)
		{
			pattern._patternValue = PatternValue::THREEOFAKIND;
			pattern._bestCard = card.CardValue;
			return true;
		}
	}
	return false;
}

bool Player::IsStraight(Pattern& pattern)
{
	bool straight = false;

	// If each card follows the other, then there is a "straight" and the best card is the last one
	for (int i = 0; i < 4; i++)
	{
		if (static_cast<int>(_hand[i].CardValue) == static_cast<int>(_hand[i + 1].CardValue ) - 1)
		{
			pattern._patternValue = PatternValue::STRAIGHT;
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
		// If there is 5 times the same card suit, then there is a "flush" and the best card is the last one.
		if (CountSuit(card.CardSuit) == 5)
		{
			pattern._patternValue = PatternValue::FLUSH;
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

	// If there is a "three of a kind" and a "pair", then there is a "full house".
	// The best card is equal to the value of the "three of a kind".
	if (IsThreeOfAKind(one) && IsPair(two))
	{
		pattern._patternValue = PatternValue::FULLHOUSE;
		pattern._bestCard = one._bestCard;
		return true;
	}
	return false;
}

bool Player::IsFourOfAKind(Pattern& pattern)
{
	for (auto& card : _hand)
	{
		// If there is 4 times the same card value, there is a "four of a kind".
		// the best card is equal to the pattern's value.
		if (CountValue(card.CardValue) == 4)
		{
			pattern._patternValue = PatternValue::FOUROFAKIND;
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
	// If there is a "straight" and a "flush", there is a "straight flush" and the best card is the last one.
	if (IsStraight(one) && IsFlush(two))
	{
		pattern._patternValue = PatternValue::STRAIGHTFLUSH;
		pattern._bestCard = two._bestCard;
		return true;
	}
	return false;
}

bool Player::IsRoyalFlush(Pattern& pattern)
{
	Pattern one;
	Pattern two;
	// If the hand's first card is a 10 and there is a "straight" and a "flush", there is a "royal flush".
	// The best card is the last one 
	if (static_cast<int>(_hand[0].CardValue) == 10)
	{
		if (IsStraight(one) && IsFlush(two))
		{
			pattern._patternValue = PatternValue::ROYALFLUSH;
			pattern._bestCard = two._bestCard;
			return true;
		}
	}
	return false;
}

// This method check all the possible pattern and return the one corresponding to the player's hand.
Pattern Player::TestPattern()  
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

	// If no other pattern was found, then there is a high card.
	// The best card is the last one and the second best card is the second to last one.
	result._patternValue = PatternValue::HIGHCARD;
	result._bestCard = _hand[_hand.size() -1].CardValue;
	result._secondBestCard = _hand[_hand.size() - 2].CardValue;
	
	return result;
}

void Player::ShowPattern(Pattern& pattern)
{
	std::cout << pattern.GetPattern() << " of " << Card::GetCardValueAsString(pattern._bestCard) << std::endl;
}