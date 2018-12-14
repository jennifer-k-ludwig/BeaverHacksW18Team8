#include<iostream>
#include<string>
#include<ctime> //for random number generator


int main()
{
	
	//Home Screen
	std::cout << "Welcome to MASH!" << std::endl;
	std::cout << "MASH is a game that predicts your future." << std::endl;
	std::cout << "Enter any key to continue or q to quit." << std::endl; //need to add this functionality
	std::cout << std::endl;

	//Instructions
	std::cout << "Instructions:" << std::endl; 
	std::cout << "MASH stands for Mansion, Apartment, Shack, House." << std::endl;
	std::cout << "In MASH, you will be given a number of categories, including housing." << std::endl;
	std::cout << "You will fill each category with four choices of that type." << std::endl;
	std::cout << "Once the categories have been filled, a random number" << std::endl;
	std::cout << "will be selected for you and used to predict your future!" << std::endl;
	std::cout << std::endl;

	//Collect four choices under each category from user (except for housing)
	//Categories: housing(MASH), Partner, Kids, Job, Salary
	std::string categories[5] = { "Housing", "Partner", "Kids", "Job", "Salary" };
	std::string choices[5][4] = { {"Mansion", "Apartment", "Shack", "House"} }; //the rows are categories and the columns are choices
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

	//outputs contents of array (for testing)
	count = 0;
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

	//Generate random number
	srand(time(NULL)); //seed the random number generator using time
	int number = (rand() % 10) + 2; //assign random number (between 2 and 11) to variable
	std::cout << "Your random number is " << number << "." << std::endl;
	std::cout << std::endl;

	//Compute fortune
	

	//Display fortune
	std::cout << "Congratulations! We have successfully determined your future." << std::endl;

	return 0;
}