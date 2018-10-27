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
	for(int n = 0; n < 1000; n++){
		board.moveCritters();
		board.clearMoved();
		board.breedCritters(); 	
		board.removeCritters();
		board.displayBoard();
		std::cout << "Time step " << n +1 << std::endl;
	}

	return 0;
}