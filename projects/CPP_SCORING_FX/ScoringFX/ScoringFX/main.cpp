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


int main() {
	
	printf("C++ CLASS FOR RANKING GLOBAL CURRENCIES\n");


	/// ##################################################################
	/// 1. TESTING REGRESSION CLASS
	/// ##################################################################

	printf("\nTESTING REGRESSION CLASS\n");

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
	Eigen::MatrixXd M = Xen.ConvertToEigenMatrix();
	std::cout << M << std::endl;
	

	/// ##################################################################
	/// 2. LEAST SQUARES REGRESSION
	/// ##################################################################

	int n = M.rows() * (M.rows() - 1);	   // 110
	std::cout << "M.size() = " << M.size() << std::endl;

	int x = -1;
	Eigen::MatrixXd Y = Eigen::MatrixXd::Zero(n, 1);
	std::cout << Y.rows() << std::endl;
	Eigen::MatrixXd Y_ix = Eigen::MatrixXd::Zero(n, 2);

	// OUTPUT VECTOR (Y)
	for (int i = 0; i < M.rows(); i++) {
		for (int j = 0; j < M.cols(); j++) {

			if (M(i, j) != 0){
				x = x + 1;
				// Output vector Y elements
				Y(x, 0) = M(i, j);
				Y_ix(x, 0) = i + 1;
				Y_ix(x, 1) = j + 1;
			}
		}
	}
	std::cout << M.sum() << " , " << Y.sum() << std::endl;
	std::cout << "x = " << x << std::endl;

	// DESIGN MATRIX (X)
	std::cout << "Y_ix.sum() = " << Y_ix.sum() << std::endl;    // 1320
	std::cout << "Y.rows() = " << Y.rows() << std::endl;

	Eigen::MatrixXd X = Eigen::MatrixXd::Zero(Y.rows(), M.rows());

	for (int i = 0; i < Y.rows(); i++) {

		int s_i = Y_ix(i, 0);
		int s_j = Y_ix(i, 1);

		for (int j = 0; j < M.rows(); j++) {

			if (j + i == s_i) {
				X(i, j) = 1.0;
			}
			if (j + 1 == s_j) {
				X(i, j) = -1.0;
			}
		}
	}
	std::cout << "(" << X.rows() << "," << X.cols() << ")" << std::endl;
	std::cout << std::endl;

	// Check matrix sizes
	std::cout << "Dimension of vector Y: (" << Y.rows() << "," << Y.cols() << ")" << std::endl;
	std::cout << "Dimension of matrix X: (" << X.rows() << "," << X.cols() << ")" << std::endl;


	// LEAST SQUARES LINEAR REGRESSION

	// Vector of currency scores (S)
	Eigen::VectorXd S = Eigen::VectorXd::Random(M.rows());

	// METHOD 1: Dense matrix decomposition
	std::cout << "Least-squares solution via SVD:" << std::endl;

	S = X.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(Y);

	std::cout << S << std::endl;

	// METHOD 2: Sparse matrix decomposition (= overkill, gives same result as Dense)
	S = Eigen::VectorXd::Random(M.rows());

	std::cout << "Least-squares solution via Conjugate Gradient:" << std::endl;
	Eigen::LeastSquaresConjugateGradient<Eigen::MatrixXd> lscg;
	lscg.compute(X);
	S = lscg.solve(Y);
	std::cout << "iterations: " << lscg.iterations() << std::endl;  // iterations = 2
	std::cout << "estimated error: " << lscg.error() << std::endl;
	S = lscg.solve(Y);

	std::cout << S << std::endl;
	std::cout << std::endl;

	// RANKING OF CURRENCIES
	for (int i = 0; i < C.size(); i++) {
		std::cout << C[i] << "   :   " << S[i] << std::endl;
	}

	/*

	AUD   :   -0.194862
	GBP   :   -0.104
	CAD   :   -0.153486
	DKK   :   0.202
	EUR   :   0.153
	JPY   :   0.48
	NZD   :   -0.314
	NOK   :   -0.287
	SEK   :   -0.15
	CHF   :   0.404
	USD   :   -0.044

	*/

	system("pause");
	return 0;
}