#include "Ant.hpp"
#include <cstdlib>
#include <iostream>


Ant::Ant()
{
}

Ant::Ant(int x, int y)
{
	setSteps(0);
	setMoved(false);	
	xCoord = x;
	yCoord = y;
	type = ANT;

}


Ant::~Ant()
{
}

void Ant::move(Critter ****board)
{
	/*
	Increase step count by 1
	randomly move up, down, left, or right. If cell is occupied or off the grid, don’t move.  
	*/
	int counter = 0;
	int direction = rand(); 
	bool moved = false;
	while(counter < 4 && !moved)
	{
		direction++;
		direction  = direction % 4;
		switch(direction)
		{
			case 0:
				if(getXCoord() - 1 > -1 && (*board)[getXCoord() - 1][getYCoord()] == NULL)
				{
					(*board)[getXCoord() - 1][getYCoord()] = (*board)[getXCoord()][getYCoord()];
					(*board)[getXCoord()][getYCoord()] = NULL;
					setXCoord(getXCoord() - 1);
					moved = true;
				}
				counter++;
				break;
			case 1:
				if(getYCoord() + 1 < 20  && (*board)[getXCoord()][getYCoord() +1] == NULL)
				{
					(*board)[getXCoord()][getYCoord() +1] = (*board)[getXCoord()][getYCoord()];
					(*board)[getXCoord()][getYCoord()] = NULL;
					setYCoord(getYCoord() + 1);
					moved = true;
				}
				counter++;
				break;
			case 2:
				if(getXCoord() + 1 < 20 && (*board)[getXCoord() + 1][getYCoord()] == NULL)
				{
					(*board)[getXCoord() + 1][getYCoord()] = (*board)[getXCoord()][getYCoord()];
					(*board)[getXCoord()][getYCoord()] = NULL;
					setXCoord(getXCoord() + 1);
					moved = true;
				}
				counter++;
				break;
			case 3:
				if(getYCoord() - 1 > -1  && (*board)[getXCoord()][getYCoord() -1] == NULL)
				{
					(*board)[getXCoord()][getYCoord() -1] = (*board)[getXCoord()][getYCoord()];
					(*board)[getXCoord()][getYCoord()] = NULL;
					setYCoord(getYCoord() - 1);
					moved = true;
				}
				counter++;
				break;


		}
	}
	setMoved(true);
	setSteps(getSteps() + 1);
}

void Ant::breed()
{
	/*
	 if Steps >= 3 
		create new ant in an empty cell adjacent to ant, 
		set Steps to 0. 
	If no empty adjacent cell, do nothing.
	*/
}
