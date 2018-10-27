#ifndef BOARD_HPP
#define BOARD_HPP

#include "Critter.hpp"
class Board
{
private:
	Critter*** board;
	int size;
public:
	Board();
	~Board();

	void displayBoard();
	void addCritters();
	void moveCritters();
	void breedCritters();
	void clearMoved();
	void removeCritters();



};

#endif