#include "game.hpp"
#include "menu.hpp"

int main()
{
	Game game;
	Menu menu;

	//Home Screen
	menu.displayHomescreen();

	//Instructions
	menu.displayInstructions();
	
	//Gets choices under each category from user
	game.getChoices();

	//Output contents of array (for testing)
	game.printChoices();

	//Run game
	game.runGame();

	//Display fortune
	game.displayFortune();

	return 0;
}

