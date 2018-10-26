#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug :
	public Critter
{
private:
	int hunger;
public:
	Doodlebug();
	Doodlebuyg(int x, int y);
	~Doodlebug();

	void move();
	void breed();
	void setHunger(int starve);
	int getHunger();
};

#endif
