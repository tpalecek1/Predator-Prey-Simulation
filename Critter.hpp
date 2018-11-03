/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:     Critter.hpp is the Critter class header file.
*********************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP
enum Type {ANT, DOODLEBUG};

class Critter
{
	protected:
		int xCoord;	//Stores current x and y coords(MAY NOT BE NEEDED)
		int yCoord;	//stores steps since last bred
		int steps;	//Checks if critter has moved this turn
		bool moved;	//checks if critter is alive
		bool alive;	//Stores enum value Ant or Doodlebug
		Type type;
	public:
		Critter();
		virtual ~Critter();
		void setXCoord(int);
		int getXCoord();
		void setYCoord(int);
		int getYCoord();
		void setSteps(int);
		int getSteps();
		void setMoved(bool);
		bool getMoved();
		void setAlive(bool);
		bool getAlive();
		Type getType();
		virtual void move(Critter****, int);
		virtual void breed(Critter****, int);
		virtual bool starve();
};
#endif
