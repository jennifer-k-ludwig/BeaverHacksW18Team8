#include<iostream>
#include<string>

int main()
{
	//Home Screen
	std::cout << "Welcome to MASH!" << std::endl;
	std::cout << "MASH is a game that allows you to predict your future." << std::endl;
	std::cout << "Enter any key to continue or q to quit." << std::endl;
	std::cout << std::endl;

	//Instructions
	std::cout << "Instructions" << std::endl; 
	std::cout << "MASH stands for Mansion, Apartment, Shack, House.\nIn MASH, you will be given a number of categories, including housing.\n" <<
		"You will fill each category with four choices of that type.\nOnce the categories have been filled, a random number\n" <<
		" will be selected for you and used to predict your future!" << std::endl;
	return 0;
}