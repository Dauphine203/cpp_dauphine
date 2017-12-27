/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: Implementation
*/

#include <iostream>

#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

//#include <Eigen/dense>
//#include <Eigen/sparse>
//using namespace Eigen;


#include "data_reader.h"
#include "scoring.h"


int main() {
	
	std::cout << "SCORING CLASS FOR RANKING GLOBAL CURRENCIES\n" << std::endl;
	
	std::cout << "Welcome to the H.E.V. Mark 4 protective system." << std::endl;
	std::cout << "For use in hazardous environment conditions.\n" << std::endl;


	// #####################################################################################
	// Test 1: BASIC OOP
	// #####################################################################################
	printf("BASIC OOP TESTING\n");

	Scoring Xen(2);
	Scoring BlackMesa = Xen;
	Xen.SetDimension(3);
	std::cout << "Xen: " << Xen.GetDimension() << std::endl;        // 3 is expected
	std::cout << "BlackMesa: " << BlackMesa.GetDimension() << std::endl;  // 2 is expected
	Xen.~Scoring();
	

	// #####################################################################################
	// Test 2: RANDOM ANTISYMMETRIC MATRIX GENERATOR
	// #####################################################################################
	printf("\nRANDOM ANTISYMMETRIC MATRIX GENERATOR\n");
	
	Xen.RandomSkewMatrix();
	Xen.PrintSkewMatrix();
	std::vector<std::vector<double>> a = Xen.GetSkewMatrix();
	std::cout << "a[0][1]: " << a[0][1] << std::endl;


	// #####################################################################################
	// Test 3: INHERITANCE (Scoring <- Regression)
	// #####################################################################################
	printf("\nINHERITANCE\n");
	Regression GLaDOS;

	// Subclass GlaDOS has access to all the methods of Scoring class
	int t1 = GLaDOS.GetDimension();
	std::cout << t1 << std::endl;
	GLaDOS.~Regression();

	GLaDOS.SetDimension(4);  // Change here the dimension of square matrix
	std::cout << GLaDOS.GetDimension() << std::endl;

	GLaDOS.RandomSkewMatrix();
	GLaDOS.PrintSkewMatrix();


	// #####################################################################################
	// Test 4: READING TEXT FILES
	// #####################################################################################
	printf("\nREADING TEXT FILES\n");
	printf("\n1. Antisymmetric Matrix\n");

	const int D = 11;
	std::ifstream in("data.txt");
	double M[D][D];

	if (!in) { std::cout << "Cannot open file.\n"; }

	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 11; x++) {
			in >> M[x][y];
			std::cout << M[x][y] << " , "; }
		std::cout << std::endl; }
	in.close();

	printf("\n2. List of currencies\n");

	std::ifstream currencies_file("currencies.txt");
	std::vector<std::string> currencies;
	std::copy(std::istream_iterator<std::string>(currencies_file),
		std::istream_iterator<std::string>(),
		std::back_inserter(currencies));

	std::cout << currencies.size() << std::endl;
	for (int i = 0; i < currencies.size(); i++) {
		std::cout << currencies[i] << ", ";
	}
	std::cout << std::endl;


	// #####################################################################################
	// Test 5: TESTING EIGEN
	// #####################################################################################

	// Need to #include Additional libraries a folder with Eigen functions
	/*
	printf("\nTESTING EIGEN\n");
	MatrixXf A = MatrixXf::Random(3, 2);
	VectorXf b = VectorXf::Random(3);
	std::cout << "The solution using the QR decomposition is:\n"
		<< A.colPivHouseholderQr().solve(b) << std::endl;
	*/


	system("pause");
	return 0;
}