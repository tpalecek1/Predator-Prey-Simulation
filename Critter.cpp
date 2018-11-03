/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:     Critter.cpp is the Critter class implementation file.
*********************************************************************/

#include "Critter.hpp"

/********************************************************************
** Description: Default constructor.
********************************************************************/
Critter::Critter()
{
}

/********************************************************************
** Description: Destructor.
********************************************************************/
Critter::~Critter()
{
}

/********************************************************************
** Description: This function accept an integer x and set the 
				member variable xCoord.
********************************************************************/
void Critter::setXCoord(int x)
{
	xCoord = x;
}

/********************************************************************
** Description: This function accepts no parameter and returns 
				and integer representing xCoord.
********************************************************************/
int Critter::getXCoord()
{
	return xCoord;
}

/********************************************************************
** Description: This function accept an integer y and set the 
				member variable yCoord.
********************************************************************/
void Critter::setYCoord(int y)
{
	yCoord = y;
}

/********************************************************************
** Description: This function accepts no parameter and returns 
				and integer representing yCoord.
********************************************************************/
int Critter::getYCoord()
{
	return yCoord;
}

/********************************************************************
** Description: This function accept an integer s and set the 
				member variable steps.
********************************************************************/
void Critter::setSteps(int s)
{
	steps = s;
}

/********************************************************************
** Description: This function accepts no parameter and returns 
				and integer representing steps.
********************************************************************/
int Critter::getSteps()
{
	return steps;
}

/********************************************************************
** Description: This function accept an boolean mov and set the 
				member variable moved.
********************************************************************/
void Critter::setMoved(bool mov)
{
	moved = mov;
}

/********************************************************************
** Description: This function accept an no parameter and returns
				the boolean moved.
********************************************************************/
bool Critter::getMoved()
{
	return moved;
}

/********************************************************************
** Description: This function accept a boolean state and set the
				member varaiable alive.
********************************************************************/
void Critter::setAlive(bool state)
{
	alive = state;
}

/********************************************************************
** Description: This function accept no parameter and returns the 
				boolean alive.
********************************************************************/
bool Critter::getAlive()
{
	return alive;
}

/********************************************************************
** Description: This function accept no parameter and returns the 
				Critter type.
********************************************************************/
Type Critter::getType()
{
	return type;
}

/********************************************************************
** Description: This function accept Critter board and board size 
				as the parameter. Moves to an adjacent position and 
				increases step count by 1
********************************************************************/
void Critter::move(Critter ****board, int boardSize)
{
	//
}

/********************************************************************
** Description: This function accept Critter board and board size 
				as the parameter.  attempts to create critter in
				adjacent empty cell. If successful, set steps to 0
********************************************************************/
void Critter::breed(Critter ****board, int boardSize)
{
	//
}

/********************************************************************
** Description: This function accept no parameter and returns the 
				boolean false.
********************************************************************/
bool Critter::starve()
{
	return false;
}
