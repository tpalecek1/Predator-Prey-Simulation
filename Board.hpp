/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:     Board.hpp is the Board class header file.
*********************************************************************/
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
		void displayBoard();
		void addCritters();
		void moveCritters();
		void breedCritters();
		void clearMoved();
		void removeCritters();
		~Board();	
};
#endif