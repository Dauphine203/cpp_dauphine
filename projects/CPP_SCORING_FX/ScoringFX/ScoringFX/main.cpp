/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: Implementation
*/

#include <iostream>
#include "data.h"
#include "scoring.h"
//#include "scoring.cpp"  Never put this when defining class methods outside of class.h header



int main() {
	
	std::cout << "SCORING CLASS FOR RANKING GLOBAL CURRENCIES\n" << std::endl;


	std::cout << "Welcome to the H.E.V. Mark 4 protective system." << std::endl;
	std::cout << "For use in hazardous environment conditions.\n" << std::endl;


	// Test 1: Basic OOP
	printf("BASIC OOP TESTING\n");

	Scoring Xen(2);
	Scoring BlackMesa = Xen;
	Xen.setDimension(3);
	std::cout << "Xen: " << Xen.getDimension() << std::endl;        // 3 is expected
	std::cout << "BlackMesa: " << BlackMesa.getDimension() << std::endl;  // 2 is expected
	Xen.~Scoring();


	// Test 2: Random antisymmetric matrix generator
	printf("\nRANDOM ANTISYMMETRIC MATRIX GENERATOR\n");
	Xen.RandSkewMatrix(3);
	Xen.PrintSkewMatrix();

	// Problem here: using the GetVariable method on a 2D Dynamical Array
	//std::vector<std::vector<double>> X = Xen.GetMatrix();





	system("pause");
	return 0;
}