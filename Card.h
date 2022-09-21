#pragma once
#include <string>

enum class CardSuit  
{
	CLUBS,
	HEARTS,
	SPADES,
	DIAMONDS,

	SuitEnd, 
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

	ValueEnd, 
};

class Card
{
public: // constructor 1st
	Card(CardSuit cardSuit, CardValue cardValue);

private: // attributs and intern methods 2nd
	CardSuit _cardSuit;
	CardValue _cardValue;

	std::string getCardSuitAsString();
	std::string getCardValueAsString();

public: // extern method 3rd
	std::string ToString();
};