#include "game.hpp"
#include "menu.hpp"
#include <iostream>

int main()
{
	Menu menu;

	//Homescreen
	menu.displayHomescreen();

	//Instructions
	menu.displayInstructions();

	//Play game
	menu.playGame();

	return 0;
}

