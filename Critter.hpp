#ifndef CRITTER_HPP
#define CRITTER_HPP
enum Type {ANT, DOODLEBUG};

class Critter
{
protected:
	//Stores current x and y coords(MAY NOT BE NEEDED)
	int xCoord;
	int yCoord;
	//stores steps since last bred
	int steps;
	//Checks if critter has moved this turn
	bool moved;
	//checks if critter is alive
	bool alive;
	//Stores enum value Ant or Doodlebug
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

	//Function that moves to an adjacent position and increases step count by 1
	virtual void move(Critter****);
	//Function that attempts to create critter in adjacent empty cell. If successful, set steps to 0
	virtual void breed();
};

#endif