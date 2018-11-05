#include "matrix.hpp"

namespace dauphine
{
    matrix::matrix(std::size_t nb_rows, std::size_t nb_cols)
        : m_nb_rows(nb_rows),
          m_nb_cols(nb_cols),
          m_data(nb_rows * nb_cols)
    {
    }
}
