/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: Implementation
*/

#include <iostream>
#include "data.h"
#include "scoring.h"
#include "scoring.cpp"



int main() {
	
	std::cout << "SCORING ALGORITHM FOR RANKING CURRENCIES\n" << std::endl;

	/*
	Part 1: IMPLEMENTATION WITH RANDOMIZED DATA
	*/
	std::cout << "Part 1: IMPLEMENTATION WITH RANDOMIZED DATA" << std::endl;
		
	Scoring Xen(2);
	Scoring BlackMesa = Xen;
	Xen.setDimension(3);
	std::cout << Xen.getDimension() << std::endl;        // 3 is expected
	std::cout << BlackMesa.getDimension() << std::endl;  // 2 is expected
	Xen.~Scoring();

	/*
	Part 2: IMPLEMENTATION WITH 25D FX RISK REVERSAL DATA
	*/

	// [To be completed]
	
	system("pause");
	return 0;
}