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
	

	std::cout << "A C++ SCORING ALGORITHM FOR RANKING GLOBAL CURRENCIES BASED ON FINANCIAL MARKET SENTIMENT\n" << std::endl;
	std::cout << "A simple method for ranking currencies based on their relative stability\n" << std::endl;
	

	/// 1. RANDOM DATA
	/// ##################################################################

	std::cout << "\n1. ROUTINE" << std::endl;
	std::cout << "Using the C++ programming language (and testing with generated data), produce a routine performing the" << std::endl;
	std::cout << "approximation of an antisymmetrical matrix with the outerdifference of a score vector.\n" << std::endl;
	
	// Implementation
	Regression Xen;
	Xen.RandomSkewMatrix(20);
	Xen.EigenLeastSquares();
	Xen.PrintResults();

	system("pause");


	/// 2. IMPORTED DATA
	/// ##################################################################

	std::cout << "\n\n2. REAL-WORLD SNAPSHOT" << std::endl;
	std::cout << "Using a real-world snapshot of the 25-Delta risk reversal values, compute a ''score'' for a list of at least 15" << std::endl;
	std::cout << "currencies of the world following the criterion described in the previous section, including precious metals.\n" << std::endl;

	// Implementation
	Xen.ImportSkewMatrix("data.txt");
	Xen.ImportCurrencies("currencies.txt");
	Xen.EigenLeastSquares();
	Xen.PrintResults();

	system("pause");
	return 0;
}