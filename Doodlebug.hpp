/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:     Doodlebug.hpp is the Doodlebug class header file.
*********************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"
#include "Board.hpp"

class Doodlebug : public Critter
{
	private:
		int hunger;
	public:
		Doodlebug();
		Doodlebug(int x, int y);
		virtual void move(Critter****,int);
		virtual void breed(Critter****,int);
		void setHunger(int starve);
		int getHunger();
		bool starve();
		~Doodlebug();
};

#endif
