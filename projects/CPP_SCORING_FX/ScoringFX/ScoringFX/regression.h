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
	One possible approach to Scoring is to compute a least squares regression.
	This version uses Eigen.
	*/

	protected:
		Eigen::MatrixXd M;
		/* Antisymmetric matrix of currency pairwise ATM volatility skews */

		Eigen::MatrixXd Y;
		/* Output vector of volatility skews */

		Eigen::MatrixXd X;
		/* Design matrix of currency scores */

		Eigen::MatrixXd S;
		/* Score vector of currencies */

		Eigen::MatrixXd O;
		/* Outer-difference matrix of the score vector */

		double FrobeniusNorm;
		/* Frobenius norm of the difference between M and O */

		bool CheckRegression;
		/* Was the regression successful ? */

	public:
	
		/// CONSTRUCTORS
		Regression() {
			std::cout << "Invoked Regression(). Initialized Regression Object." << std::endl;
		};

		~Regression() {
			std::cout << "Invoked ~Regression(). Deleted Regression Object." << std::endl;
		};


		/// LEAST SQUARES REGRESSION
		/// GET PROTECTED ATTRIBUTS: M, X, Y, S
		void EigenLeastSquares();


		/// GETTERS
		Eigen::MatrixXd GetM() { return M; };
		Eigen::MatrixXd GetY() { return Y; };
		Eigen::MatrixXd GetX() { return X; };
		Eigen::MatrixXd GetS() { return S; };
		Eigen::MatrixXd GetO() { return O; };
		//double GetFNorm() { return FrobeniusNorm; };


		/// PRINT RESULTS
		void PrintResults() const;


		/// SETTERS (just in case)


		/// CONVERT 2D DYNAMIC ARRAYS TO EIGEN MATRICES
		Eigen::MatrixXd ConvertToEigenMatrix();


		/// RANKED CURRENCIES


	};

#endif