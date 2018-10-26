#include "Board.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <cstdlib>
#include <iostream>

//Used to initialize board to 20x20 of NULL
Board::Board()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			board[i][j] = NULL;
		}
	}
}
//Used to remove any dynamically created objects off the board
Board::~Board()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (board[i][j] != NULL)
				delete board[i][j];
		}
	}
}
//Used to iterate through the board and display a blank, 'O', or 'X' based on what
//what is located there
void Board::displayBoard()
{
	std::cout << "\n\n";
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			if (board[i][j] == NULL)
				std::cout << " ";
			else if (board[i][j]->getType() == ANT)
				std::cout << "O";
			else
				std::cout << "X";
		}
		std::cout << std::endl;
	}
}
//Used to add Critter Pointers to 100 Ant
//and Doodlebug objects randomly on the board
void Board::addCritters()
{
	//The Ant creation/addition portion
	int numAnt = 0;
	while (numAnt < 100)
	{
		int x = rand() % 20;  //get random x
		int y = rand() % 20;  //get random y

		if (board[x][y] == NULL) //if there is nothing there
		{ //increase the number of ant counter
			numAnt++;
			//create a critter pointer to an ant object named flik
			Critter *flik = new Ant(x, y);
			//assign that board spot the pointer
			board[x][y] = flik;
		}
}

void Board::moveCritters()
{
	//Iterate through grid performing move function on all Critters with moved = false
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if(board[i][j] != NULL)
			{
				if (board[i][j]->getMoved() == false)
				{
					board[i][j]->move();
					board[i][j]->setMoved(true);
				}
			}
		}
	}
}

void Board::breedCritters()
{
	//perform breed function on all Critters
}

void Board::clearMoved()
{
	//set moved to false on all Critters
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (board[i][j] != NULL)
			{
				board[i][j]->setMoved(false);
			}
		}
	}
}

void Board::removeCritters()
{
	//remove all Critters with alive = false
}
