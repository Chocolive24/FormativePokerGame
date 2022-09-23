#pragma once

#include <vector>

#include "Card.h"
#include "Pattern.h"

class Player
{
public:
	Player(std::string name);

	std::vector<Card> _hand;

private:
	std::string _name;
	

public:
	std::string GetName();
	void GetACard(const Card card);
	
	void PlayerHand();
	void SortHand();

	int CountValue(CardValue cardValue);
	int CountSuit(CardSuit cardSuit);

	bool IsPair(Pattern& pattern);
	bool IsTwoPair(Pattern& pattern);
	bool IsThreeOfAKind(Pattern& pattern);
	bool IsStraight(Pattern& pattern);
	bool IsFlush(Pattern& pattern);
	bool IsFullHouse(Pattern& pattern);
	bool IsFourOfAKind(Pattern& pattern);
	bool IsStraightFlush(Pattern& pattern);
	bool IsRoyalFlush(Pattern& pattern);

	void ShowPattern(Pattern& pattern);
	Pattern TestPattern();
	void ClearHand();
	//Card GiveACard();
};
