#include "game.hpp"

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
	//Show housing category with prefilled options
	std::cout << "Category: Housing" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << i + 1 << ". " << choices[0][i] << std::endl;
	}
	std::cout << std::endl;
	
	int count = 0;

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
			std::cout << choices[i][j] << std::endl;
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

					//Set category variable to final choice in each category
					setHouse();
					setPartner();
					setKids();
					setJob();
					setSalary();

					//Print new choice board to show user progress
					printChoices();

					std::cout << eliminated << " was eliminated" << std::endl;

					std::cout << "Press enter to continue..." << std::endl;
					std::cin.ignore(1, '\n');
          
					//Check if elimination is done to continue loop
					if (house != "" && partner != "" && kids != "" && job != "" && salary != "")
						eliminationIsDone = true;

					//Reset choice counter
					choiceCounter = 0;
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

std::string Game::checkForLastChoice(int row)
{
	std::string lastChoice = "";

	//If last choice in a category, save it to house and eliminate it from choices
	if (choices[row][0] == "" && choices[row][1] == "" && choices[row][2] == "")
	{
		lastChoice = choices[row][3];
		choices[row][3] = "";
	}
	else if (choices[row][0] == "" && choices[row][1] == "" && choices[row][3] == "")
	{
		lastChoice = choices[row][2];
		choices[row][3] = "";
	}
	else if (choices[row][0] == "" && choices[row][2] == "" && choices[row][3] == "")
	{
		lastChoice = choices[row][1];
		choices[row][3] = "";
	}
	else if (choices[row][1] == "" && choices[row][2] == "" && choices[row][3] == "")
	{
		lastChoice = choices[row][0];
		choices[row][3] = "";
	}

	return lastChoice;
}

/************************************************************************************************
Function: void displayFortune()
Description: Displays fortune to user.
************************************************************************************************/

void Game::displayFortune()
{
	std::cout << "Congratulations!" << std::endl;
  std::cout << "We have successfully determined your future." << std::endl;
  std::cout << std::endl;
	std::cout << "You will live in a " << getHouse() << " with your partner, " << getPartner() << "," << std::endl;
  std::cout << "and your " << getKids() << " children. You will work as a " << getJob() << std::endl;
	std::cout << "and make " << getSalary() << " per year." << std::endl;
}
