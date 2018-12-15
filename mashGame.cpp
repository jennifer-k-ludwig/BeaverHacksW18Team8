#include "pch.h"
#include<iostream>
#include<string>
#include<ctime> //for random number generator

void displayHomeScreen(), displayInstructions(), getChoices(std::string [], std::string[][4]), printChoices(std::string[], std::string[][4]), displayFortune();
int getRand();
std::string checkForLastChoice(std::string array[][4], int col);

int main()
{
	//Home Screen
	displayHomeScreen();

	//Instructions
	displayInstructions();

	//Collect four choices under each category from user (except for housing)
	//Categories: housing(MASH), Partner, Kids, Job, Salary
	std::string categories[5] = { "Housing", "Partner", "Kids", "Job", "Salary" };

	//the rows are categories and the columns are choices
	std::string choices[5][4] = { {"Mansion", "Apartment", "Shack", "House"} }; 
	
	getChoices(categories, choices);

	//outputs contents of array (for testing)
	printChoices(categories, choices);

	//Generate random number
	int luckyNumber = getRand();
	std::cout << "Your random number is " << luckyNumber << "." << std::endl;
	std::cout << std::endl;

	
	//Compute fortune
	int choiceCounter = 0;
	int nullCounter = 0;
	bool eliminationIsDone = false;

	std::string house = "";
	std::string partner = "";
	std::string kids = "";
	std::string job = "";
	std::string salary = "";

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

					//Print new choice board to show user progress
					printChoices(categories, choices);
					std::cout << eliminated << " was eliminated" << std::endl;

					//Check each category for a final choice
					if (house == "")
						house = checkForLastChoice(choices, 0);

					if (partner == "")
						partner = checkForLastChoice(choices, 1);

					if (kids == "")
						kids = checkForLastChoice(choices, 2);

					if (job == "")
						job = checkForLastChoice(choices, 3);

					if (salary == "")
						salary = checkForLastChoice(choices, 4);

					std::cout << "TEST: " << std::endl;
					std::cout << "House: " << house << std::endl;
					std::cout << "Partner: " << partner << std::endl;
					std::cout << "Kids: " << kids << std::endl;
					std::cout << "Job: " << job << std::endl;
					std::cout << "Salary: " << salary << std::endl;

					system("pause");

					//Check if elimination is done to continue loop
					if (house != "" && partner != "" && kids != "" && job != "" && salary != "")
						eliminationIsDone = true;
				}
			}
			nullCounter = 0;
		}
	}
		

	//Display fortune
	displayFortune();

	return 0;
}

/************************************************************************************************
Function: void displayHomeScreen()
Description: Displays home screen.
************************************************************************************************/
void displayHomeScreen()
{
	std::cout << "Welcome to MASH!" << std::endl;
	std::cout << "MASH is a game that predicts your future." << std::endl;
	std::cout << std::endl;
}

/************************************************************************************************
Function: void displayInstructions()
Description: Displays instructions.
************************************************************************************************/
void displayInstructions()
{
	std::cout << "Instructions:" << std::endl;
	std::cout << "MASH stands for Mansion, Apartment, Shack, House." << std::endl;
	std::cout << "In MASH, you will be given a number of categories, including housing." << std::endl;
	std::cout << "You will fill each category with four choices of that type." << std::endl;
	std::cout << "Once the categories have been filled, a random number" << std::endl;
	std::cout << "will be selected for you and used to predict your future!" << std::endl;
	std::cout << std::endl;

	system("pause");
	std::cout << std::endl;
}

/************************************************************************************************
Function: void getChoices()
Description: Gets choices from user.
************************************************************************************************/
void getChoices(std::string array1[], std::string array2[][4])
{
	int count = 0;

	//Show housing category with prefilled options
	std::cout << "Category: Housing" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << i + 1 << ". " << array2[0][i] << std::endl;
	}
	std::cout << std::endl;

	for (int i = 1; i < 5; i++)
	{
		std::cout << "Category: " << array1[i] << std::endl;
		for (int j = 0; j < 4; j++)
		{
			std::cout << j + 1 << ". ";
			std::getline(std::cin, array2[i][j]);
		}
		std::cout << std::endl;
		count++;
	}
}
/************************************************************************************************
Function: void printChoices()
Description: Prints choices to screen.
************************************************************************************************/
void printChoices(std::string array1[], std::string array2[][4])
{
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Category: " << array1[count] << std::endl;
		for (int j = 0; j < 4; j++)
		{
			std::cout << j + 1 << ". ";
			std::cout << array2[i][j];
			std::cout << std::endl;
		}
		std::cout << std::endl;
		count++;
	}
}

/************************************************************************************************
Function: void getRand()
Description: Outputs users random number to console.
************************************************************************************************/
int getRand()
{
	//seed the random number generator using time
	srand(time(NULL));

	//return random number (between 2 and 11) to variable
	return (rand() % 10) + 2; 

	
}

/************************************************************************************************
Function: void displayFortune()
Description: Displays fortune to user.
************************************************************************************************/
void displayFortune()
{
	std::cout << "Congratulations! We have successfully determined your future." << std::endl;
}

/************************************************************************************************
Function: string checkHousing(std::string array[][4])
Description: checks housing category for final selection
************************************************************************************************/
std::string checkForLastChoice(std::string array[][4], int col)
{
	std::string lastChoice = "";

	//If last choice in a category, save it to house and eliminate it from choices
	if (array[col][0] == "" && array[col][1] == "" && array[col][2] == "")
	{
		lastChoice = array[col][3];
		array[col][3] = "";
	}
	else if (array[col][0] == "" && array[col][1] == "" && array[col][3] == "")
	{
		lastChoice = array[col][2];
		array[col][3] = "";
	}
	else if (array[col][0] == "" && array[col][2] == "" && array[col][3] == "")
	{
		lastChoice = array[col][1];
		array[col][3] = "";
	}
	else if (array[col][1] == "" && array[col][2] == "" && array[col][3] == "")
	{
		lastChoice = array[col][0];
		array[col][3] = "";
	}

	return lastChoice;
}