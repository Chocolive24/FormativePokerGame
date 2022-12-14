#pragma once

#include <string>

enum class CardSuit  
{
	CLUBS,
	HEARTS,
	SPADES,
	DIAMONDS,

	SUITEND
};

enum class CardValue
{
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 11,
	QUEEN = 12 ,
	KING = 13,
	ACE = 14,

	VALUEEND 
};

class Card
{
public:
	Card(enum CardSuit cardSuit, enum CardValue cardValue);

	CardSuit CardSuit;
	CardValue CardValue;

	static std::string GetCardSuitAsString(enum CardSuit cardSuit);
	static std::string GetCardValueAsString(enum CardValue cardValue);
	std::string ToString();
};