#include "Doodlebug.hpp"



Doodlebug::Doodlebug()
{
}

Doodlebug::Doodlebuyg(int x, int y)
{
	xCoord = x;
	yCoord = y;
	type = DOODLEBUG;
}


Doodlebug::~Doodlebug()
{
}

void Doodlebug::move()
{
	/*If there is an ant adjacent, 
		move to that cell, 
		eat(set alive to 0) ant
		set Hunger to 0.  
	else If no ants are adjacent, 
		move to empty cell
		increase Hunger by 1 
	else If no ants AND no empty cell(all adjacent cells are Doodlebugs) 
		don’t move
		increase Hunger by 1. 
		Increase Steps by 1.
	*/
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
