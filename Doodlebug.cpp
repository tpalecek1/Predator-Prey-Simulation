/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:     Doodlebug.cpp is the Doodlebug implementation file.
*********************************************************************/

#include "Doodlebug.hpp"
#include <cstdlib>
#include <iostream>

/********************************************************************
** Description: Default constructor.
********************************************************************/
Doodlebug::Doodlebug()
{
}

/********************************************************************
** Description: This constructor accepts two integers: x and y. Set 
				the member variables: steps to 0, move to false, 
				xCoord to x, yCoord to y, hunger to 0 and type to 
				Doodlebug.
********************************************************************/
Doodlebug::Doodlebug(int x, int y)
{
	xCoord = x;
	yCoord = y;
	type = DOODLEBUG;
	setHunger(0);
	setSteps(0);
	setMoved(false);
}

/********************************************************************
** Description: This function accpets Critter board and the board 
				size as the parameter. Each step Doodlebug will try 
				to move to an adjacent cell containing an ant and eat 
				the ant. If not the Doodle will move to a random 
				adjacent cell.
********************************************************************/
void Doodlebug::move(Critter ****board, int boardSize)
{
	/*
	Increase step count by 1
	randomly move up, down, left, or right. If cell is occupied or off the grid, don’t move.  
	*/
	int direction;
	bool critterMoved = false;

	//Checks if the cell in the up, left, right or down position it is actually on the 
	//board, if that cell is pointing to a Critter type, and if that Critter type is Ant.
	bool isAntUp = getXCoord() - 1 > -1 
					&& (*board)[getXCoord() -1][getYCoord()] != NULL 
					&& (*board)[getXCoord() -1][getYCoord()]->getType() == ANT;

	bool isAntDown = getXCoord() + 1 < boardSize 
					&& (*board)[getXCoord() + 1][getYCoord()] != NULL 
					&& (*board)[getXCoord() +1][getYCoord()]->getType() == ANT;

	bool isAntRight = getYCoord() + 1 < boardSize 
					&& (*board)[getXCoord()][getYCoord() + 1] != NULL 
					&& (*board)[getXCoord()][getYCoord() + 1]->getType() == ANT;

	bool isAntLeft = getYCoord() - 1 > -1 
					&& (*board)[getXCoord()][getYCoord() - 1] != NULL 
					&& (*board)[getXCoord()][getYCoord() - 1]->getType() == ANT;

	//Checks if the cell in the up, down, left, or right position is actually on the board 
	//and if that cell is pointing to NULL.
	bool up = getXCoord() - 1 > -1 
			&& (*board)[getXCoord() - 1][getYCoord()] == NULL;

	bool down = getXCoord() + 1 < boardSize 
			&& (*board)[getXCoord() + 1][getYCoord()] == NULL;

	bool left = getYCoord() - 1 > -1  
			&& (*board)[getXCoord()][getYCoord() -1] == NULL;

	bool right = getYCoord() + 1 < boardSize 
			&& (*board)[getXCoord()][getYCoord() +1] == NULL;

	/*
	If there is an Ant in a cell around the Doodlebug, the Doodlebug will look for it.			

	Loop until it finds an Ant.

	Once an Ant is found, free the memory at the Ant location, take the Ant's pointer 
	and point to the Doodlebug. Set the Doodlebug's old pointer to NULL and update the
	Doodlebug's x or y coordinate. Set it's hunger to 0 and change critterMoved to true
	to break out of the loop.
	*/
	if(isAntUp || isAntDown || isAntRight || isAntLeft){
		while(!critterMoved){
			direction = rand() % 4;
			switch(direction){
				case 0:
					if(isAntUp){
						delete (*board)[getXCoord() -1][getYCoord()];
						(*board)[getXCoord() -1][getYCoord()] = (*board)[getXCoord()][getYCoord()];
						(*board)[getXCoord()][getYCoord()] = NULL;
						setXCoord(getXCoord() - 1);
						setHunger(0);
						critterMoved = true;
					}
					break;
				case 1:
					if(isAntDown){
						delete (*board)[getXCoord() + 1][getYCoord()];
						(*board)[getXCoord() + 1][getYCoord()] = (*board)[getXCoord()][getYCoord()];
						(*board)[getXCoord()][getYCoord()] = NULL;
						setXCoord(getXCoord() + 1);
						setHunger(0);
						critterMoved = true;
					}
					break;
				case 2:
					if(isAntRight){
						delete (*board)[getXCoord()][getYCoord() + 1];
						(*board)[getXCoord()][getYCoord() + 1] = (*board)[getXCoord()][getYCoord()];
						(*board)[getXCoord()][getYCoord()] = NULL;
						setYCoord(getYCoord() + 1);
						setHunger(0);
						critterMoved = true;
					}
					break;
				case 3:
					if(isAntLeft){
						delete (*board)[getXCoord()][getYCoord() - 1];
						(*board)[getXCoord()][getYCoord() - 1] = (*board)[getXCoord()][getYCoord()];
						(*board)[getXCoord()][getYCoord()] = NULL;
						setYCoord(getYCoord() - 1);
						setHunger(0);
						critterMoved = true;
					}
					break;

			}	
		}

	}

	else	
	{
		/*
		If there are no Ant's around, the Doodlebug will move randomly to an available cell if possible.
		The pointers are swapped, the old pointer points to NULL, the doodlebug's hunger increases, it's
		X or Y coordinate is changed and critterMoved is changed to break from the loop.
		*/
		while((up || down || left || right) && !critterMoved)
		{
			direction = rand() % 4;
			switch(direction)
			{
				case 0:
					if(up)
					{
						(*board)[getXCoord() - 1][getYCoord()] = (*board)[getXCoord()][getYCoord()];
						(*board)[getXCoord()][getYCoord()] = NULL;
						setXCoord(getXCoord() - 1);
						setHunger(getHunger() +1);
						critterMoved = true;
					}
					break;
				case 1:
					if(right)
					{
						(*board)[getXCoord()][getYCoord() +1] = (*board)[getXCoord()][getYCoord()];
						(*board)[getXCoord()][getYCoord()] = NULL;
						setYCoord(getYCoord() + 1);
						setHunger(getHunger() +1);
						critterMoved = true;
					}
					break;
				case 2:
					if(down)
					{
						(*board)[getXCoord() + 1][getYCoord()] = (*board)[getXCoord()][getYCoord()];
						(*board)[getXCoord()][getYCoord()] = NULL;
						setXCoord(getXCoord() + 1);
						setHunger(getHunger() +1);
						critterMoved = true;
					}
					break;
				case 3:
					if(left)
					{
						(*board)[getXCoord()][getYCoord() -1] = (*board)[getXCoord()][getYCoord()];
						(*board)[getXCoord()][getYCoord()] = NULL;
						setYCoord(getYCoord() - 1);
						setHunger(getHunger() +1);
						critterMoved = true;
					}
					break;


			}
		}
	}
	
	setMoved(true);
	setSteps(getSteps() + 1);
}

