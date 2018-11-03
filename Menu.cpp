/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:     Implementation file for the Menu class.  Has integers
					to store number of instructions and number of menu 
					options, vecotrs to store instructions and options. 
					Has functions to add instructions and options, to
					display the menu and return validated user input 
					as an int.
*********************************************************************/
#include "Menu.hpp"

/********************************************************************
** Description: Default constructor set private member variable
				numInstructions and numOptions to 0.
********************************************************************/
Menu::Menu()
{
	numInstructions = 0;
	numOptions = 0;
}

/********************************************************************
** Description: Destructor.
********************************************************************/
Menu::~Menu()
{
}

/********************************************************************
** Description: This function accepts no parameter and returns
				the number of instructions.
********************************************************************/
int Menu::getNumInstructions()
{
	return numInstructions;
}

/********************************************************************
** Description: This function accepts no parameter and returns
				the number of options.
********************************************************************/
int Menu::getNumOptions()
{
	return numOptions;
}

/********************************************************************
** Description: This function add an instruction to vector of strings.
********************************************************************/
void Menu::addInstructions(std::string instr)
{
	instructions.push_back(instr);
	numInstructions++;
}

/********************************************************************
** Description: This function add option to vector of strings
********************************************************************/
void Menu::addOption(std::string op)
{
	options.push_back(op);
	numOptions++;
}

/********************************************************************
** Description: This function accepts no parameter and display
				the instruction and menu to the user.
********************************************************************/
void Menu::display()
{
	std::cout << "\n**********************************************" << std::endl;
	for (int i = 0; i < numInstructions; i++) {
		std::cout << instructions[i] << std::endl;
	}
	std::cout << "**********************************************" << std::endl;
	for (int i = 0; i < numOptions; i++) {
		std::cout << i + 1 << ". " << options[i] << std::endl;
	}
}

/********************************************************************
** Description: This function accepts no parameter and returns
				user input between 1 and number of options.
********************************************************************/
int Menu::getInput()
{
	std::string strInput = " ";
	std::getline(std::cin, strInput);

	//check that user did not just press enter
	while (strInput == "") {
		std::cout << "Invalid input, please enter a menu choice between 1 and " << numOptions << ": ";
		std::getline(std::cin, strInput);
	}

	//Check if input is an integer
	bool isInt = true;
	for (int i = 0; i < strInput.length(); i++) {
		if (!isdigit(strInput[i])) {
			isInt = false;
		}
	}
	//Keep checking if re-entered input is integer within desired range
	while (isInt == false || std::stoi(strInput) < 1 || std::stoi(strInput) > numOptions) {
		isInt = true;
		std::cout << "Invalid input, please enter a menu choice between 1 and " << numOptions << ": ";
		std::getline(std::cin, strInput);
		while (strInput == "") {
			std::cout << "Invalid input, please enter a menu choice between 1 and " << numOptions << ": ";
			std::getline(std::cin, strInput);
		}
		for (int i = 0; i < strInput.length(); i++) {
			if (!isdigit(strInput[i])) {
				isInt = false;
			}
		}
	}

	return std::stoi(strInput);
}


/********************************************************************
** Description: This function accepts no parameter and displays the
				menu to the user and retuns the user input.
********************************************************************/
int Menu::prompt()
{
	display();
	return getInput();
}
