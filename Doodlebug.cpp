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

void Doodlebug::move(Critter ****board)
{
	/*
	Increase step count by 1
	randomly move up, down, left, or right. If cell is occupied or off the grid, don’t move.  
	*/
	//There needs to be another function checking for an Ant to eat. Else it continues down.
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
	setHunger(getHunger() +1);
	std::cout << "The doodlebug is " << getHunger() << " that hungry." << std::endl;
}


void Doodlebug::breed()
{
	/*
	If Steps >= 8 
		create new Doodlebug in an empty cell adjacent to Doodlebug, 
		set Steps to 0. 
	If no empty adjacent cell, 
		do nothing.
	*/
}

int Doodlebug::getHunger()
{
	return hunger;
}

void Doodlebug::setHunger(int starve)
{
	hunger = starve;
}
