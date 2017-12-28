/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: FX Scoring Class Methods
*/

#include "scoring.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>


void Scoring::RandomSkewMatrix() {

	int N = dim;
	std::vector<std::vector<double>> matrix(N, std::vector<double>(N));
	
	// Initialize matrix (here as a 2D dynamical array)
	srand(time(0));
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			matrix[i][j] = (std::rand() % 5) + 1.0; } }

	// Comply the random matrix as an antisymmetric matrix
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			if (i == j) {
				matrix[i][j] = 0.0;
			}
			else {
				matrix[j][i] = -matrix[i][j];
			}
		}
	}

	// Set "protected" variable as the random antisymmetric matrix
	std::cout << "Generated random antisymmetric matrix" << std::endl;
	std::cout << std::endl;
	SkewMatrix = matrix;
}


void Scoring::PrintSkewMatrix() const {
	int N = SkewMatrix.size();
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) { std::cout << SkewMatrix[i][j] << " , "; }
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}


void Scoring::ImportSkewMatrix(const std::string& path, const int nb_currencies) {

	// Import
	std::ifstream file(path);
	if (!file) { std::cout << "Cannot open file.\n"; }

	// Matrix
	int D = nb_currencies;
	std::vector<std::vector<double>> matrix(D, std::vector<double>(D));
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < D; j++) {
			file >> matrix[i][j];
		}
	}
	file.close();

	std::cout << "Imported matrix of antisymmetric data" << std::endl;
	std::cout << std::endl;
	SkewMatrix = matrix;
}


void Scoring::ImportCurrencies(const std::string& path) {

	// Import
	std::ifstream file(path); // Path

	if (!file.is_open())
	{
		std::cerr << "Unable to open file" << "\n";
		std::exit(-1);
	}
	// Vector
	std::vector<std::string> vector;
	std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(vector));
	file.close();

	std::cout << "Imported vector of currency tickers" << std::endl;
	std::cout << std::endl;
	Currencies = vector;
}


void Scoring::PrintCurrencies() const {
	
	for (int i = 0; i < Currencies.size(); i++) {
		std::cout << Currencies[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}