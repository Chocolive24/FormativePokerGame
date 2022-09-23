#include "Player.h"
#include "Deck.h"

#include <iostream>
#include <vector>

int main()
{
    // The deck and the game are controlled by the program which is the dealer.
    Deck deck;

	std::vector<Player> playersNames;

    deck.CreatePlayers(playersNames); 

    bool game = true;

    do 
    {
        // Add the 52 cards in the deck and shuffle them
        deck.AddCardsToDeck();
        deck.ShuffleDeck();

        // Distribute the first card of the deck to each player five times.
        deck.DistributeCards(deck, playersNames);

        // Print the sorted hand and the pattern(s) of each player. 
        deck.ShowPlayersHands(playersNames);

        // Determine and print the winner(s).
        deck.DetermineTheWinner(playersNames);

        // Ask the user if he want to play again.
        deck.PlayAgain(deck, playersNames, game);

    } while (game);

    return 0;
}