#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>


namespace functions
{
    // The goal of ths exercise is to implement
    // a class modeling a N-degree polynomial with
    // traditional arithmetic operations. Process
    // step by step so you can incrementally test
    // your implementation.
    //
    // Pay attention to the const-correctness
    
    // Phase 1
    // Declare and define a class polynomial with the
    // following methods:
    //
    // - a constructor taking the degree of the polynomial
    // as its parameter
    // - a constructor taking an std::initializer_list<double>
    // so one can initialize the polynomial in a single line.
    // The initializer list should start with the highest degree
    // coefficient and end with the lowest (reverse order)
    // - operator[] for reading and writing coefficients
    // of given degree. Coefficient are stored in ascending
    // degree; if p is a 4-degree polynomial, p[0] is the
    // coefficient of degree 0, p[1] the one of degree1 and
    // so on.
    // - degree(), a method that returns the degree of
    // the coefficient.
    // - eval(double x), a method that returns the evaluation
    // of the polynomial at the given point
    //
    // Also define an operator<< for printing the polynomial. Only
    // non null coefficients should be printed:
    // polynomial p(5);
    // p[0] = 1.; p[2] = 2.; p[3] = 3.;
    // std::cout << p << std::endl should print:
    // 3. X^4 + 2. X^2 + 1.
    
	class polynomial {
	
		private:
			int D;
	
		public:
			// CONSTRUCTOR: Initialize polynomial
			polynomial(int choiceD = 2)
					   :D(choiceD)
			{
				// Set degree
				D = choiceD;
				std::cout << "Created an instance of class polynomial" << std::endl;
				std::cout << "Degree: " << D << std::endl;
				
				// Initialize coefficients
				std::vector<double> polycoefs(D);
				
				// From highest to lowest
				for (auto i : polycoefs){
					std::cout << polycoefs[i] << ",";
				}
				std::cout << std::endl;
			}
			
			void printSymbol(){
				
				for (int i; i < D; ++i){
					std::cout << " + " << polycoefs[i] << "X^" << i;
				}
				
			}
			
			
			// CONSTRUCTOR: Coefficients
			

	
    // Phase 2
    // - Implement the addition and substraction operations for polynomials.
    // Don't forget the overloads involving a polynomial and a scalar.
    // - Implement comparison operator (operator== and operator!=) out of
    // the polynomial class.
    // TIP: you can either declare them as friend in the polynomial class
    // or make them rely on a public method of the polynomial called "equal"
    // that would perform the comparison. In that later case, operator==
    // and operator!= should be one-liners.

    // Phase 3
    // - Implement the multiplication of a polynomial by a scalar
    // - Implement the multiplication of 2 polynomials
    // Process in 3 steps
    // a] Start with a naive implementation (loops without any optimization)
    // b] Avoid useless operations (when a coefficient is 0)
    // c] Try to refine your implementation with the STL algorithms 
    // Note: you can skip step c] in a first time and come back to it when
    // you've implemented all the features of the polynomial class.

    // Phase 4
    // - Implement the division of a polynomial by a scalar
    // - Implement the euclidian division of polynomials
    //     operator/ returns the quotient
    //     operator% returns the remainder
	
};

}

#endif

