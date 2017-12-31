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

#include <Eigen/Eigen>


/// FILES
#include "sandbox.h"
#include "scoring.h"
#include "regression.h"


int main(int argc, char* argv[]) {
	
	printf("C++ CLASS FOR RANKING GLOBAL CURRENCIES\n");


	/// ##################################################################
	/// 1. TESTING REGRESSION CLASS
	/// ##################################################################

	printf("\n\nTESTING REGRESSION CLASS\n");

	Scoring Earth;
	Earth.SetDimension(3);
	Earth.RandomSkewMatrix();
	Earth.PrintSkewMatrix();

	Regression Xen;
	Xen.ImportCurrencies("currencies.txt");
	Xen.ImportSkewMatrix("data.txt", 11);
	
	Xen.PrintCurrencies();
	Xen.PrintSkewMatrix();

	std::vector<std::vector<double>> M_ = Xen.GetSkewMatrix();
	std::vector<std::string> C = Xen.GetCurrencies();
	Eigen::MatrixXd M__ = Xen.ConvertToEigenMatrix();
	std::cout << M__ << std::endl;
		

	/// ##################################################################
	/// 2. LEAST SQUARES REGRESSION WITH IMPORTED DATA
	/// ##################################################################
	printf("\n\nLEAST SQUARES REGRESSION WITH IMPORTED DATA\n");

	Xen.EigenLeastSquares();
	Eigen::MatrixXd M = Xen.GetM();
	Eigen::MatrixXd Y = Xen.GetY();
	Eigen::MatrixXd X = Xen.GetX();
	Eigen::MatrixXd S = Xen.GetS();
	
	// Checks
	//std::cout << M(0,1) << std::endl;
	//std::cout << Y(0,0) << std::endl;
	//std::cout << X(0,0) << std::endl;
	//std::cout << S(0,0) << std::endl;
		
	for (int i = 0; i < C.size(); i++) {
		std::cout << C[i] << "  :  " << S(i,0) << std::endl;
	}

	/*
	AUD  :  -0.194037
	GBP  :  -0.1042
	CAD  :  -0.152404
	DKK  :  0.2016
	EUR  :  0.1547
	JPY  :  0.4771
	NZD  :  -0.3118
	NOK  :  -0.2869
	SEK  :  -0.1505
	CHF  :  0.403
	USD  :  -0.0448

	*/


	/// ##################################################################
	/// 3. LEAST SQUARES REGRESSION WITH RANDOM DATA
	/// ##################################################################
	printf("\n\nLEAST SQUARES REGRESSION WITH RANDOM DATA\n");

	Xen.SetDimension(20);
	Xen.RandomSkewMatrix();
	Xen.EigenLeastSquares();
	Eigen::MatrixXd S_rnd = Xen.GetS();
	std::cout << S_rnd << std::endl;

	system("pause");
	return 0;
}