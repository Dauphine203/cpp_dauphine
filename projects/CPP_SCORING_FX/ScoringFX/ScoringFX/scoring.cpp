/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: FX Scoring Class Methods
*/

#include "scoring.h"
#include <cstdlib>
#include <ctime>


void Scoring::RandomSkewMatrix() {

	int N = dim;
	std::vector<std::vector<double>> M(N, std::vector<double>(N));
	
	// Initialize matrix (here as a 2D dynamical array)
	srand(time(0));
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			M[i][j] = (std::rand() % 5) + 1.0; } }

	// Comply the random matrix as an antisymmetric matrix
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			if (i == j) {
				M[i][j] = 0.0;
			}
			else {
				M[j][i] = -M[i][j];
			}
		}
	}

	// Set private variable as the random antisymmetric matrix
	SkewMatrix = M;
}


void Scoring::PrintSkewMatrix() const {
	int N = SkewMatrix.size();
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) { std::cout << SkewMatrix[i][j] << " , "; }
		std::cout << std::endl; }
}
