#pragma once

#include "Card.h"
#include "Pattern.h"

#include <vector>

class Player
{
public:
	Player(std::string name);

private:
	std::string _name;
	std::vector<Card> _hand;

public:
	// Methods which control the players and their hand.
	std::string GetName();
	void GetACard(const Card card);
	void SortHand();
	void PlayerHand();
	void ClearHand();

	// Methods to count the values and suits in players hands.
	int CountValue(CardValue cardValue);
	int CountSuit(CardSuit cardSuit);

	// Methods which test any possible patterns.
	bool IsPair(Pattern& pattern);
	bool IsTwoPair(Pattern& pattern);
	bool IsThreeOfAKind(Pattern& pattern);
	bool IsStraight(Pattern& pattern);
	bool IsFlush(Pattern& pattern);
	bool IsFullHouse(Pattern& pattern);
	bool IsFourOfAKind(Pattern& pattern);
	bool IsStraightFlush(Pattern& pattern);
	bool IsRoyalFlush(Pattern& pattern);

	// Methods which return and print the players patterns.
	Pattern TestPattern();
	void ShowPattern(Pattern& pattern);
};