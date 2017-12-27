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

	protected:
		// Dimension of the antisymmetric matrix M
		// It's the number of currencies in our scoring algorithm
		int dim;
		
		// Antisymmetric matrix M
		// This is the matrix of pairwise currency skew volatilities
		// Can be butterfly, risk reversal values, etc.
		std::vector<std::vector<double>> matrix;

		// Currencies (vector of strings)
		// TBD

	public:
		/*******************************************
		1. CONSTRUCTORS, SETTERS & GETTERS
		********************************************/

		// Default constructor
		// Need to put N = initial value (or else it won't be seen as a default constructor by C++)
		Scoring(int D = 2) : dim(D) { std::cout << "Constructed a square matrix of dimension: (" << D << "," << D << ")" << std::endl; }

		// Copy constructor
		Scoring(const Scoring &copy) : dim(copy.dim) { std::cout << "Copied class" << std::endl; };

		// Destructor
		~Scoring() { std::cout << "No regrets, Mr. Freeman..." << std::endl; };

		// Change default dimension value
		void SetDimension(int dim) {
			this-> dim = dim;
			std::cout << "You have changed the dimension to: (" << dim << "," << dim << ")" << std::endl; };

		// Get dimension value
		int GetDimension() const { return dim; }


		/*******************************************
		2. ANTISYMMETRIC DATA GENERATION
		********************************************/
		// Method 1: GENERATE RANDOM DATA FOR ANTISYMMETRIC MATRIX
		void RandomSkewMatrix();

		// Method 2: Use external data
		/* TO BE DETERMINED */

		// Methods for printing and getting the antisymmetric matrix
		void PrintSkewMatrix() const;
		std::vector<std::vector<double>> GetSkewMatrix() const { return matrix; }

};


class Regression : public Scoring {

	public:
		Regression() { std::cout << "Created Regression subclass of Scoring" << std::endl; }
		//Regression(const Regression &copy) : dim(copy.dim) { std::cout << "Copied class" << std::endl; };
		~Regression() { std::cout << "Status: Observation Terminated" << std::endl; };
		
		void test(int dim) {
			std::cout << dim << std::endl;
		}
		

};


#endif