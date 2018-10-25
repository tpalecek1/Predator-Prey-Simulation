#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug :
	public Critter
{
public:
	Doodlebug();
	Doodlebuyg(int x, int y);
	~Doodlebug();

	void move();
	void breed();
};

#endif