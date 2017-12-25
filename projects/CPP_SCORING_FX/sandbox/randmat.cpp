// SANDBOX
// -- RANDOM ANTISYMMETRIC MATRIX --

// To compile for Windows users:

// mkdir build
// cd build
// cmake -G "NMake Makefiles" ..
// nmake

#include <iostream>
#include <cstdlib>
#include <ctime> // Access time in computer
#include <vector>


int main(){
	
	// 1. RANDOM NUMBERS
	// Generate a list of random numbers
	// It appears random, but it will always generate
	// the same variables
	for (int x=0; x<5; x++){
		std::cout << 1+(std::rand()%6) << std::endl;
	}
	
	std::cout << std::endl;
	
	// You need to add srand() for seed
	srand(41);
	for (int x=0; x<5; x++){
		std::cout << 1+(std::rand()%6) << std::endl;
	}
	
	std::cout << std::endl;
	
	// To make the seed random, we use computer time
	// as our seed
	srand(time(0));
	for (int x=0; x<5; x++){
		std::cout << 1+(std::rand()%6) << std::endl;
	}
	
	std::cout << std::endl;
	
	// 2. RANDOM MULTIDIMENSIONAL VECTOR
	// Let's apply this to a multidimensional vector (not
	// with Eigen yet)
	
	// You cannot use arrays, use matrices
	int N;
	std::cout << "Square matrix size: ";
	std::cin >> N;
	std::vector<std::vector<double>> M(N, std::vector<double>(N));
	
	for (int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			M[i][j] = (rand()%5) + 1.0;
		}
	}
	
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){ std::cout << M[i][j] << " " ; }
		std::cout << std::endl; }
	
	std::cout << std::endl;
	
	// To transform it as an antisymmetric matrix
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (i == j){
				M[i][j] = 0.0;
			} else {
				M[j][i] = -M[i][j];
			}
		}
	}
	
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){ std::cout << M[i][j] << " " ; }
		std::cout << std::endl; }
	
	std::cout << std::endl;
	
	system("pause");
	
	std::cout << M.size() << std::endl;  // N
	
	return 0;
}