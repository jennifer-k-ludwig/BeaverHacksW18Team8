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
	//Constructor
	Game();

	//Setters
	void setHouse()
	{
		if (house == "")
			house = checkForLastChoice(0);
	}
	void setPartner()
	{
		if (partner == "")
			partner = checkForLastChoice(1);
	}
	void setKids()
	{
		if (kids == "")
			kids = checkForLastChoice(2);
	}
	void setJob()
	{
		if (job == "")
			job = checkForLastChoice(3);
	}
	void setSalary()
	{
		if (salary == "")
			salary = checkForLastChoice(4);
	}

	//Getters
	std::string getHouse()
	{ return house; }
	std::string getPartner()
	{ return partner; }
	std::string getKids()
	{ return kids; }
	std::string getJob()
	{ return job; }
	std::string getSalary()
	{ return salary; }

	//Methods
	void getChoices();
	void printChoices();
	int getRand();
	void runGame();
	std::string checkForLastChoice(int);
	void displayFortune();

};
#endif