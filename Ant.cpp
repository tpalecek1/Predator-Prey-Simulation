/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:     Ant.cpp is the Ant class implementation file.
*********************************************************************/
#include "Ant.hpp"
#include <cstdlib>
#include <iostream>

/********************************************************************
** Description: Default constructor.
********************************************************************/
Ant::Ant()
{
}

/********************************************************************
** Description: This constructor accepts two integers: x and y. Set 
				the member variables: steps to 0, move to false, 
				xCoord to x, yCoord to y and type to ANT.
********************************************************************/
Ant::Ant(int x, int y)
{
	setSteps(0);
	setMoved(false);	
	xCoord = x;
	yCoord = y;
	type = ANT;
}


/********************************************************************
** Description: This function accpets Critter board and the board 
				size as the parameter. Move ant to a random adjacent
				cell, if none are occupied don't move.
********************************************************************/
void Ant::move(Critter ****board, int boardSize)
{
	/*
	Increase step count by 1
	randomly move up, down, left, or right. If cell is occupied or off the grid, don't move.  
	*/
	int direction = rand(); 
	bool critterMoved = false;
	bool up = getXCoord() - 1 > -1 
		&& (*board)[getXCoord() - 1][getYCoord()] == NULL;
	bool down = getXCoord() + 1 < boardSize 
		&& (*board)[getXCoord() + 1][getYCoord()] == NULL; 
	bool left = getYCoord() - 1 > -1  
		&& (*board)[getXCoord()][getYCoord() -1] == NULL; 
	bool right = getYCoord() + 1 < boardSize 
		&& (*board)[getXCoord()][getYCoord() +1] == NULL;
	/*
	The Ant will move randomly to an available cell if possible. The pointers are swapped, the old 
	pointer points to NULL, it's X or Y coordinate is changed and critterMoved is changed to break 
	from the loop.
	*/
	while((up || down || left || right) && !critterMoved)
	{
		direction  = rand() % 4;
		switch(direction)
		{
			case 0:
				if(up)
				{
					(*board)[getXCoord() - 1][getYCoord()] = (*board)[getXCoord()][getYCoord()];
					(*board)[getXCoord()][getYCoord()] = NULL;
					setXCoord(getXCoord() - 1);
					critterMoved = true;
				}
				break;
			case 1:
				if(right)
				{
					(*board)[getXCoord()][getYCoord() +1] = (*board)[getXCoord()][getYCoord()];
					(*board)[getXCoord()][getYCoord()] = NULL;
					setYCoord(getYCoord() + 1);
					critterMoved = true;
				}
				break;
			case 2:
				if(down)
				{
					(*board)[getXCoord() + 1][getYCoord()] = (*board)[getXCoord()][getYCoord()];
					(*board)[getXCoord()][getYCoord()] = NULL;
					setXCoord(getXCoord() + 1);
					critterMoved = true;
				}
				break;
			case 3:
				if(left)
				{
					(*board)[getXCoord()][getYCoord() -1] = (*board)[getXCoord()][getYCoord()];
					(*board)[getXCoord()][getYCoord()] = NULL;
					setYCoord(getYCoord() - 1);
					critterMoved = true;
				}
				break;
		}
	}

	setMoved(true);
	setSteps(getSteps() + 1);
}

/********************************************************************
** Description: This function takes in two parameters: Critter board
				and the size of the board. If a ant survives for three
				steps breed a new ant to a random adjacent cell. If no
				empty cells are avaiable no breeding occurs.
********************************************************************/
void Ant::breed(Critter**** board, int boardSize)
{
	/*
	 if Steps >= 3 
		create new ant in an empty cell adjacent to ant, 
		set Steps to 0. 
	If no empty adjacent cell, do nothing.
	*/
	int direction;

	bool up = getXCoord() - 1 > -1 
		&& (*board)[getXCoord() -1][getYCoord()] == NULL;
	bool down = getXCoord() + 1 < boardSize 
		&& (*board)[getXCoord() + 1][getYCoord()] == NULL;
	bool left = getYCoord() + 1 < boardSize 
		&& (*board)[getXCoord()][getYCoord() + 1] == NULL;
	bool right = getYCoord() - 1 > -1 
		&& (*board)[getXCoord()][getYCoord() - 1] == NULL;

	bool notBred = true;

	while((up || down || left || right) && notBred){
		direction = rand() % 4;
		switch(direction){
			case 0:
				if(up){
					(*board)[getXCoord() -1][getYCoord()] = new Ant(getXCoord() - 1, getYCoord());
					notBred = false;
				}
				break;
			case 1:	
				if(down){
					(*board)[getXCoord() + 1][getYCoord()] 	= new Ant(getXCoord() + 1, getYCoord());
					notBred = false;
				}
				break;
			case 2:
				if(left){
					(*board)[getXCoord()][getYCoord() + 1] 	= new Ant(getXCoord(), getYCoord() + 1);
					notBred = false;
				}
				break;
			case 3:
				if(right){
					(*board)[getXCoord()][getYCoord() - 1] 	= new Ant(getXCoord(), getYCoord() - 1);
					notBred = false;
				}
				break;	
		}
	}
}

/********************************************************************
** Description: Destructor
********************************************************************/
Ant::~Ant()
{
}