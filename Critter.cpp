#include "Critter.hpp"



Critter::Critter()
{

}


Critter::~Critter()
{
}

void Critter::setXCoord(int x)
{
	xCoord = x;
}

int Critter::getXCoord(int)
{
	return xCoord;
}

void Critter::setYCoord(int y)
{
	yCoord = y;
}

int Critter::getYCoord(int)
{
	return yCooord;
}

void Critter::setSteps(int s)
{
	steps = s;
}

int Critter::getSteps()
{
	return steps;
}

void Critter::setMoved(bool mov)
{
	moved = mov;
}

bool Critter::getMoved()
{
	return moved;
}

void Critter::setAlive(bool state)
{
	alive = state;
}

bool Critter::getAlive()
{
	return alive;
}

Type Critter::getType()
{
	return type;
}

void Critter::move()
{
	//
}

void Critter::breed()
{
	//
}
