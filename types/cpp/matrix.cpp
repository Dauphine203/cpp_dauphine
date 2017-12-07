#include "matrix.hpp"
#include <iterator>
#include <numeric>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>
namespace dauphine
{	
	matrix::matrix(size_t nb_rows, size_t nb_cols)
	//initialization list: assigning values to data members
        : m_nb_rows(nb_rows),
          m_nb_cols(nb_cols),
          m_data(nb_rows * nb_cols)
    {
    }
	
	std::size_t matrix::nb_rows() const
    {
        return m_nb_rows;
    }

    std::size_t matrix::nb_cols() const
    {
        return m_nb_cols;
    }
	
	void matrix::resizematrix(std::size_t nb_rows, std::size_t nb_cols)
    {
        m_nb_rows = nb_rows;
        m_nb_cols = nb_cols;
        m_data.resize(m_nb_rows * m_nb_cols);
    }
	
	double& matrix::operator()(std::size_t i, std::size_t j)
    {
        return m_data[i * m_nb_cols + j];
    }

    const double& matrix::operator()(std::size_t i, std::size_t j) const
    {
        return m_data[i * m_nb_cols + j];
    }
	
	std::ostream& operator<<(std::ostream& out, const matrix& m)
    {
        for(std::size_t i = 0; i < m.nb_rows(); ++i)
        {
            for(std::size_t j = 0; j < m.nb_cols(); ++j)
            {
                out << m(i, j) << ", ";
            }
            out << std::endl;
        }
        return out;
    }
// when using in main: std::cout<<m;
// the compiler understands:std::cout.operator<<m;
//operator<<(std:cout, m);
	void initmat(matrix& m, std::size_t row, std::size_t col)
	{
		m.resizematrix(row,col);
		for(std::size_t i=0; i<row;i++)
		{
			for(std::size_t j=0; j<col;j++)
			{
				m(i,j)=2*i+j;
			}
		}
	}
	
	/*matrix& matrix::operator+=(const matrix& rhs) // matrix& matrix to return the object
    {
        for(std::size_t i = 0; i < m_nb_rows; ++i)
        {
            for(std::size_t j = 0; j < m_nb_cols; ++j)
            {
                m_data[i * m_nb_cols + j] += rhs.m_data[i * m_nb_cols + j];
            }
        }
        return *this; // this* renvoie la current object matrix
    }*/
	
	matrix& matrix::operator+=(const matrix& rhs)
    {
        std::transform(m_data.begin(), m_data.end(), rhs.m_data.begin(),
                       m_data.begin(), std::plus<double>());
        return *this;
    }
	
	/*matrix& matrix::operator+=(double rhs)
	{
		for(std::size_t i = 0; i < m_nb_rows; ++i)
        {
            for(std::size_t j = 0; j < m_nb_cols; ++j)
            {
                m_data[i * m_nb_cols + j] += rhs;
            }
        }
		return *this;
	}*/
	
    matrix& matrix::operator+=(double rhs)
    {
        std::transform(m_data.begin(), m_data.end(), m_data.begin(),
                       [rhs](double arg) { return arg + rhs; });
        return *this;
    }
}
