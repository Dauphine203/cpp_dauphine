/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: Implementation
*/


/// PACKAGES
#include <iostream>

#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <iomanip>

#include <Eigen/Eigen>


/// FILES
#include "sandbox.h"
#include "scoring.h"
#include "regression.h"


int main(int argc, char* argv[]) {
	
	printf("C++ CLASS FOR RANKING GLOBAL CURRENCIES\n");
	

	/// 1. RANDOM DATA
	/// ##################################################################

	std::cout << "\n1. RANDOM DATA" << std::endl;
	std::cout << "Approximation of an antisymmetrical matrix with the outerdifference of a score vector.\n" << std::endl;
	
	// You invoke Regression subclass of Scoring class here
	// It initializes at 2 currencies, a 2x2 antisymmetric matrix, a 2x1 currency vector
	Regression Xen;
	std::cout << Xen.GetDimension() << std::endl;
	Xen.PrintCurrencies();
	Xen.PrintSkewMatrix();

	// Enter the antisymmetric matrix size of your choice (you should put 5 here)
	int m;
	std::cout << "Enter size of anti-symmetrical matrix for routine: ";
	std::cin >> m;
	Xen.SetDimension(m);
	Xen.RandomSkewMatrix();
	
	// Will not work if Currencies vector rank doesn't match with rank of SkewMatrix
	Xen.EigenLeastSquares();

	// Adjustment (here take 5)
	Xen.SetCurrencies({ "USD", "DKK", "RND" , "CNY", "JPY" });

	Xen.EigenLeastSquares();
	Xen.PrintResults();


	/// 2. IMPORTED DATA
	/// ##################################################################

	std::cout << "\n2. IMPORTED DATA\n" << std::endl;
	std::cout << "Using a real-world snapshot of the 25-Delta risk-reversal values," << std::endl;
	std::cout << "compute a score for a list of at least 15 currencies of the world" << std::endl;
	std::cout << "the criterion described in the previous section, including precious" << std::endl;
	std::cout << "metals.\n" << std::endl;

	Regression Combine;
	Combine.ImportCurrencies("currencies.txt");
	Combine.ImportSkewMatrix("data.txt", 11);  // Only lacking 4 additional currencies and 2 precious metals (Gold, Silver)
	Combine.EigenLeastSquares();
	Combine.PrintResults();

	system("pause");
	return 0;
}