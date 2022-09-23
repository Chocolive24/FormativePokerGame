#include "Card.h"

Card::Card(enum CardSuit cardSuit, enum CardValue cardValue)
{
	CardSuit = cardSuit;
	CardValue = cardValue;
}

std::string Card::getCardSuitAsString(enum CardSuit cardSuit)
{
	switch(cardSuit)
	{
		case CardSuit::CLUBS:
			return "Clubs";
		case CardSuit::HEARTS:
			return "Hearts";
		case CardSuit::SPADES:
			return "Spades";
		case CardSuit::DIAMONDS:
			return "Diamonds";
		case CardSuit::SUITEND:
            return "Unknown";
        default:
            return "Unknown";
	}
}

std::string Card::getCardValueAsString(enum CardValue cardValue)
{
    switch (cardValue)
    {
    case CardValue::TWO:
        return "2";
    case CardValue::THREE:
        return "3";
    case CardValue::FOUR:
        return "4";
    case CardValue::FIVE:
        return "5";
    case CardValue::SIX:
        return "6";
    case CardValue::SEVEN:
        return "7";
    case CardValue::EIGHT:
        return "8";
    case CardValue::NINE:
        return "9";
    case CardValue::TEN:
        return "10";
    case CardValue::JACK:
        return "Jack";
    case CardValue::QUEEN:
        return "Queen";
    case CardValue::KING:
        return "King";
    case CardValue::ACE:
        return "Ace";
    case CardValue::VALUEEND:
        return "Unknown";
    default:
        return "Unknown";
    }
}

 std::string Card::ToString()
{
	return getCardValueAsString(CardValue)  + " of " + getCardSuitAsString(CardSuit);
}
