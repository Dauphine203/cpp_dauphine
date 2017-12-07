#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <ostream>
#include <iterator>
#include <numeric>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>
namespace dauphine
{
	class matrix
    {
    public:
        
        matrix(std::size_t nb_rows, std::size_t nb_cols);

        std::size_t nb_rows() const;
        std::size_t nb_cols() const;
		
		void resizematrix(std::size_t nb_rows, std::size_t nb_cols);
		
		double& operator()(std::size_t i, std::size_t j);
		// a= m(1,2) or m(1,2)=5, use to modify
		
        const double& operator()(std::size_t i, std::size_t j) const;
		// use to read the value
		// twice const, first because we are returning a const and 2nd because we do not modify the things inside
		
		// parentesis after operator because we need to use parentesis to feed arguments
		matrix& operator+=(const matrix& rhs);
        //matrix& operator-=(const matrix& rhs);
        //matrix& operator*=(const matrix& rhs);
        //matrix& operator/=(const matrix& rhs);// rhs= right hand side
		matrix& operator+=(double rhs);
        //matrix& operator-=(double rhs);
        //matrix& operator*=(double rhs);
        //matrix& operator/=(double rhs);
		
		
    private: // can be accessed only internally so if I want a method to return it I need to define it in the public part,
//	I cannot access the elements directly out from the class

        std::size_t m_nb_rows;
        std::size_t m_nb_cols;
        std::vector<double> m_data;
    };
	
	std::ostream& operator<<(std::ostream& out, const matrix& m);
	void initmat(matrix& m, std::size_t row, std::size_t col);
	
}

#endif

