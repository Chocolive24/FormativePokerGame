#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

#include "Card.h"
#include "Player.h"
#include "Deck.h"

int main()
{
    Deck deck;

    std::vector<Player> playersNames;
    int numberOfPlayers = 0;
    std::cout << "Tap the number of players up to 4 : ";
    std::cin >> numberOfPlayers;
    std::string name;

    for(int nbrPlayersIdx = 1; nbrPlayersIdx <= numberOfPlayers; nbrPlayersIdx++)
    {
        std::cout << "Player " << nbrPlayersIdx << " : Tap your name : ";
        std::cin >> name;
        Player player(name);
        playersNames.emplace_back(player.GetName());
    }

    
    //deck.CreatePlayers();
    deck.AddCardsToDeck();
    deck.ShuffleDeck();

    for (int cardInHand = 0; cardInHand < 5; cardInHand++)
    {
        for (auto &player : playersNames)
        {
            player.GetACard(deck.GiveACard());
            /*std::cout << player.GetName() << " Hand : ";
            player.PlayerHand();
            std::cout << std::endl;*/
            
            /*std::this_thread::sleep_for(std::chrono::milliseconds(500));
            system("cls");*/
        }
    }

    for (auto &player : playersNames)
    {
        std::cout << player.GetName() << " Hand : ";
        player.PlayerHand();
        std::cout << std::endl << std::endl;
    }

    /*

    Player player1("John"), player2("Paul");

    
    for (int a = 0; a < 5; a++)
    {
        player1.GetACard(deck.GiveACard());
        player2.GetACard(deck.GiveACard());
        std::cout << "John Hand : / ";
        player1.PlayerHand();
        std::cout << std::endl << std::endl;
        std::cout << "Paul Hand : / ";
        player2.PlayerHand();
        std::cout << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        system("cls");
        
    } 

    
    
    std::cout << "John Hand : / ";
    player1.PlayerHand();
    std::cout << std::endl << std::endl;
    std::cout << "Paul Hand : / ";
    player2.PlayerHand();
    std::cout << std::endl << std::endl;

    */

    /*
    for (auto card : deck) // for each card in the deck : print a copy of it 
    {
        i++;
        std::cout << card.ToString() << " " << i << std::endl;
    }

    for (int a = 0; a < 5; a++)
    {
        Card dealtcard(deck.front());
        deck.erase(deck.begin());
        player2.GetACard(dealtcard);
    }

    */
    
    /*
    player2.PlayerHand();
    std::cout << std::endl;

    for (auto card : deck) // for each card in the deck : print a copy of it 
    {
        i++;
        std::cout << card.ToString() << " " << i << std::endl;
    }

    */

    //Card dealtCard(deck.front());
    //deck.erase(deck.begin());
    
}



