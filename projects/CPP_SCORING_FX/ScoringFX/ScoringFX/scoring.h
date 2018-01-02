/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: FX Scoring Class Initialization
*/

#ifndef SCORING_HPP
#define SCORING_HPP

#include <iostream>
#include <vector>
#include <string>


class Scoring {


	protected:
		/// PROTECTED VARIABLES

		int dim;
		/* Dimension of the antisymmetric matrix M
		   It's the number of currencies in our scoring algorithm */
		
		std::vector<std::string> Currencies;
		/* Currencies (vector of strings) */

		std::vector<std::vector<double>> SkewMatrix;
		/* Antisymmetric matrix (here as a 2D dynamic array) M
		   This is the matrix of pairwise currency skew volatilities
		   Can be ATM volatility, butterfly, risk reversal values, etc. */


	public:
		/// CONSTRUCTORS
		
		Scoring(int D = 2, std::vector<std::string> C = {"Currency 1","Currency 2"}, std::vector<std::vector<double>> M = { {0,1},{-1,0} }) :
			dim(D), Currencies(C), SkewMatrix(M)
		{
			// Initializes for 2 currencies
			// Initializes a default 2x2 antisymmetric matrix
			// Initializes a default 2x1 currency string vector
			std::cout << "Invoked Scoring(). Initialized Scoring Object." << std::endl;
		}
				
		Scoring(const Scoring &copy) : dim(copy.dim), Currencies(copy.Currencies), SkewMatrix(copy.SkewMatrix) {
			std::cout << "Invoked copy Scoring(). Copied Scoring Object." << std::endl;
		};
		
		~Scoring() {
			std::cout << "Invoked ~Scoring(). Deleted Scoring Object." << std::endl;
		};
		

		/// NUMBER OF CURRENCIES

		void SetDimension(int dim) {
			this-> dim = dim;
			std::cout << "Invoked SetDimension(). Changed dimension to " << dim << std::endl;
		};

		int GetDimension() const {
			return dim;
		}


		/// CURRENCIES VECTOR

		// cf. scoring.cpp
		void ImportCurrencies(const std::string& path);

		// cf. scoring.cpp
		void PrintCurrencies() const;

		std::vector<std::string> GetCurrencies() const {
			return Currencies;
		}

		std::vector<std::string> SetCurrencies(const std::vector<std::string>& C) {
			Currencies = C;
			return Currencies;
		}


		/// ANTISYMMETRIC MATRIX

		// cf. scoring.cpp
		void RandomSkewMatrix();

		// cf. scoring.cpp
		void ImportSkewMatrix(const std::string& path, const int N);

		// cf. scoring.cpp
		void PrintSkewMatrix() const;

		std::vector<std::vector<double>> GetSkewMatrix() const {
			return SkewMatrix;
		}

};

#endif