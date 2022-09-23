#include "Pattern.h"

Pattern::Pattern()
{
	_patternValue = PatternValue::HIGHCARD;
	_bestCard = CardValue::TWO;
	_secondBestCard = CardValue::TWO;
}

std::string Pattern::GetPattern()
{
	switch (_patternValue)
	{
	case PatternValue::HIGHCARD:
		return "High Card";
	case PatternValue::PAIR:
		return "Pair";
	case PatternValue::TWOPAIRS:
		return "Two Pairs";
	case PatternValue::THREEOFAKIND:
		return "Three of a kind";
	case PatternValue::STRAIGHT:
		return "Straight";
	case PatternValue::FLUSH:
		return "Flush";
	case PatternValue::FULLHOUSE:
		return "Full house";
	case PatternValue::FOUROFAKIND:
		return "Four of a kind";
	case PatternValue::STRAIGHTFLUSH:
		return "Straight flush";
	case PatternValue::ROYALFLUSH:
		return "Royal flush";
	case PatternValue::PATTERNEND:
		return "unknown";
	default:
		return "unknown";
	}
}