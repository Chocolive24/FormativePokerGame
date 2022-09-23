#pragma once
#include <string>
#include "Card.h"

enum class PatternValue
{
	HighCard,
	Pair,
	TwoPairs,
	ThreeOfAKind,
	Straight,
	Flush,
	FullHouse,
	FourOfAKind,
	StraightFlush,
	RoyalFlush,

	PatternEnd

};

class Pattern
{

public:
	Pattern();

	PatternValue _patternValue;
	CardValue _bestCard;
	CardValue _secondBestCard;

	std::string GetPattern();

};