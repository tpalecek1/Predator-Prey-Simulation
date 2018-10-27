#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"
#include "Board.hpp"

class Doodlebug :
	public Critter
{
private:
	int hunger;
public:
	Doodlebug();
	Doodlebug(int x, int y);
	~Doodlebug();

	virtual void move(Critter****);
	void breed();
	void setHunger(int starve);
	int getHunger();
};

#endif
