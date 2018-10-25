#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant :
	public Critter
{
public:
	Ant();
	Ant(int x, int y);
	~Ant();

	void move();
	void breed();
};

#endif
