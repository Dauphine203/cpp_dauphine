#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>
#include <vector>

namespace dauphine
{
    class matrix
    {
    public:

        matrix(std::size_t nb_rows, std::size_t nb_cols);

    private:

        std::size_t m_nb_rows;
        std::size_t m_nb_cols;
        std::vector<double> m_data;
    };
}

#endif

