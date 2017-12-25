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
		size_t dim;
		
		// Antisymmetric matrix M
		// std::vector<std::vector<double>> M;

	public:
		// Generate a random antisymmetric matrix
		Scoring(size_t N) :
			dim(N)
		{
			std::cout << "Constructed a square matrix of size " << N << std::endl;
		}
		
};


class Regression: public Scoring {



};

#endif