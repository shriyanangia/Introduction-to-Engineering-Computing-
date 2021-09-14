//
//Name: Shriya Nangia 
//Date: March 22 2020
//Filename: hw4.cpp
//Description: A program to code for a dice game  
//

#include <iostream>
#include <cstdlib>	// needed for srand and rand functions
#include <ctime>	// needed for time function

using namespace std;
//function prototypes 
int roll();
void whiteDiceDisplay(int randnumber);
void redDiceDisplay(int randnumber);


int main()
{
	int comStart;	//declaring the variable that allows the player to start the computer's turn 
	int totalComScore = 0;	//declaring variable that holds the computer's total score (sum of 6 total rolls)
	int comRoll1; int comRoll2; int comRoll3; int comRoll4; int comRoll5; int comRoll6;	//declaring variables to hold the value of each of the computer's 6 rolls
	int totalPlayerScore = 0;	//declaring the variable that holds the player's total score 
	int initialPlayerScore = 0;	//declaring the variable that holds the sum of the white dice for each turn of the player 
	int currentPlayerScore = 0;	//declaring the variable that hold the updated score after comparing the numbers on the white dice with those on the red die 
	int rollAgain;	//declaring the variable that allows the player to roll again 
	int playerRollRed; int playerRollWhite1; int playerRollWhite2;	//declaring the variables that hold the number rolled for each die respectively  
	int playAgain;	//declaring the variable that allows the player to play the game again 
	srand(time(0));	//gives the random function a new seed (a starting point) 

	//Start game 
	cout << "Enter 1 to start the game." << endl; 
	cin >> playAgain;
	while (playAgain == 1)	//while player wants to play the game. Entering outer while loop 
	{
		//Computer's turn 
		cout << "Computer goes first. Computer gets to roll the 2 scoring dice 3 times. For each round, only 1 of the 2 dice will be shown to the player." << endl;
		cout << "Enter 1 to start the computer's turn" << endl;
		cin >> comStart;	//starts the computer's rolls
		cout << "Computer has rolled the dice for round 1. Displayed is 1 of the scoring dice." << endl;
		comRoll1 = roll();	//random number between 1-6 generated (call to function roll())
		comRoll2 = roll();
		whiteDiceDisplay(comRoll1);	//pictorial display of one of the white dice from first round 
		cout << endl;
		cout << "Computer has rolled the dice for round 2. Displayed is 1 of the scoring dice." << endl;
		comRoll3 = roll();
		comRoll4 = roll();
		whiteDiceDisplay(comRoll4);	//pictorial display of one of the white dice from second round
		cout << endl;
		cout << "Computer has rolled the dice for round 3. Displayed is 1 of the scoring dice." << endl;
		comRoll5 = roll();
		comRoll6 = roll();
		whiteDiceDisplay(comRoll6);	//pictorial display of one of the white dice from third round
		cout << endl;
		totalComScore = comRoll1 + comRoll2 + comRoll3 + comRoll4 + comRoll5 + comRoll6;	//sum of all 6 rolls by the computer 

		//Player's turn 
		cout << "It is now the player's turn. Press 1 to roll dice." << endl;
		cin >> rollAgain;
		while (rollAgain == 1)	//while player wants to roll again in the ongoing game. Entering inner while loop  
		{
			playerRollRed = roll();	//random number between 1-6 generated (call to function roll())
			playerRollWhite1 = roll();
			playerRollWhite2 = roll();
			cout << "Red Die: " << endl;
			redDiceDisplay(playerRollRed);	//pictorial display of the red die
			cout << endl;
			cout << "White Die 1: " << endl;
			whiteDiceDisplay(playerRollWhite1);	//pictorial display of the 1st white die
			cout << endl;
			cout << "White Die 2: " << endl;
			whiteDiceDisplay(playerRollWhite2);	//pictorial display of the 2nd white die 
			cout << endl;
			initialPlayerScore = playerRollWhite1 + playerRollWhite2;	//calculation of initial player score 
			if ((playerRollRed == playerRollWhite1) and (playerRollRed == playerRollWhite2))	//checks if all 3 dice have the same number 
			{
				currentPlayerScore = 3*initialPlayerScore;	//updates the current score if true 
				totalPlayerScore += currentPlayerScore;	//current score is added to the existing total score 
				cout << "Current score for this turn: " << currentPlayerScore << endl;	//display current score to the player 
				cout << "Total Score so far: " << totalPlayerScore << endl;	//display total score up till now 
				cout << "Would you like to roll again? (1-Yes , 2-No)" << endl;
				cin >> rollAgain; 
			}
			else if ((playerRollRed == playerRollWhite1) or (playerRollRed == playerRollWhite2))	//checks if the number on the red die matches either of the white dice
			{
				currentPlayerScore = 2*initialPlayerScore;	//updates current score if true 
				totalPlayerScore += currentPlayerScore;	//current score is added to the existing total score 
				cout << "Current score for this turn: " << currentPlayerScore << endl;	//display current score to the player 
				cout << "Total Score so far: " << totalPlayerScore << endl;	//display total score up till now 
				cout << "Would you like to roll again? (1-Yes , 2-No)" << endl;
				cin >> rollAgain; 
			}
			else if ((playerRollRed == 1) and ((playerRollWhite1 != 1) or (playerRollWhite2 != 1)))	//checks if either of the white dice rolled a 1 when the red die rolls a 1
			{
				currentPlayerScore = initialPlayerScore;	//updates current score if true 
				totalPlayerScore = 0;	//total score is reset to 0. Player has lost the game when condition is true.
				rollAgain = 2;	//ensures player cannot roll again 
				cout << "Current score for this turn: " << currentPlayerScore << endl;	//display current score to the player 
			}
			else
			{	
				currentPlayerScore = initialPlayerScore;	//updates current score
				totalPlayerScore += currentPlayerScore;	//current score is added to the existing total score
				cout << "Current score for this turn: " << currentPlayerScore << endl;	//display current score to the player 
				cout << "Total Score so far: " << totalPlayerScore << endl;	//display total score up till now 
				cout << "Would you like to roll again? (1-Yes , 2-No)" << endl;
				cin >> rollAgain; 
			}
			
		}	//exits inner while loop if player does not want to roll again
		//player's turn ends for current game 
		cout << "The computer's total score is = " << totalComScore << endl;	//display computer's total score 
		cout << "The player's total score is = " << totalPlayerScore << endl;	//display player's total score
		//determining the winner of the current game  
		if (totalComScore > totalPlayerScore)
		{
			cout << "The computer won!" << endl;
		}
		else if (totalComScore==totalPlayerScore)
		{
			cout <<"It is a tie!" << endl;
		}
		else
		{
			cout << "Player has won!" << endl; 
		}
		cout << "Would you like to play again? (1-Yes 2-No)" << endl;
		cin >> playAgain;
	}	//exits outer while loop if player does not want to play another game  

	return 0;
}


