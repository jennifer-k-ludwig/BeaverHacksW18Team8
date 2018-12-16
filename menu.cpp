#include "menu.hpp"

/************************************************************************************************
Function: void displayHomeScreen()
Description: Displays home screen.
************************************************************************************************/

void Menu::displayHomescreen()
{
	std::cout << "Welcome to MASH!" << std::endl;
	std::cout << "MASH is a game that predicts your future." << std::endl;
	std::cout << std::endl;
}

/************************************************************************************************
Function: void getChoices()
Description: Gets choices from user.
************************************************************************************************/

void Menu::displayInstructions()
{
	std::cout << "Instructions:" << std::endl;
	std::cout << "MASH stands for Mansion, Apartment, Shack, House." << std::endl;
	std::cout << "In MASH, you will be given a number of categories, including housing." << std::endl;
	std::cout << "You will fill each category with four choices of that type." << std::endl;
	std::cout << "Once the categories have been filled, you will be given a lucky" << std::endl;
	std::cout << "number and it will be used to predict your future!" << std::endl;
	std::cout << std::endl;
	std::cout << "Press enter to play..." << std::endl;
	std::cin.ignore(1, '\n');
}
