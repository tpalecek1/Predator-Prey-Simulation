#include "Doodlebug.hpp"
#include <cstdlib>
#include <iostream>



Doodlebug::Doodlebug()
{
}

Doodlebug::Doodlebug(int x, int y)
{
	xCoord = x;
	yCoord = y;
	type = DOODLEBUG;
	setHunger(0);
	setSteps(0);
	setMoved(false);
}


Doodlebug::~Doodlebug()
{
}

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


void Doodlebug::breed(Critter**** board, int boardSize)
{
	/*
	If Steps >= 8 
		create new Doodlebug in an empty cell adjacent to Doodlebug, 
		set Steps to 0. 
	If no empty adjacent cell, 
		do nothing.
	*/

	int direction;
	bool up = getXCoord() - 1 > -1 && (*board)[getXCoord() -1][getYCoord()] == NULL;
	bool down = getXCoord() + 1 < boardSize && (*board)[getXCoord() + 1][getYCoord()] == NULL;
	bool left = getYCoord() + 1 < boardSize && (*board)[getXCoord()][getYCoord() + 1] == NULL;
	bool right = getYCoord() - 1 > -1 && (*board)[getXCoord()][getYCoord() - 1] == NULL;
	bool notBred = true;
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

int Doodlebug::getHunger()
{
	return hunger;
}

void Doodlebug::setHunger(int starve)
{
	hunger = starve;
}

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
