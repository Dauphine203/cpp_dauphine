// SANDBOX
// -- MULTIDIMENSIONAL ARRAYS/VECTORS --

// To compile for Windows users:

// mkdir build
// cd build
// cmake -G "NMake Makefiles" ..
// nmake

#include <iostream>
#include <vector>

int main(){
	
	// Creating multidimensional arrays
	std::cout << "Creating multidimensional ARRAYS" << std::endl;
	
	int mat[2][3] = {{11,12,13},{21,22,23}};
	
	// 11, 12, 13
	// 21, 22, 23
	
	std::cout << mat[1][2] << std::endl;
	
	// Printing multidimensional arrays
	std::cout << "\nPrinting multidimensional ARRAYS\n" << std::endl;
	
	for(int i=0; i<2; i++){
		for (int j=0; j<3; j++){
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	// Multidimensional vectors
	std::cout << "\nGenerating multidimensional VECTORS\n" << std::endl;
	
	size_t s;
	std::cin >> s;
	std::vector<std::vector<double>> A(s, std::vector<double>(s));
	
	int k = 0;
	for (size_t i=0; i<s; i++){
		for (size_t j=0; j<s; j++){
			A[i][j] = k++;
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	// Function for printing multidimensional arrays/vectors
	// std::cout << "\nFUNCTION\n" << std::endl;
	// TBC
	
	return 0;
}