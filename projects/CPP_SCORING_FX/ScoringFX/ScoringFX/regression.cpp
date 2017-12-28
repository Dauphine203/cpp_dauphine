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


void Regression::EigenInputs() {



}


void Regression::EigenLeastSquares() {
	


}