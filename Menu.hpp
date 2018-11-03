/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:    	Header file for the Menu class.  Has integers to store 
					number of instructions and number of menu options, 
					vectors to store instructions and options. Has functions 
					to add instructions and options, to display the menu and 
					return validated user input as an integer.
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
		int getNumInstructions();	//Return number of instructions
		int getNumOptions();	//Return number of options
		void addInstructions(std::string);	//Add an instruction to vector of strings
		void addOption(std::string);	//Add option to vector of strings
		void display();	//Display the instructions and a numbered list of options
		int getInput();	//Return user input between 1 and number of options
		int prompt();	//Displays the menu AND gets input
};
#endif