#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"
#include "Board.hpp"

class Ant :	public Critter
{
public:
	Ant();
	Ant(int x, int y);
	~Ant();

	virtual void move(Critter ****board);
	void breed(Critter**** board);
};

#endif
