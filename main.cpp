/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:     This is the main function to start the program
					Predator-Prey Game.
*********************************************************************/

#include "Board.hpp"
#include "Menu.hpp"
#include "validation.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main(int argc, char const *argv[])
{
	int rounds = 0;
	int cont = 1;
	srand(time(NULL));
	Board board;
	
	// add options to the menu
	Menu mainMenu;
	mainMenu.addInstructions("Would you like to continue the simulation?");
	mainMenu.addOption("Start");
	mainMenu.addOption("Quit");
	
	// validate user input and display board  
	std::cout << "Please enter a number of rounds you would like to simulate: ";
	rounds = validation(rounds, 1, 100, "Please enter number of rounds between 1 and 100: ");
	board.displayBoard();
	board.addCritters();
	board.displayBoard();

	// iterate until user exit
	while (cont == 1) {
		for (int n = 0; n < rounds; n++) {
			board.moveCritters();
			board.breedCritters();
			board.clearMoved();
			board.removeCritters();
			board.displayBoard();
		}
		cont = mainMenu.prompt();
		if (cont == 1) {
			std::cout << "Please enter a number of rounds you would like to simulate: ";
			rounds = validation(rounds, 1, 100, "Please enter number of rounds between 1 and 100: ");
		}
	}
	
	return 0;
}