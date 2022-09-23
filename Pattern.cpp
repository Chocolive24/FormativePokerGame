#include "Pattern.h"

//Pattern::Pattern(PatternValue patternValue)
//{
//	_patternValue = patternValue;
//}


Pattern::Pattern()
{
	_patternValue = PatternValue::HighCard;
	_bestCard = CardValue::TWO;
	_secondBestCard = CardValue::TWO;
}

std::string Pattern::GetPattern()
{
	switch (_patternValue)
	{
	case PatternValue::HighCard:
		return "High Card";
	case PatternValue::Pair:
		return "Pair";
	case PatternValue::TwoPairs:
		return "Two Pairs";
	case PatternValue::ThreeOfAKind:
		return "Three of a kind";
	case PatternValue::Straight:
		return "Straight";
	case PatternValue::Flush:
		return "Flush";
	case PatternValue::FullHouse:
		return "Full house";
	case PatternValue::FourOfAKind:
		return "Four of a kind";
	case PatternValue::StraightFlush:
		return "Straight flush";
	case PatternValue::RoyalFlush:
		return "Royal flush";
	case PatternValue::PatternEnd:
		return "unknown";
	default:
		return "unknown";
	}
}


