#include "Deck.h"
#include <vector>
#include "Card.h"
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>


/*Deck::Deck()
{
	this->_deck;
}*/

/*
std::vector<Card> Deck::GetDeck()
{
    return _deck;
}
*/

//void Deck::CreatePlayers()
//{
//    int numberOfPlayers = 0;
//    std::cout << "Tap the number of players up to 4 : ";
//    std::cin >> numberOfPlayers;
//    std::string name;
//
//    for (int nbrPlayersIdx = 1; nbrPlayersIdx <= numberOfPlayers; nbrPlayersIdx++)
//    {
//        std::cout << "Player " << nbrPlayersIdx << " : Tap your name : ";
//        std::cin >> name;
//        Player player(name);
//        _playersNames.emplace_back(player.GetName());
//    }
//}
//
//std::vector<Player> Deck::GetPlayersNames()
//{
//    return _playersNames;
//}


void Deck::AddCardsToDeck()
{
    for (int suit = (int)CardSuit::CLUBS; suit < (int)CardSuit::SUITEND; suit++) 
			// for each symbol of cards (4 symbols) 

    {
        for (int value = (int)CardValue::TWO; value < (int)CardValue::VALUEEND; value++) 
        	// for each value of cards (13 values)

        {
            _deck.emplace_back(Card(static_cast<CardSuit>(suit), static_cast<CardValue>(value)));
        	// add a card with a symbol and a value in the deck
        }
    }
}

void Deck::ShuffleDeck()
{
    // Given some container `container`...
    std::shuffle(_deck.begin(), _deck.end(), std::random_device()); // shuffle the deck
    
    //int i = 0;
    //// for each card in the deck : print a copy of it 
    //for (auto card : _deck) 
    //{
    //    i++;

    //    // animation of the dealer shuffling
    //    std::cout << "The Dealer is shuffling... : ";
    //    std::cout << card.ToString() << " "  << std::endl;
    //    std::this_thread::sleep_for(std::chrono::milliseconds(10)); 
    //    system("cls");
    //}
}

Card Deck::GiveACard()
{
    // take the first card of the deck, erase it from the deck and return it.
    Card dealtcard(_deck.front());
    _deck.erase(_deck.begin());

    return dealtcard;
}

void Deck::DistributeCards(Deck &deck, std::vector<Player> &playersNames)
{
    for (int cardInHand = 0; cardInHand < 5; cardInHand++)
    {
        for (auto& player : playersNames)
        {
            player.GetACard(deck.GiveACard());
            /*std::cout << player.GetName() << " Hand : ";
            player.PlayerHand();
            std::cout << std::endl;*/

            /*std::this_thread::sleep_for(std::chrono::milliseconds(500));
            system("cls");*/
        }
    }
}

void Deck::ShowPlayersHands(std::vector<Player>& playersNames)
{
    for (auto& player : playersNames)
    {
        Pattern patternShowed = player.TestPattern();
        std::cout << player.GetName() << "'s Hand : " << std::endl;
        player.SortHand();
        std::cout << std::endl;
        player.PlayerHand();
        std::cout << std::endl;
        std::cout << player.GetName() << " has a ";
        //player.ShowPattern(patternShowed);
        std::cout << patternShowed.GetPattern() << std::endl;
    	//" of " << Card::getCardValueAsString(player._hand[player._hand.size() - 1].CardValue) << std::endl;
        std::cout << "________________________________" << std::endl;
        std::cout << std::endl;
    }
}

void Deck::ClearDeck()
{
    _deck.clear();
}


//void Deck::DistributeCards()
//{
//    for (int cardInHand = 0; cardInHand < 5; cardInHand++)
//    {
//        for (auto& player : _playersNames)
//        {
//            player.GetACard(deck.GiveACard());
//            /*std::cout << player.GetName() << " Hand : ";
//            player.PlayerHand();
//            std::cout << std::endl;
//
//            std::this_thread::sleep_for(std::chrono::milliseconds(500));
//            system("cls");*/
//        }
//    }
//}

