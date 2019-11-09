#ifndef ADDITIONAL_EXERCISES_HPP
#define ADDITIONAL_EXERCISES_HPP

#include <vector>

namespace dauphine
{
    // Exercise 1
    void linear_interpolate(const std::vector<double>& x,
                            const std::vector<double>& y,
                            const std::vector<double>& x_interp,
                            std::vector<double>& res);

    // Exercise 2
    int count_pairs(const std::vector<int>& input);

    // Exercise 3
    int count_pairs(const std::vector<int>& input, int n);
}

#endif
