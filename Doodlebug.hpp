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

	virtual void move(Critter****,int);
	virtual void breed(Critter****,int);
	void setHunger(int starve);
	int getHunger();
	bool starve();
};

#endif
