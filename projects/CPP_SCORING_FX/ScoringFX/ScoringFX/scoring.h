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
		// Dimension of antisymmetric matrix M
		int dim;
		
		// Antisymmetric matrix M
		std::vector<std::vector<double>> M;

	public:
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
		~Scoring() { std::cout << "No regrets Mr. Freeman !" << std::endl; };

		// Copy constructor
		Scoring(const Scoring &other):
			dim(other.dim)
		{
			std::cout << "Copied class" << std::endl;
		};
		
};


class Regression: public Scoring {



};

#endif