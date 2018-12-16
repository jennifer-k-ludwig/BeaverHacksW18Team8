#include "pch.h"
#include "game.hpp"
#include <windows.h>

/************************************************************************************************
Function: Game()
Description: Gets choices from user.
************************************************************************************************/
Game::Game()
{
	house = "";
	partner = "";
	kids = "";
	job = "";
	salary = "";
}

/************************************************************************************************
Function: void getChoices()
Description: Gets choices from user.
************************************************************************************************/
void Game::getChoices()
{
	int count = 0;

	//Show housing category with prefilled options
	std::cout << "Category: Housing" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << i + 1 << ". " << choices[0][i] << std::endl;
	}
	std::cout << std::endl;

	for (int i = 1; i < 5; i++)
	{
		std::cout << "Category: " << categories[i] << std::endl;
		for (int j = 0; j < 4; j++)
		{
			std::cout << j + 1 << ". ";
			std::getline(std::cin, choices[i][j]);
		}
		std::cout << std::endl;
		count++;
	}
}


/************************************************************************************************
Function: void printChoices()
Description: Prints choices to screen.
************************************************************************************************/
void Game::printChoices()
{
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Category: " << categories[count] << std::endl;
		for (int j = 0; j < 4; j++)
		{
			std::cout << j + 1 << ". ";
			std::cout << choices[i][j];
			std::cout << std::endl;
		}
		std::cout << std::endl;
		count++;
	}
}

/************************************************************************************************
Function: int getRand()
Description: Outputs users random number to console.
************************************************************************************************/
int Game::getRand()
{
	//seed the random number generator using time
	srand(time(NULL));

	//return random number (between 2 and 11) to variable
	return (rand() % 10) + 2;
}


/************************************************************************************************
Function: void runGame()
Description: Generates random number, performs the elimination process and stores players
              choices in variables.
************************************************************************************************/
void Game::runGame()
{
  	//Generate random number
	int luckyNumber = getRand();
	std::cout << "Your random number is " << luckyNumber << "." << std::endl;
	std::cout << std::endl;

	//Compute fortune
	int choiceCounter = 0;
	int nullCounter = 0;
	bool eliminationIsDone = false;

	

	while (!eliminationIsDone)
	{
		for (int n = 0; n < 5; n++)
		{
			for (int m = 0; m < 4; m++)
			{
				//each choice is counted if not null
				if (choices[n][m] != "")
				{
					choiceCounter++;
				}
				//if the choice number is equal to the lucky number, it will be set to a null string
				if (choiceCounter == luckyNumber)
				{
					//Save choice for elimination readout
					std::string eliminated = choices[n][m];

					//Eliminate choice
					choices[n][m] = "";

					choiceCounter = 0;

					//Check each category for a final choice
					if (house == "")
						house = checkForLastChoice(0);

					if (partner == "")
						partner = checkForLastChoice(1);

					if (kids == "")
						kids = checkForLastChoice(2);

					if (job == "")
						job = checkForLastChoice(3);

					if (salary == "")
						salary = checkForLastChoice(4);

					//Print new choice board to show user progress
					printChoices();
					std::cout << eliminated << " was eliminated" << std::endl;

					Sleep(1500);

					//Check if elimination is done to continue loop
					if (house != "" && partner != "" && kids != "" && job != "" && salary != "")
						eliminationIsDone = true;
				}
			}
			nullCounter = 0;
		}
	}
  
}

/************************************************************************************************
Function: string checkForLastChoice(int col)
Description: Checks each category for final selection.
************************************************************************************************/

std::string Game::checkForLastChoice(int col)
{
	std::string lastChoice = "";

	//If last choice in a category, save it to house and eliminate it from choices
	if (choices[col][0] == "" && choices[col][1] == "" && choices[col][2] == "")
	{
		lastChoice = choices[col][3];
		choices[col][3] = "";
	}
	else if (choices[col][0] == "" && choices[col][1] == "" && choices[col][3] == "")
	{
		lastChoice = choices[col][2];
		choices[col][3] = "";
	}
	else if (choices[col][0] == "" && choices[col][2] == "" && choices[col][3] == "")
	{
		lastChoice = choices[col][1];
		choices[col][3] = "";
	}
	else if (choices[col][1] == "" && choices[col][2] == "" && choices[col][3] == "")
	{
		lastChoice = choices[col][0];
		choices[col][3] = "";
	}

	return lastChoice;
}

/************************************************************************************************
Function: void displayFortune()
Description: Displays fortune to user.
************************************************************************************************/

void Game::displayFortune()
{
	std::cout << std::endl;
	std::cout << "Congratulations! We have successfully determined your future." << std::endl;
	std::cout << "You will live in a " << house << " with your partner, " << partner << ", and your "
		<< kids << " children." << std::endl;
	std::cout << "You will work as a " << job << " and make " << salary << " per year."
		<< std::endl;
}
