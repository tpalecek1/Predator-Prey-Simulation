/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:     Board.cpp is the Board class implementation file.
*********************************************************************/

#include "Board.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>

/********************************************************************
** Description: This default constructor initialize board to 20x20 
				to NULL.
********************************************************************/
Board::Board()
{
	size = 20;
	board = new Critter**[size];
	for(int i = 0; i < size; i++)
	{
		board[i] = new Critter*[size];
		for (int j = 0; j < size; j++)
		{
			board[i][j] = NULL;
		}
	}
}

/********************************************************************
** Description: This function accepts no parameter and display the 
				board to the user.
********************************************************************/
void Board::displayBoard()
{
	int ants = 0;
	int doodlebugs = 0;

	std::cout << "\n\n";
	//iterate through board displaying either 'X' or 'O'
	for (int j = 0; j < size; j++)
	{
		std::cout << "|";
		for (int i = 0; i < size; i++)
		{
			if (board[i][j] == NULL)
				std::cout << " ";
			else if (board[i][j]->getType() == ANT){
				ants++;
				std::cout << "O";
			}
			else {
				doodlebugs++;
				std::cout << "X";
			}
		std::cout << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "There are " << ants << " ants." << std::endl;
	std::cout << "There are " << doodlebugs << " doodlebugs." << std::endl;
}


/********************************************************************
** Description: This function accepts no parameter and add Critter ptr
				to 100 Ants and 5 Doodlebug objects randomly on the
				board.
********************************************************************/
void Board::addCritters()
{
	//The Ant creation/addition portion
	int numAnt = 0;
	int numDoodlebug = 0;
	while (numAnt < 100)
	{
		int x = rand() % size;  //get random x
		int y = rand() % size;  //get random y

		if (board[x][y] == NULL) //if there is nothing there
		{ //increase the number of ant counter
			numAnt++;
			//assign that board spot the pointer
			board[x][y] = new Ant(x,y);
		}
	}

	//The Doodlebug creation/addition portion
	while (numDoodlebug < 5)
	{
		int x = rand() % size;  //get random x
		int y = rand() % size;  //get random y

		if (board[x][y] == NULL) //if there is nothing there
		{ //increase the number of ant counter
			numDoodlebug++;
			//assign that board spot the pointer
			board[x][y] = new Doodlebug(x, y);
		}
	}
}

/********************************************************************
** Description: This function accepts no parameter. Move Doodlebug
				first than Ant.
********************************************************************/
void Board::moveCritters()
{
	//Iterate through grid performing move function on all Critters with moved = false
	//Move the Doodlebugs first.
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(board[i][j] != NULL && board[i][j]->getType() == DOODLEBUG && board[i][j]->getMoved() == false)
			{
				board[i][j]->move(&board, size);
			}
		}
	}
	//Move the Ants last.	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(board[i][j] != NULL && board[i][j]->getType() == ANT && board[i][j]->getMoved() == false)
			{
				board[i][j]->move(&board, size);
			}
		}
	}
}

/********************************************************************
** Description: This function accepts no parameter. Peforms breed
				function on all Critters.
********************************************************************/
void Board::breedCritters()
{
	//perform breed function on all Critters
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(board[i][j] != NULL && board[i][j]->getType() == DOODLEBUG && board[i][j]->getSteps() > 0 && board[i][j]->getSteps() % 8 == 0)
			{
				board[i][j]->breed(&board,size);
			}
			if(board[i][j] != NULL && board[i][j]->getType() == ANT && board[i][j]->getSteps() > 0 && board[i][j]->getSteps() % 3 == 0)
			{
				board[i][j]->breed(&board,size);
			}
		}
	}
}

/********************************************************************
** Description: This function accepts no parameter. Clears the move
				flag for all Critters.
********************************************************************/
void Board::clearMoved()
{
	//set moved to false on all Critters
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] != NULL)
			{
				board[i][j]->setMoved(false);
			}
		}
	}
}

/********************************************************************
** Description: This function accepts no parameter. Removes all 
				critter by setting the flag of alive to false.
********************************************************************/
void Board::removeCritters()
{
	//remove all Critters with alive = false
	for(int x = 0; x < size; x++){
		for(int y = 0; y < size; y++){
			if(board[x][y] != NULL && board[x][y]->getType() == DOODLEBUG){
				Doodlebug *doodle = dynamic_cast<Doodlebug*>(board[x][y]);
				if (doodle->starve()){
					delete board[x][y];
					board[x][y] = NULL;
				}
			}
		}
	}
}

/********************************************************************
** Description: This destructor free's up dynamically allocated
				memory.
********************************************************************/
Board::~Board()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] != NULL)
				delete board[i][j];
		}
		delete [] board[i];
	}
	delete[] board;
}
