#include "Card.h"
#include "Deck.h"

#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <random>
#include <thread>

void Deck::AddCardsToDeck()
{
    // For each suit of cards (4 suit).
    for (int suit = (int)CardSuit::CLUBS; suit < (int)CardSuit::SUITEND; suit++) 
    {
    	// For each value of cards (13 values).
        for (int value = (int)CardValue::TWO; value < (int)CardValue::VALUEEND; value++) 
        {
            // Add a card with a symbol and a value in the deck.
            _deck.emplace_back(Card(static_cast<CardSuit>(suit), static_cast<CardValue>(value)));
        }
    }
}

void Deck::ShuffleDeck()
{
    // Given some container `container`...
    std::shuffle(_deck.begin(), _deck.end(), std::random_device()); // shuffle the deck

    // For each card in the deck : print a copy of it.
    int i = 0;
    for (auto card : _deck) 
    {
        i++;

        // Animation of the dealer shuffling.
        std::cout << "The Dealer is shuffling... : ";
        std::cout << card.ToString() << " "  << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); 
        system("cls");
    }
}

void Deck::CreatePlayers(std::vector<Player>& playersNames)
{
    // Create as many players as you want with their name, up to 10.
    int numberOfPlayers = 0;
    std::cout << "Tap the number of players, up to 10 : ";
    std::cin >> numberOfPlayers;
    std::string name;
    system("cls");

    // Ask for the names of the players and add them in a vector.
    for (int nbrPlayersIdx = 1; nbrPlayersIdx <= numberOfPlayers; nbrPlayersIdx++)
    {
        std::cout << "Player " << nbrPlayersIdx << " : Tap your name : ";
        std::cin >> name;
        Player player(name);
        playersNames.emplace_back(player.GetName());
        system("cls");
    }
}

Card Deck::GiveACard()
{
    // take the first card of the deck, erase it from the deck and return it.
    Card dealtcard(_deck.front());
    _deck.erase(_deck.begin());

    return dealtcard;
}

// Give the first card of the deck to each player in turn, 5 times
void Deck::DistributeCards(Deck &deck, std::vector<Player> &playersNames)
{
    for (int cardInHand = 0; cardInHand < 5; cardInHand++)
    {
        for (auto& player : playersNames)
        {
            player.GetACard(deck.GiveACard());
        }
    }
}

// For each player, print his hand and pattern
void Deck::ShowPlayersHands(std::vector<Player>& playersNames)
{
    for (auto& player : playersNames)
    {
        // Check the pattern.
        Pattern patternShowed = player.TestPattern();

        std::cout << player.GetName() << "'s Hand : " << std::endl;

        // Sort the cards in ascending order.
        player.SortHand();
        std::cout << std::endl;

        // Show player's hand.
        player.PlayerHand();
        std::cout << std::endl;

        // Show player's pattern.
        std::cout << player.GetName() << " has a ";
        std::cout << patternShowed.GetPattern() << std::endl;
        std::cout << "________________________________" << std::endl;
        std::cout << std::endl;
    }
}

void Deck::DetermineTheWinner(std::vector<Player> &playersNames)
{
    // Best pattern is set by default at "high card".
    Pattern bestPattern;

    // Vector that will contains the filtered winning players.
    std::vector<std::string> bestPlayer;

    // Algorithm looking for the winning player.
    for (auto& player : playersNames)
    {
        // Check the pattern
        Pattern pattern = player.TestPattern();

        // If the player's pattern is better than the best pattern
        if (pattern._patternValue > bestPattern._patternValue)
        {
            // The best pattern become the player's pattern and the vector saves the name of the new best player
            bestPattern = pattern;
            bestPlayer.clear();
            bestPlayer.emplace_back(player.GetName());
        }

        // If the patterns are equal, check the best cards and the second best cards to find a winner and save his name
        else if (pattern._patternValue == bestPattern._patternValue)
        {
            if (pattern._bestCard > bestPattern._bestCard || (pattern._bestCard == bestPattern._bestCard &&
                pattern._secondBestCard > bestPattern._secondBestCard))
            {
                bestPattern = pattern;
                bestPlayer.clear();
                bestPlayer.emplace_back(player.GetName());
            }

            // If the patterns and the best cards and second best cards are equal, then there is two or more winners.
            else if (pattern._bestCard == bestPattern._bestCard &&
                pattern._secondBestCard == bestPattern._secondBestCard)
            {
                bestPlayer.emplace_back(player.GetName());
            }
        }
    }

    // Print the name(s) of the winner(s)
    for (auto player : bestPlayer)
    {
        std::cout << "The Winner is : " << player << std::endl << std::endl;
    }
}

// Ask the user if he wants to play again
void Deck::PlayAgain(Deck &deck, std::vector<Player> &playersNames, bool &game)
{
    int userAnswer;
    std::cout << "Tap '1' to replay or any other key to quite the game." << std::endl;
    std::cin >> userAnswer;

    // If yes, clear the deck and the players hands
    if (userAnswer == 1)
    {
        deck.ClearDeck();
        for (auto& player : playersNames)
        {
            player.ClearHand();
        }
        system("cls");
    }

    else
    {
        system("cls");
        std::cout << "See you soon !" << std::endl;
        game = false;
    }
}

void Deck::ClearDeck()
{
    _deck.clear();
}