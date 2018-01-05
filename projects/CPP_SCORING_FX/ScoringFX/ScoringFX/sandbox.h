/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: Sandbox for testing
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

#include <Eigen/Eigen>

#include <istream>

namespace sandbox {
	
	/// IMPORTING THE LIST OF CURRENCIES
	
	std::vector<std::string> ImportCurrenciesX(const std::string& path){
		// Import
		std::ifstream file(path); // Path

		if (!file.is_open())
		{ std::cerr << "Unable to open file" << "\n";
		  std::exit(-1); }
		// Vector
		std::vector<std::string> vector;
		std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(vector));
		file.close();

		return vector;
	}
	

	/// IMPORTING THE ANTISYMMETRIC MATRIX DATA

	std::vector<std::vector<double>> ImportSkewMatrixX(const std::string& path, const int nb_currencies) {
		
		// Import
		std::ifstream file(path);
		if (!file) { std::cout << "Cannot open file.\n"; }

		// Matrix
		int D = nb_currencies;
		std::vector<std::vector<double>> matrix(D, std::vector<double>(D));
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < D; j++) {
				file >> matrix[i][j]; } }
		file.close();

		return matrix;
	}


	/// CONVERT TO EIGEN MATRICES
	
	Eigen::MatrixXd ConvertToEigenMatrixX(std::vector<std::vector<double>> data)
	{
		Eigen::MatrixXd eMatrix(data.size(), data[0].size());
		for (int i = 0; i < data.size(); ++i)
			eMatrix.row(i) = Eigen::VectorXd::Map(&data[i][0], data[0].size());
		return eMatrix;
	}


	/// COUNT AUTOMATICALLY THE NUMBER OF CURRENCIES
	// Suggestion to have a dynamic dimension integer that adapts to data.txt length
	// Will be integrated with the import data.txt function

	int nb_currency(const std::string path)
	{
		int number_of_lines = 0;
		int dim = 0;

		std::ifstream myfile(path);
		std::string line;
		while (myfile.good())
		{
			getline(myfile, line);
			++number_of_lines;
		}

		dim = number_of_lines;
		return dim;
	}
}