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
		int dim;
		/* Dimension of the antisymmetric matrix M
		   It's the number of currencies in our scoring algorithm */
				
		std::vector<std::vector<double>> SkewMatrix;
		/* Antisymmetric matrix (here as a 2D dynamic array) M
		   This is the matrix of pairwise currency skew volatilities
		   Can be ATM volatility, butterfly, risk reversal values, etc. */

		std::vector<std::string> Currencies;
		/* Currencies (vector of strings) */

	public:
		/// CONSTRUCTORS

		Scoring(int D = 2) :
			dim(D)
		{
			std::cout << "Constructed a square matrix of dimension: (" << D << "," << D << ")" << std::endl;
		}
		Scoring(const Scoring &copy) : dim(copy.dim) { std::cout << "Copied class" << std::endl; };
		~Scoring() { std::cout << "TERMINATED" << std::endl; };


		/// NUMBER OF CURRENCIES

		void SetDimension(int dim) { this-> dim = dim; std::cout << "Changed the dimension to: (" << dim << "," << dim << ")" << std::endl; };
		int GetDimension() const { return dim; }


		/// CURRENCIES VECTOR

		void ImportCurrencies(const std::string& path);
		void PrintCurrencies() const;
		std::vector<std::string> GetCurrencies() const { return Currencies; }


		/// ANTISYMMETRIC MATRIX

		void RandomSkewMatrix();
		void ImportSkewMatrix(const std::string& path, const int nb_currencies);
		void PrintSkewMatrix() const;
		std::vector<std::vector<double>> GetSkewMatrix() const { return SkewMatrix; }

};

#endif