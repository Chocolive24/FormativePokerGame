#include <iostream>
#include <random>
#include <vector>

#include "Player.h"
#include "Deck.h"

// faire fonction qui affiche le Pattern (éviter le texte de la fin du programme
// faire fonctions qui compare 2 patternes, une qui compare les cartes des patternes,
// l'autre qui compare le reste des cartes si les patternes ont les memes cartes

std::vector<Player> CreatePlayers(std::vector<Player>& playersNames)
{
    int numberOfPlayers = 0;
    std::cout << "Tap the number of players up to 10 : ";
    std::cin >> numberOfPlayers;

    std::string name;
    system("cls");

    for (int nbrPlayersIdx = 1; nbrPlayersIdx <= numberOfPlayers; nbrPlayersIdx++)
    {
        std::cout << "Player " << nbrPlayersIdx << " : Tap your name : ";
        std::cin >> name;
        Player player(name);
        playersNames.emplace_back(player.GetName());
        system("cls");
    }

    return playersNames;
}

int main()
{
	std::vector<Player> playersNames;

    // Create the players with their name for the number of players wanted.
    CreatePlayers(playersNames); 

    bool game = true;

    do 
    {
        // The deck and the game are controlled by the program which is the dealer.
        Deck deck; 
        deck.AddCardsToDeck();
        deck.ShuffleDeck();

        // Distribute the first card of the deck to each player five times.
        deck.DistributeCards(deck, playersNames);

        // Show the sorted hand and the pattern(s) of each player 
        deck.ShowPlayersHands(playersNames);
        


    /*    Player test("Testeur");
        Card card1(CardSuit::DIAMONDS, CardValue::TEN);
        Card card2(CardSuit::SPADES, CardValue::TEN);
        Card card3(CardSuit::DIAMONDS, CardValue::TWO);
        Card card4(CardSuit::DIAMONDS, CardValue::TWO);
        Card card5(CardSuit::SPADES, CardValue::QUEEN);

        Player test2("L'autre");
        Card card6(CardSuit::CLUBS, CardValue::FOUR);
        Card card7(CardSuit::HEARTS, CardValue::FOUR);
        Card card8(CardSuit::CLUBS, CardValue::TEN);
        Card card9(CardSuit::CLUBS, CardValue::TEN);
        Card card10(CardSuit::HEARTS, CardValue::THREE);

        test.GetACard(card1);
        test.GetACard(card2);
        test.GetACard(card3);
        test.GetACard(card4);
        test.GetACard(card5);
        test.SortHand();
        test.PlayerHand();
        std::cout << std::endl;
        test.TestPattern();
        std::cout << std::endl;

        test2.GetACard(card6);
        test2.GetACard(card7);
        test2.GetACard(card8);
        test2.GetACard(card9);
        test2.GetACard(card10);
        test2.SortHand();
        test2.PlayerHand();
        std::cout << std::endl;
        test2.TestPattern();
        std::cout << std::endl;

        playersNames.emplace_back(test);
        playersNames.emplace_back(test2);*/

        Pattern bestPattern;
		//PatternValue bestPatternValue = PatternValue::HighCard;
        /*CardValue bestCard = CardValue::TWO;*/
        std::vector<std::string> bestPlayer;
        /*PatternValue result;
        CardValue highCard;*/

        for (auto& player : playersNames)
        {
            Pattern pattern = player.TestPattern();
            /*result = pattern._patternValue;
            highCard = pattern._bestCard;*/

            if (pattern._patternValue > bestPattern._patternValue)
            {
                bestPattern = pattern;
                //bestCard = highCard;
                bestPlayer.clear();
                bestPlayer.emplace_back(player.GetName());
            }
            else if (pattern._patternValue == bestPattern._patternValue)
            {
                if (pattern._bestCard > bestPattern._bestCard || (pattern._bestCard == bestPattern._bestCard &&
                    pattern._secondBestCard > bestPattern._secondBestCard))
                {
                    bestPattern = pattern;
                    //bestCard = highCard;
                    bestPlayer.clear();
                    bestPlayer.emplace_back(player.GetName());
                }
                else if(pattern._bestCard == bestPattern._bestCard &&
                    pattern._secondBestCard == bestPattern._secondBestCard)
                {
                    bestPlayer.emplace_back(player.GetName());
                }
            }
            
        }

        for (auto player : bestPlayer)
        {
            std::cout << "The Winner is : " << player << std::endl << std::endl;
        }



        //for (auto player : bestPlayer)
        //{
        //    if (player.TestPattern()._bestCard > bestCard) // si 1b < 2b
        //    {
        //        bestCard = player.TestPattern()._bestCard;
        //        bestPlayer.clear();
        //        bestPlayer.emplace_back(player.GetName());
        //    }
        //}



        

        //for (auto player : playersNames)
        //{
	       // 
        //}

        //if (test.TestPattern()._patternValue > test2.TestPattern()._patternValue) // si 1 < 2
        //{
        //    bestPlayer.clear();
        //    bestPlayer.emplace_back(test.GetName());
        //}
        //else if (test.TestPattern()._patternValue == test2.TestPattern()._patternValue
        //    && test.TestPattern()._bestCard > test2.TestPattern()._bestCard) // si 1 == 2
        //{// si 1b < 2b
        //    
        //    bestPlayer.clear();
        //    bestPlayer.emplace_back(test.GetName());
        //}
         //   else if (test.TestPattern()._bestCard == test2.TestPattern()._bestCard
         //           && test.TestPattern()._secondBestCard > test2.TestPattern()._secondBestCard) // si 1b == 2b
         //   {
         //       std::cout << "ENFIN";
         //   }
        	//else if (test.TestPattern()._bestCard == test2.TestPattern()._bestCard
         //       && test.TestPattern()._secondBestCard == test2.TestPattern()._secondBestCard) // si 1sb < 2sb
         //   {
        	//	std::cout << "CA RACE";
         //   }
        	//else if (test.TestPattern()._secondBestCard == test2.TestPattern()._secondBestCard
         //           && test.TestPattern()._thirdBestCard > test2.TestPattern()._thirdBestCard) // si 1sb == 2sb
         //   {
        	//	std::cout << "TESTEUR 1 GAGNE";
         //   }
         //   

        //std::cout << "The Winner is : " << bestPlayer[0];

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

        int userAnswer;
        std::cout << "Tap '1' to replay or any other key to quite the game.";
        std::cin >> userAnswer;

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
            game = false;
        }
        

    } while (game);
}



