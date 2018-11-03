/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:     Ant.hpp is the Ant class header file.
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"
#include "Board.hpp"

class Ant :	public Critter
{
	public:
		Ant();
		Ant(int x, int y);
		virtual void move(Critter ****,int);
		virtual void breed(Critter ****,int);
		~Ant();
};
#endif
