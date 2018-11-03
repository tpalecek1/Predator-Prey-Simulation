/*********************************************************************
** Program name:    Predator-Prey Game
** Author:          Timothym P, Johnny B, Jose G, Melisa L, Randoplph T
** Date:            11/3/2018
** Description:    	This file stores validation functions that ensures
					inputs are of the desired type and within the 
					desired range, and returns these values.
*********************************************************************/
#include "validation.hpp"
#include <string>
#include <ctime>
#include <iostream>
#include <limits>

/*********************************************************************
** Description:   Checks that user input only contains alphanumeric values 	
*********************************************************************/
std::string alphaNumValidation(std::string message) {
	//get input from user
	std::string strInput = " ";
	std::getline(std::cin, strInput);

	//check that user did not just press enter
	while (strInput == "") {
		std::cout << message;
		std::getline(std::cin, strInput);
	}
	//Check if input contains only alphanumeric characters
	bool isInt = true;
	for (int i = 0; i < strInput.length(); i++) {
		if (!isalnum(strInput[i]) && strInput[i] != ' ') {
			isInt = false;
		}
	}
	//Keep checking if re-entered input is integer within desired range
	while (isInt == false) {
		isInt = true;
		std::cout << message;
		std::getline(std::cin, strInput);
		while (strInput == "") {
			std::cout << message;
			std::getline(std::cin, strInput);
		}
		for (int i = 0; i < strInput.length(); i++) {
			if (!isalnum(strInput[i])) {
				isInt = false;
			}
		}
	}

	return strInput;
}


/*********************************************************************
** Description:   Check that user input is an integer in the desired
				  range. 	
*********************************************************************/
int validation(int input, int lowerbound, int upperbound, std::string message) {
	//get input from user
	std::string strInput = " ";
	std::getline(std::cin, strInput);

	//check that user did not just press enter
	while (strInput == "") {
		std::cout << message;
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
	while (isInt == false || std::stoi(strInput) < lowerbound || std::stoi(strInput) > upperbound) {
		isInt = true;
		std::cout << message;
		std::getline(std::cin, strInput);
		while (strInput == "") {
			std::cout << message;
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

/*********************************************************************
** Description:  Check that user input is a double in the desired range 	
*********************************************************************/
double doubleValidation(double lowerbound, double upperbound, std::string message) {
	double dInput = -2;
	bool validInput = false;
	//get input from user
	std::cin >> dInput;
	while (!std::cin || dInput < lowerbound || dInput > upperbound) {
		std::cout << message;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> dInput;
	}

	return dInput;
}