//Definition of function roll
//Function simulates a roll of a die and returns a random number between 1 and 6
int roll()
{
    int roll = rand() % 6 + 1;
    return roll;
}

//Definition of function whiteDiceDisplay
//Function shows the faces of the white dice corresponding to the numbers 1-6
void whiteDiceDisplay(int randnumber)
{
	switch (randnumber)
	{
		case 1: cout << 
				"  - - - - "  << endl <<
				"|         |" << endl <<
				"|    *    |" << endl <<
				"|         |" << endl <<
				"  - - - -  " << endl;
				break;
		case 2: cout << 
				"  - - - - "  << endl <<
				"| *       |" << endl <<
				"|         |" << endl <<
				"|       * |" << endl <<
				"  - - - -  " << endl;
				break;
		case 3: cout << 
				"  - - - - "  << endl <<
				"| *       |" << endl <<
				"|    *    |" << endl <<
				"|       * |" << endl <<
				"  - - - -  " << endl;
				break;
		case 4: cout << 
				"  - - - - "  << endl <<
				"| *     * |" << endl <<
				"|         |" << endl <<
				"| *     * |" << endl <<
				"  - - - -  " << endl;
				break;
		case 5: cout << 
				"  - - - - "  << endl <<
				"| *     * |" << endl <<
				"|    *    |" << endl <<
				"| *     * |" << endl <<
				"  - - - -  " << endl;
				break;
		case 6: cout << 
				"  - - - - "  << endl <<
				"| *     * |" << endl <<
				"| *     * |" << endl <<
				"| *     * |" << endl <<
				"  - - - -  " << endl;
				break;
	}
}

//Definition of function redDiceDisplay
//Function shows the face of the red die corresponding to the numbers 1-6
void redDiceDisplay(int randnumber)
{
	switch (randnumber)
	{
		case 1: cout << 
				"  - - - - "  << endl <<
				"|         |" << endl <<
				"|    o    |" << endl <<
				"|         |" << endl <<
				"  - - - -  " << endl;
				break;
		case 2: cout << 
				"  - - - - "  << endl <<
				"| o       |" << endl <<
				"|         |" << endl <<
				"|       o |" << endl <<
				"  - - - -  " << endl;
				break;
		case 3: cout << 
				"  - - - - "  << endl <<
				"| o       |" << endl <<
				"|    o    |" << endl <<
				"|       o |" << endl <<
				"  - - - -  " << endl;
				break;
		case 4: cout << 
				"  - - - - "  << endl <<
				"| o     o |" << endl <<
				"|         |" << endl <<
				"| o     o |" << endl <<
				"  - - - -  " << endl;
				break;
		case 5: cout << 
				"  - - - - "  << endl <<
				"| o     o |" << endl <<
				"|    o    |" << endl <<
				"| o     o |" << endl <<
				"  - - - -  " << endl;
				break;
		case 6: cout << 
				"  - - - - "  << endl <<
				"| o     o |" << endl <<
				"| o     o |" << endl <<
				"| o     o |" << endl <<
				"  - - - -  " << endl;
				break;
	}
}
