#include "Ant.hpp"



Ant::Ant()
{
}

Ant::Ant(int x, int y)
{
	xCoord = x;
	yCoord = y;
	type = ANT;

}


Ant::~Ant()
{
}

void Ant::move()
{
	/*
	Increase step count by 1
	randomly move up, down, left, or right. If cell is occupied or off the grid, don’t move.  
	*/
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
