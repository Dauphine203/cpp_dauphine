/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: FX Scoring Regression SubClass Methods
*/

#include "scoring.h"
#include "regression.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <Eigen/Eigen>
#include <cmath>
#include <cstdlib>
#include <ctime>



Eigen::MatrixXd Regression::ConvertToEigenMatrix() {

	Eigen::MatrixXd matrix(SkewMatrix.size(), SkewMatrix[0].size());
	for (int i = 0; i < SkewMatrix.size(); ++i)
		matrix.row(i) = Eigen::VectorXd::Map(&SkewMatrix[i][0], SkewMatrix[0].size());
	
	return matrix;
}



// Returns the round value of a float a, given the arrondi value b we want, b=2 to get to the 0.01.
double arrondi(double a, int b)
{
	int power;
	double result;
	power = pow(10, b);  // 10^b
	result = floor(a*power) / power;
	return result;
}



void Regression::EigenLeastSquares() {
	
	// GENERATE ANTISYMMETRIC MATRIX (M)
	Eigen::MatrixXd M_(SkewMatrix.size(), SkewMatrix[0].size());    // Protected variable
	for (int i = 0; i < SkewMatrix.size(); ++i)
		M_.row(i) = Eigen::VectorXd::Map(&SkewMatrix[i][0], SkewMatrix[0].size());


	// GENERATE OUTPUT VECTOR (Y)
	int n = M_.rows() * (M_.rows() - 1);
	
	int x = -1;
	Eigen::MatrixXd Y_ = Eigen::MatrixXd::Zero(n, 1);    // Protected variable
	Eigen::MatrixXd Y_ix = Eigen::MatrixXd::Zero(n, 2);
	
	for (int i = 0; i < M_.rows(); i++) {
		for (int j = 0; j < M_.cols(); j++) {

			if (M_(i, j) != 0) {
				x = x + 1;

				// Elements
				Y_(x, 0) = M_(i, j);
				Y_ix(x, 0) = i + 1;
				Y_ix(x, 1) = j + 1;
			}
		}
	}
	

	// GENERATE DESIGN MATRIX (X)
	Eigen::MatrixXd X_ = Eigen::MatrixXd::Zero(Y_.rows(), M_.rows());    // Protected variable

	for (int i = 0; i < Y_.rows(); i++) {

		int s_i = Y_ix(i, 0);
		int s_j = Y_ix(i, 1);

		for (int j = 0; j < M_.rows(); j++) {

			if (j + i == s_i) {
				X_(i, j) = 1.0;
			}
			if (j + 1 == s_j) {
				X_(i, j) = -1.0;
			}
		}
	}

		
	// LEAST SQUARES REGRESSION (S)
	Eigen::VectorXd S_ = Eigen::VectorXd::Random(SkewMatrix.size());   // Protected variable
	S_ = X_.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(Y_);
	

	// OUTER-DIFFERENCE MATRIX (O) OF THE SCORE VECTOR S
	Eigen::MatrixXd O_ = Eigen::MatrixXd::Zero(SkewMatrix.size(), SkewMatrix.size());   // Protected variable
	for (int i = 0; i < SkewMatrix.size(); ++i) {
		for (int j = 0; j < SkewMatrix.size(); ++j) {
				
			O_(i, j) = S_(i) - S_(j);
			O_(i, j) = arrondi(O_(i, j),2); // We want the outer difference to be precise to the hundredth
				
		}
	}
	
	// RESULTS FOR PROTECTED VARIABLES
	M = M_;
	X = X_;
	Y = Y_;
	S = S_;
	O = O_;

	std::cout << "Invoked EigenLeastSquares() successfully." << std::endl;

}



void Regression::PrintResults() const {

	std::cout << std::endl;
	std::cout << "=======================================================" << std::endl;
	std::cout << "SUMMARY OF REGRESSION RESULTS" << std::endl;
	std::cout << "=======================================================" << std::endl;
	std::cout << "Time: " << time(0) << std::endl;
	std::cout << "Method: Least squares (singular value decomposition)" << std::endl;
	std::cout << "External library: Eigen" << std::endl;
	if (ImportedData == true) {
		std::cout << "Data: Imported" << std::endl;
	}
	else {
		std::cout << "Data: Random" << std::endl;
	}
	std::cout << "No. Observations: " << Y.rows() << std::endl;
	std::cout << "No. Currencies: " << dim << std::endl;
	std::cout << "Cost: " << (M - O).squaredNorm() << std::endl;
	std::cout << "=======================================================" << std::endl;
	std::cout << "CURRENCY STRENGTH SCORES" << std::endl;
	bool error = false;
	
	for (int i = 0; i < SkewMatrix.size() ; ++i) {
		
		if (ImportedData == true) {
			// Case 1: Imported Data. Currencies vector rank matches antisymmetric matrix rank
			if (Currencies.size() == SkewMatrix.size()) { std::cout << Currencies[i] << " : " << S(i) << std::endl;
			}
			else {
			// Case 2: Imported Data. Currencies vector rank doesn't match antisymmetric matrix mark
				error = true;
			}
		} else {
			// Case 3: Random data. No need for currency string vector
			std::cout << "Score " << i + 1 << " : " << S(i) << std::endl;
		}
	}
	if (error == true) {
		std::cout << "Error. Rank of currencies vector doesn't match rank of" << std::endl;
		std::cout << "antisymmetric matrix." << std::endl;
		std::cout << "Rank of currencies vector: " << Currencies.size() << std::endl;
		std::cout << "Rank of antisymmetric matrix: " << SkewMatrix.size() << std::endl;
	}

	std::cout << "=======================================================" << std::endl;
	std::cout << std::endl;
}