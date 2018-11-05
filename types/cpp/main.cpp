#include <iostream>
#include "matrix.hpp"

int main(int argc, char* argv[])
{
    dauphine::matrix m(2, 4);
    std::cout << m.m_nb_rows << std::endl;
    return 0;
}

