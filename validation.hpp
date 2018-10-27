/*********************************************************************
** Program name: Langton's Ant
** Author: Timothy Palecek
** Date: 10/3/2018
** Description: This file stores validation functions that ensures inputs are of the desired
**				type and within the desired range, and returns these values.
*********************************************************************/


#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <string>

//Validate string is all alphanumeric characters
std::string alphaNumValidation(std::string message);

//validate Int input between a lower and upper bound. Display error message and re-prompt if out of bounds
int validation(int input, int lowerBound, int upperBound, std::string message);

double doubleValidation(double lowerbound, double upperbound, std::string message);
#endif

