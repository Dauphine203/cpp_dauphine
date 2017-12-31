/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: FX Scoring Regression SubClass Methods
*/

#include "scoring.h"
#include "regression.h"

#include <iostream>
#include <vector>
#include <Eigen/Eigen>


Eigen::MatrixXd Regression::ConvertToEigenMatrix() {

	Eigen::MatrixXd matrix(SkewMatrix.size(), SkewMatrix[0].size());
	for (int i = 0; i < SkewMatrix.size(); ++i)
		matrix.row(i) = Eigen::VectorXd::Map(&SkewMatrix[i][0], SkewMatrix[0].size());
	
	return matrix;
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

	// LEAST SQUARES REGRESSION
	Eigen::VectorXd S_ = Eigen::VectorXd::Random(M_.rows());   // Protected variable
	S_ = X_.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(Y_);

	
	// RESULTS FOR PROTECTED VARIABLES
	M = M_;
	X = X_;
	Y = Y_;
	S = S_;
}