/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: FX Scoring Class Initialization
*/

#ifndef SCORING_HPP
#define SCORING_HPP

#include <iostream>
#include <vector>


class Scoring {

	private:
		// Dimension of the antisymmetric matrix M
		// It's the number of currencies in our scoring algorithm
		int dim;
		
		// Antisymmetric matrix M
		// This is the matrix of pairwise currency skew volatilities
		// Can be butterfly, risk reversal values, etc.
		std::vector<std::vector<double>> matrix;

	public:
		/*******************************************
		1. BASICS
		********************************************/

		// Default constructor
		Scoring(int N) :
			dim(N)
		{
			std::cout << "Constructed a square matrix of size " << N << std::endl;
		}

		// Change default dimension value
		void setDimension(int dim) {
			this-> dim = dim;
			std::cout << "You changed the dimension to " << dim << std::endl;
		};

		// Get dimension value
		int getDimension() const {
			return dim;
		}

		// Destructor
		~Scoring() { std::cout << "No regrets, Mr. Freeman !" << std::endl; };

		// Copy constructor
		Scoring(const Scoring &other):
			dim(other.dim)
		{
			std::cout << "Copied class" << std::endl;
		};


		/*******************************************
		2. DATA GENERATION
		********************************************/
		// Method 1: Generate random data
		void RandSkewMatrix(int dim);

		// Method 2: Use external data
		// TBD

		// Printing and getting matrices
		void PrintSkewMatrix() const;
		//std::vector<double> GetMatrix() const;
		
};


class Regression: public Scoring {



};



class Eigen : public Regression {



};

#endif