/********************************************************************
** Description: This function takes in two parameters: Critter board
				and the size of the board. If a ant survives for >=8
				steps. Breed a new Doodlebug to a random adjacent cell. 
				If no empty cells are avaiable no breeding occurs.
********************************************************************/
void Doodlebug::breed(Critter**** board, int boardSize)
{
	int direction;
	
	bool up = getXCoord() - 1 > -1 && (*board)[getXCoord() -1][getYCoord()] == NULL;
	bool down = getXCoord() + 1 < boardSize && (*board)[getXCoord() + 1][getYCoord()] == NULL;
	bool left = getYCoord() + 1 < boardSize && (*board)[getXCoord()][getYCoord() + 1] == NULL;
	bool right = getYCoord() - 1 > -1 && (*board)[getXCoord()][getYCoord() - 1] == NULL;
	bool notBred = true;

	/*
	If Steps >= 8 
		create new Doodlebug in an empty cell adjacent to Doodlebug, 
		set Steps to 0. 
	If no empty adjacent cell, 
		do nothing.
	*/
	while((up || down || left || right) && notBred){
		direction = rand() % 4;
		switch(direction){
			case 0:
				if(up){
					(*board)[getXCoord() -1][getYCoord()] = new Doodlebug(getXCoord() - 1, getYCoord());
					notBred = false;
				}
				break;
			case 1:	
				if(down){
					(*board)[getXCoord() + 1][getYCoord()] 	= new Doodlebug(getXCoord() + 1, getYCoord());
					notBred = false;
				}
				break;
			case 2:
				if(left){
					(*board)[getXCoord()][getYCoord() + 1] 	= new Doodlebug(getXCoord(), getYCoord() + 1);
					notBred = false;
				}
				break;
			case 3:
				if(right){
					(*board)[getXCoord()][getYCoord() - 1] 	= new Doodlebug(getXCoord(), getYCoord() - 1);
					notBred = false;
				}
				break;	
		}
	}
}

/********************************************************************
** Description: This function accepts an integer starve and set
				the member variable hunger.
********************************************************************/
void Doodlebug::setHunger(int starve)
{
	hunger = starve;
}

/********************************************************************
** Description: This function accepts no parameter and return the
				integer hunger.
********************************************************************/
int Doodlebug::getHunger()
{
	return hunger;
}

/********************************************************************
** Description: This function accepts no parameter. Returns true
				if hunger is greater than 3 if not return false.
********************************************************************/
bool Doodlebug::starve()
{
	if (hunger > 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/********************************************************************
** Description: Destructor
********************************************************************/
Doodlebug::~Doodlebug()
{
}