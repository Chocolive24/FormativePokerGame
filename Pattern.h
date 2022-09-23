#pragma once

#include "Card.h"

#include <string>

enum class PatternValue
{
	HIGHCARD,
	PAIR,
	TWOPAIRS,
	THREEOFAKIND,
	STRAIGHT,
	FLUSH,
	FULLHOUSE,
	FOUROFAKIND,
	STRAIGHTFLUSH,
	ROYALFLUSH,

	PATTERNEND
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