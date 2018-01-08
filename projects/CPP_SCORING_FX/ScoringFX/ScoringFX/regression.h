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

		std::string Method;
		/* Method used for least squares: SVD, Normal equations, QR, Conjugate Gradient */

		bool CheckRegression;
		/* Checks if regression was launched */

		std::vector<std::pair<std::string, double>> Ranks1;
		/* Ranking of scores per currency */

		std::vector<std::pair<int, double>> Ranks2;
		/* Ranking of scores per currency */


	public:
	
		/// CONSTRUCTORS
		Regression(Eigen::MatrixXd M_ = Eigen::MatrixXd::Zero(2,2),
				   Eigen::MatrixXd Y_ = Eigen::MatrixXd::Zero(2,1),
				   Eigen::MatrixXd X_ = Eigen::MatrixXd::Zero(2,2),
				   Eigen::MatrixXd S_ = Eigen::MatrixXd::Zero(2,1),
				   Eigen::MatrixXd O_ = Eigen::MatrixXd::Zero(2,2),
				   std::string m = "",
			       bool b = false) :

			M(M_), Y(Y_), X(X_), S(S_), O(O_), Method(m), CheckRegression(b)
		{
			std::cout << "Invoked Regression(). Initialized Regression Object." << std::endl;
		};

		Regression(const Regression &copy) : M(copy.M), Y(copy.Y), X(copy.X), S(copy.S),
			O(copy.O), Method(copy.Method), CheckRegression(copy.CheckRegression)
		{
			std::cout << "Invoked Copy Regresssion(). Copied Regression Object." << std::endl;
		};

		~Regression() {
			std::cout << "Invoked ~Regression(). Deleted Regression Object." << std::endl;
		};


		/// LEAST SQUARES REGRESSION
		/// GET PROTECTED ATTRIBUTS: M, X, Y, S, Ranks
		void LeastSquaresRegression(std::string method);


		/// GETTERS
		Eigen::MatrixXd GetM() { return M; };
		Eigen::MatrixXd GetY() { return Y; };
		Eigen::MatrixXd GetX() { return X; };
		Eigen::MatrixXd GetS() { return S; };
		Eigen::MatrixXd GetO();

		/// PRINT RESULTS
		void PrintResults() const;


		/// CONVERT 2D DYNAMIC ARRAYS TO EIGEN MATRICES
		Eigen::MatrixXd ConvertToEigenMatrix();

	};

#endif
