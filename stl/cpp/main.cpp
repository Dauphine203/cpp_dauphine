#include <algorithm>
#include <iostream>
#include <iterator>
#include "vector_utils.hpp"
#include "additional_exercises.hpp"

void test_interpolate()
{
    std::vector<double> x = { 1., 2., 3., 4., 5. };
    std::vector<double> y = { 2., 4., 6., 8., 10.};
    std::vector<double> x_interp = { 1.5, 2.5, 3.5, 4.5 };
    std::vector<double> res;

    dauphine::linear_interpolate(x, y, x_interp, res);
    std::cout << "Interpolated values:";
    std::copy(res.cbegin(), res.cend(), std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;
}

void test_count_pairs()
{
    std::vector<int> a = { 0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 8, 8, 9 };
    int res = dauphine::count_pairs(a);
    std::cout << "Number of pairs: " << res << std::endl;

    int res2 = dauphine::count_pairs(a, 3);
    std::cout << "Number of pairs holding 3: " << res2 << std::endl;
}

int main(int, char**)
{
    test_interpolate();
    test_count_pairs();
    return 0;
}

