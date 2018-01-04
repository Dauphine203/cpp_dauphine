/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: FX Scoring Class Methods
*/

#include "scoring.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>



void Scoring::RandomSkewMatrix() {

	std::vector<std::vector<double>> M(dim, std::vector<double>(dim));
	
	// Initialize matrix (here as a 2D dynamical array)
	srand(time(0));
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			//M[i][j] = (std::rand() % 5) + 1.0; } }
			M[i][j] = (std::rand() % ( 20 - (-20) + 1.0)-20 ; } } // random numbers between -20 et 20

	// Comply the random matrix as an antisymmetric matrix
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (i == j) {
				M[i][j] = 0.0;
			}
			else {
				M[j][i] = -M[i][j];
			}
		}
	}

	// Set "protected" variable as the random antisymmetric matrix
	std::cout << "Invoked RandomSkewMatrix(). Overwritten SkewMatrix." << std::endl;
	std::cout << "Generated SkewMatrix of dimension (" << dim << "," << dim << ")" << std::endl;
	SkewMatrix = M;
}



void Scoring::PrintSkewMatrix() const {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			std::cout << SkewMatrix[i][j] << " , ";
		}
		std::cout << std::endl;
	}
}



void Scoring::ImportSkewMatrix(const std::string& path, const int N) {

	// File
	std::ifstream file(path);
	if (!file) { std::cout << "Cannot open file.\n"; }
	
	// Matrix
	std::vector<std::vector<double>> M(N, std::vector<double>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			file >> M[i][j];
		}
	}
	file.close();

	std::cout << "Invoked ImportSkewMatrix(). Overwritten dim, SkewMatrix." << std::endl;
	
	// Results
	dim = N;
	SkewMatrix = M;
}



void Scoring::ImportCurrencies(const std::string& path) {

	// File
	std::ifstream file(path);
	if (!file.is_open()) { std::cerr << "Unable to open file" << "\n"; std::exit(-1); }

	// Vector
	std::vector<std::string> V;
	std::copy(std::istream_iterator<std::string>(file),
			  std::istream_iterator<std::string>(),
			  std::back_inserter(V));
	file.close();

	std::cout << "Invoked ImportCurrencies(). Overwritten Currencies." << std::endl;
	Currencies = V;
}



void Scoring::PrintCurrencies() const {
	
	for (int i = 0; i < Currencies.size(); i++) {
		std::cout << Currencies[i] << ", ";
	}
	std::cout << std::endl;
}
