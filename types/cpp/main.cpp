#include <iostream>
#include "matrix.hpp"
#include "uvector.hpp"
#include <algorithm>
/*
int main(int argc, char* argv[])
    {
        dauphine::matrix m(2, 4);
        // Error: cannot access private member m_nb_rows
        std::cout << m.m_nb_rows << std::endl;
        return 0;
    }*/
int main(int argc, char* argv[])
    {
        //dauphine::matrix m(2, 4);
        //std::cout << m.nb_rows() << std::endl;
        //std::cout << m.nb_cols() << std::endl;
		dauphine::matrix m(5,10);
		//std::cout << m.nb_rows() << std::endl;
        //std::cout << m.nb_cols() << std::endl;
		//m.resizematrix(1,2);
		//std::cout << m.nb_rows() << std::endl;
        //std::cout << m.nb_cols() << std::endl;
		dauphine::initmat(m,2,3);
		m(1,1)=10;	
		std::cout << m << std::endl;
        return 0;
    }
           