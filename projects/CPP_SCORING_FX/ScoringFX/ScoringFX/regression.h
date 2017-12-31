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
		Regression() { std::cout << "INITIALIZATION: subclass Regression" << std::endl; }
		~Regression() { std::cout << std::endl; };


		/// LEAST SQUARES REGRESSION
		/// GET PROTECTED ATTRIBUTS: M, X, Y, S
		void EigenLeastSquares();


		/// GETTERS
		Eigen::MatrixXd GetM() { return M; };
		Eigen::MatrixXd GetY() { return Y; };
		Eigen::MatrixXd GetX() { return X; };
		Eigen::MatrixXd GetS() { return S; };


		/// CONVERT 2D DYNAMIC ARRAYS TO EIGEN MATRICES
		Eigen::MatrixXd ConvertToEigenMatrix();


		/// RANKED CURRENCIES


	};

#endif