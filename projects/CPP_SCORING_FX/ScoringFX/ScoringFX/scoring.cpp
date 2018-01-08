/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: FX Scoring Class Methods
*/


// Packages
#include "scoring.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>



void Scoring::RandomSkewMatrix(int D) {

	std::vector<std::vector<double>> M(D, std::vector<double>(D));
	
	// Initialize matrix (here as a 2D dynamical array)
	srand(time(0));

	for (int i = 0; i < D; i++) {
		for (int j = 0; j < D; j++) {
			// Between -20 to +20
			M[i][j] = (std::rand() % ( 20 - (-20) + 1) - 20 );
		}
	}

	// Comply the random matrix as an antisymmetric matrix
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < D; j++) {
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
	std::cout << "Generated SkewMatrix of dimension (" << D << "," << D << ")" << std::endl;
	
	// Protected varaibles
	dim = D;
	SkewMatrix = M;
	ImportedData = false;
}



void Scoring::PrintSkewMatrix() const {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			std::cout << SkewMatrix[i][j] << " , ";
		}
		std::cout << std::endl;
	}
}



void Scoring::ImportSkewMatrix(const std::string& path) {

	// Count dynamically nb. of currencies
	int N = 0;

	std::ifstream file(path);
	std::string line;
	while (file.good()) {
		getline(file, line);
		++N;
	}
	file.close();

	// Matrix
	// Can't reuse ifstream file(path) or else it fails to import (unknown reason)
	std::ifstream f(path);
	std::vector<std::vector<double>> M(N, std::vector<double>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			f >> M[i][j];
		}
	}
	f.close();

	std::cout << "Invoked ImportSkewMatrix(). Overwritten dim, SkewMatrix, ImportedData." << std::endl;

	// Results
	dim = N;
	SkewMatrix = M;
	ImportedData = true;
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


void Scoring::loadFromCSV(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	std::vector< std::vector<std::string> > matrix;
	std::vector<std::string>row;
	std::string line;
	std::string cell;

	while (file)
	{
		std::getline(file, line);
		std::stringstream lineStream(line);
		row.clear();

		while (std::getline(lineStream, cell, ','))
			row.push_back(cell);

		if (!row.empty())
			matrix.push_back(row);
	}

	for (int i = 0; i<int(matrix.size()); i++)
	{
		for (int j = 0; j<int(matrix[i].size()); j++)
			std::cout << matrix[i][j] << " ";

		std::cout << std::endl;
	}

}