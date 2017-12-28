/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: FX Scoring Regression SubClass Initialization
*/

#ifndef REGRESSION_HPP
#define REGRESSION_HPP


#include "scoring.h"
#include <iostream>
#include <vector>
#include <Eigen/Eigen>


class Regression : public Scoring {

	/*
	One possible approach to Scoring to compute a least squares regression.
	This version uses Eigen.
	*/

	protected:
		Eigen::MatrixXd M;
		Eigen::MatrixXd Y;
		Eigen::MatrixXd X;
		Eigen::MatrixXd S;

	public:
	
		/// CONSTRUCTORS
		Regression() { std::cout << "Created Regression subclass of Scoring" << std::endl; }
		~Regression() { std::cout << "STATUS: Observation Terminated" << std::endl; };


		/// GENERATE "TARGET" VECTOR Y - "DESIGN" MATRIX X
		void EigenInputs();


		/// GETTERS
		Eigen::MatrixXd getM() { return M; };
		Eigen::MatrixXd getY() { return Y; };
		Eigen::MatrixXd getX() { return X; };
		Eigen::MatrixXd getS() { return S; };


		/// CONVERT 2D DYNAMIC ARRAYS TO EIGEN MATRICES
		Eigen::MatrixXd ConvertToEigenMatrix();


		/// LEAST SQUARES REGRESSION
		void EigenLeastSquares();

	};

#endif