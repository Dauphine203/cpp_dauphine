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



void Regression::LeastSquaresRegression(std::string method) {
	
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

	Eigen::VectorXd S_ = Eigen::VectorXd::Random(SkewMatrix.size());  // Protected variable

	// Method 1: Singular Value Decomposition
	if (method == "SVD"){
		Method = "by Singular Value Decomposition";
		S_ = X_.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(Y_);
	}

	// Method 2: QR Decomposition
	else if (method == "QR") {
		Method = "by QR Decomposition";
		S_ = X_.colPivHouseholderQr().solve(Y_);
	}

	// Method 3: Normal Equations
	else if (method == "NE") {
		Method = "by Normal Equations";
		S_ = (X_.transpose() * X_).ldlt().solve(X_.transpose() * Y_);
	}

	// Method 4: Conjugate Gradient Descent
	else if (method == "CG") {
		Method = "by Conjugate Gradient";
		Eigen::LeastSquaresConjugateGradient<Eigen::MatrixXd> lscg;
		lscg.compute(X_);
		S_ = lscg.solve(Y_);
	}
	else {
		std::cout << "Error. Requires specification of least squares method." << std::endl;
		std::cout << "Choices available: SVD, QR, Normal equations (NE), Conjugate Gradient Descent (CG)" << std::endl;
	}



	// OUTER-DIFFERENCE MATRIX (O) OF THE SCORE VECTOR S
	Eigen::MatrixXd O_ = Eigen::MatrixXd::Zero(SkewMatrix.size(), SkewMatrix.size());   // Protected variable
	for (int i = 0; i < SkewMatrix.size(); ++i) {
		for (int j = 0; j < SkewMatrix.size(); ++j) {
				
			O_(i, j) = S_(i) - S_(j);
			//O_(i, j) = arrondi(O_(i, j),2); // We want the outer difference to be precise to the hundredth
				
		}
	}
	
	// UPDATE PROTECTED VARIABLES
	M = M_;							// Antisymmetric matrix
	X = X_;							// Design matrix (X)
	Y = Y_;							// Output vector (Y)
	S = S_;							// Score vector (S)
	O = O_;							// Outerdifference matrix of score vector (O)
	CheckRegression = true;

	std::cout << "Invoked EigenLeastSquares() successfully." << std::endl;

}

//Merge the currency-vector and the score-vector
void MergeVectors(std::vector<std::string> svect, std::vector<double> nvect, std::vector<std::pair<std::string, double>> &vect)
{
	vect.resize(svect.size());

	for (int i = 0; i < svect.size();i++)
	{
		vect[i] = std::make_pair(svect[i],nvect[i]);
	}
}

//Ranks the currencies according to the score
void tri(std::vector<std::pair<std::string, double>> &vect)
{
	for (int i = 0; i < vect.size() - 1; i++)
	{
		int minimum = i;
		for (int j = i + 1; j < vect.size(); j++)
		{
			if (vect[j].second < vect[minimum].second)
			{
				minimum = j;
			}
		}
		if (minimum != i)
		{
			std::string temp1;
			double temp2;
			temp1 = vect[i].first;
			temp2 = vect[i].second;
			vect[i].first = vect[minimum].first;
			vect[i].second = vect[minimum].second;
			vect[minimum].first = temp1;
			vect[minimum].second = temp2;
		}
	}
}

void Regression::PrintResults() const {

	if (CheckRegression == true){

		std::cout << std::endl;
		std::cout << "=========================================================" << std::endl;
		std::cout << "SUMMARY OF RESULTS" << std::endl;
		std::cout << "=========================================================" << std::endl;
		std::cout << "Time: " << time(0) << std::endl;
		std::cout << "Method: Least Squares " << Method << std::endl;
		std::cout << "External library: Eigen" << std::endl;
		if (ImportedData == true) {
			std::cout << "Data: Imported" << std::endl;
		}
		else {
			std::cout << "Data: Random" << std::endl;
		}
		std::cout << "No. Observations: " << Y.rows() << std::endl;
		std::cout << "No. Currencies: " << dim << std::endl;
		std::cout << "Frobenius Norm (approximation cost): " << (M - O).squaredNorm() << std::endl;
		std::cout << "=========================================================" << std::endl;
		std::cout << "CURRENCY STRENGTH SCORES" << std::endl;
		bool error = false;
	
		
		if (ImportedData == true) {
			// Case 1: Imported Data. Currencies vector rank matches antisymmetric matrix rank
			if (Currencies.size() == SkewMatrix.size()) { 
				std::vector<std::pair<std::string, double>> v;
				MergeVectors(s, n, v);
				tri(Currencies, SkewMatrix, v);
				for(int = 0; i < v.size(); i++){
					std::cout << v[i].first << ":" << v[i].second << std::endl;					}
				}
			}
			else {
			// Case 2: Imported Data. Currencies vector rank doesn't match antisymmetric matrix rank
				error = true;
			}
		else {
		// Case 3: Random data. No need for currency string vector
			for (int i = 0; i < SkewMatrix.size() ; ++i){
				std::cout << "Score " << i + 1 << " : " << S(i) << std::endl;
			}
		}
		if (error == true) {
			std::cout << "Error. Rank of currencies vector doesn't match rank of" << std::endl;
			std::cout << "antisymmetric matrix." << std::endl;
			std::cout << "Rank of currencies vector: " << Currencies.size() << std::endl;
			std::cout << "Rank of antisymmetric matrix: " << SkewMatrix.size() << std::endl;
		}

		std::cout << "=========================================================" << std::endl;
		std::cout << std::endl;
	
	}
	else {
		std::cout << std::endl;
		std::cout << "Error. No regression detected. Use LeastSquaresRegression()." << std::endl;
		std::cout << std::endl;
	}
	
}
