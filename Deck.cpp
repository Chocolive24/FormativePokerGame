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
    for (int suit = (int)CardSuit::CLUBS; suit < (int)CardSuit::SuitEnd; suit++) // for each symbol of cards (4 symbols) 
    {
        for (int value = (int)CardValue::TWO; value < (int)CardValue::ValueEnd; value++) // for each value of cards (13 values)
        {
            _deck.emplace_back(Card(static_cast<CardSuit>(suit), static_cast<CardValue>(value))); // add a card with a symbol and a value in the deck
        }
    }
}

void Deck::ShuffleDeck()
{
    // Given some container `container`...
    std::shuffle(_deck.begin(), _deck.end(), std::random_device()); // shuffle the deck

    int i = 0;
    for (auto card : _deck) // for each card in the deck : print a copy of it 
    {
        i++;
        std::cout << "The Dealer is shuffling... : ";
        std::cout << card.ToString() << " "  << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        system("cls");
    }
}

Card Deck::GiveACard()
{
    Card dealtcard(_deck.front());
    _deck.erase(_deck.begin());

    return dealtcard;
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

