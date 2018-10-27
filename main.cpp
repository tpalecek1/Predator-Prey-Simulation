#include "Board.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Board board;
	board.displayBoard();
	board.addCritters();
	board.displayBoard();
	for(int n = 0; n < 3; n++){
		board.moveCritters();
		board.clearMoved();
		board.removeCritters();
		board.displayBoard();
	}

	return 0;
}