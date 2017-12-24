# C++ Currency Ranking Project

**1. ANTISYMMETRIC MATRIX**
- Import CSV or Excel files
- Uses a 2D std::vector (data generation in independent)
- Includes an option for generating random data

**2. CLASS FOR ALL THE SCORING METHODS**
- Checks if the input matrix is really antisymmetric (private). The verification is done with std::vector
- Option to generate random data with std::vector
- 1 general class for all possible scoring models (uses Heritage concept)
- 1 subclass for least squares using Eigen sparse matrix
- 1 subclass for least squares using xtensor with blas/lapack (optional)

**3. IMPLEMENTATION**
- Random data
- Realworld snapshot of 25D Risk Reversal values (1W 21/12/2017)