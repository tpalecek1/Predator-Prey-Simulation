/*********************************************************************
** Program name: OSU Information System
** Author: Timothy Palecek
** Date: 10/19/2018
** Description: Header file for the Menu class.  Has integers to store number of
**				instructions and number of menu options, vecotrs to store
**				instructions and options. Has functions to add
**				instructions and options, to display the menu and return 
**				validated user input as an int.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <iostream>

class Menu
{
private:
	int numInstructions;
	int numOptions;
	std::vector<std::string> instructions;
	std::vector<std::string> options;

public:
	Menu();
	~Menu();
	//Return number of instructions
	int getNumInstructions();
	//Return number of options
	int getNumOptions();
	//Add an instruction to vector of strings
	void addInstructions(std::string);
	//Add option to vector of strings
	void addOption(std::string);
	//Display the instructions and a numbered list of options
	void display();
	//Return user input between 1 and number of options
	int getInput();
	//Displays the menu AND gets input
	int prompt();


};

#endif