/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: FX Scoring Class Initialization
*/

#ifndef SCORING_HPP
#define SCORING_HPP

#include <iostream>
#include <vector>
#include <string>


class Scoring {

	/*
	This class is for managing the data for our scoring algorithm.
	If need to add different versions for regression, one simply has
	to declare heritage between this class and the newer regression
	subclass implementation.
	*/

	protected:
		/// PROTECTED VARIABLES

		int dim;
		/* Dimension of the antisymmetric matrix M
		   It's the number of currencies in our scoring algorithm */
		
		std::vector<std::string> Currencies;
		/* Currencies (vector of strings) */

		std::vector<std::vector<double>> SkewMatrix;
		/* Antisymmetric matrix (here as a 2D dynamic array) M
		   This is the matrix of pairwise currency skew volatilities
		   Can be ATM volatility, butterfly, risk reversal values, etc. */

		bool ImportedData;
		/* ImportedData = false (Random)
		   ImportedData = true  (Imported) */

	public:
		/// DEFAULT CONSTRUCTOR
		Scoring(int D = 2,
			std::vector<std::string> C = {"", ""},
			std::vector<std::vector<double>> M = { {0,1},{-1,0} },
			bool B = false) :

			dim(D), Currencies(C), SkewMatrix(M), ImportedData(B)
		{
			/* Initializes for 2 currencies
			   Initializes a default 2x2 antisymmetric matrix
			   Initializes a default 2x1 currency string vector */
			std::cout << "Invoked Scoring(). Initialized Scoring Object." << std::endl;
		}
		

		/// COPY CONSTRUCTOR
		Scoring(const Scoring &copy) : dim(copy.dim), Currencies(copy.Currencies),
			SkewMatrix(copy.SkewMatrix), ImportedData(copy.ImportedData)
		{
			std::cout << "Invoked Copy Scoring(). Copied Scoring Object." << std::endl;
		};
		

		/// DESTRUCTOR
		~Scoring() {
			std::cout << "Invoked ~Scoring(). Deleted Scoring Object." << std::endl;
		};
		

		/// NUMBER OF CURRENCIES
		/* Removed the option to set the Dimension manually. The dimension
		   gets changed when you invoke the RandomSkewMatrix() or ImportSkewMatrix().
		   You can't change dim through a SetDimension() command. */

		int GetDimension() const {
			return dim;
		}


		/// CURRENCIES VECTOR

		// cf. scoring.cpp
		void ImportCurrencies(const std::string& path);

		// cf. scoring.cpp
		void PrintCurrencies() const;

		std::vector<std::string> GetCurrencies() const {
			return Currencies;
		}

		std::vector<std::string> SetCurrencies(const std::vector<std::string>& C) {
			Currencies = C;
			return Currencies;
		}


		/// ANTISYMMETRIC MATRIX

		// cf. scoring.cpp
		void RandomSkewMatrix(int D);

		// cf. scoring.cpp
		void ImportSkewMatrix(const std::string& path);

		// cf. scoring.cpp
		void PrintSkewMatrix() const;

		std::vector<std::vector<double>> GetSkewMatrix() const { return SkewMatrix; }


		/// IMPORT CSV DATA
		void Scoring::loadFromCSV(const std::string& filename);


};

#endif