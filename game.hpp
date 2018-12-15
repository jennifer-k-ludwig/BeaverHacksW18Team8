#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <ctime>

class Game
{
private:
	std::string categories[5] = { "Housing", "Partner", "Number of Kids", "Job", "Salary" };
	std::string choices[5][4] = { {"Mansion", "Apartment", "Shack", "House"} };
	std::string house, partner, kids, job, salary;

public:
	Game();
	void getChoices();
	void printChoices();
	int getRand();
	void runGame();
	std::string checkForLastChoice(int);
	void displayFortune();
};
#endif