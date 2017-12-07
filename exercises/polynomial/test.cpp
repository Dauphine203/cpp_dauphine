#include <iostream>
#include <initializer_list>

// The goal of ths exercise is to implement
// a class modeling a N-degree polynomial with
// traditional arithmetic operations. Process
// step by step so you can incrementally test
// your implementation.

namespace math{
	
	// Phase 1
    // Declare and define a class polynomial with the
    // following methods:
    
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
    
    // Also define an operator<< for printing the polynomial. Only
    // non null coefficients should be printed:
    // polynomial p(5);
    // p[0] = 1.; p[2] = 2.; p[3] = 3.;
    // std::cout << p << std::endl should print:
    // 3. X^4 + 2. X^2 + 1.
	
	class Polynomial {
	
	private:
		double* coefficients;	// Array to store coefficients
		int degree;				// Degreee
	
	public:
		Polynomial();							// Default constructor
		Polynomial(double coeffs[], nterms);	// Initialize poly for given coefficents
		Polynomial(Polynomial&);				// Copy constructor
		Polynomial(double);						// Initialize poly for equal to a const
		~Polynomial();							// Destrucor (efficent memory allocation)
		
		Polynomial operator+(Polynomial p) const;
		Polynomial operator-(Polynomial p) const;
		Polynomial operator*(Polynomial p) const;
		
	
	}; // needed to put ";"
	
}


int main(){
	
	std::cout << "Blade Runner \n" << std::endl;
	
	
	
	return 0;
}