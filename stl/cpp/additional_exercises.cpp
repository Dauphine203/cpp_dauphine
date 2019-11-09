#include "additional_exercises.hpp"
#include <algorithm>
#include <array>
#include <numeric>

namespace dauphine
{

/*
 * Exercise 1
 *
 * Write a linear interpolation function that takes 3 input vectors:
 *
 * - x: the abscissa
 * - y: the ordinates
 * - x_interp: the abscissa of the wanted values
 *
 * and an output vector res, holding the ordinates of the interpolated points.
 *
 * That is, for each abscissa a in x_interp such that x1 < a < x2, res holds a value
 * v_res such that (a, v_res) is the linear interpolation of (x1, y1) and (x2, y2).
 */

    double linear_interpolate(double x1, double x2, double y1, double y2, double x)
    {
        double alpha = (x - x1) / (x2 - x1);
        return alpha * y2 + (1 - alpha) * y1;
    }

    void linear_interpolate(const std::vector<double>& x,
                            const std::vector<double>& y,
                            const std::vector<double>& x_interp,
                            std::vector<double>& res)
    {
        res.resize(x_interp.size());
        ptrdiff_t hint = 0;
        std::transform(x_interp.begin(), x_interp.end(), res.begin(),
                       [&x, &y, &hint](double abs)
        {
            auto low = std::upper_bound(x.begin() + hint, x.end(), abs);
            if(low == x.end())
            {
                low -= 2;
            }
            else if(low != x.begin())
            {
                --low;
            }
            auto up = low + 1;
            hint = low - x.begin();
            auto yit = y.begin() + hint;
            return linear_interpolate(*low, *up, *yit, *(yit + 1), abs);
        });
    }

/*
 * Exercise 2
 *
 * Given a std::vector<int> holding values between 0 and 9,
 * count the numbers of pairs with sum equal to 9.
 *
 * For instance, if the input vector is { 0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 8, 8, 9 },
 * the result is 5: (0, 9), (1, 8), (3, 6), (3, 6), (4, 5).
 *
 * A number can be consumed only once to from such a pair.
 *
 * We assume the input vector is sorted.
 */

    int count_pairs(const std::vector<int>& input)
    {
        std::array<int, 10> count = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        std::for_each(input.cbegin(), input.cend(), [&count](int v)
        {
            ++count[static_cast<size_t>(v)];
        });
        std::transform(count.begin(), count.begin() + 5, count.rbegin(),
                       count.begin(), [](int a, int b) { return std::min(a, b); });
        return std::accumulate(count.begin(), count.begin() + 5, 0);
    }

/*
 * Exercise 3
 *
 * Given a std::vector<int> holding values between 0 and 9, and an integer n,
 * count the numbers of pairs with sum equal to 9 that hold n as their first value
 *
 * For instance, if the input vector is { 0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 8, 8, 9 } and n = 3,
 * the result is 2:
 *
 * A number can be consumed only once to form such a pair.
 *
 * We assume the input vector is sorted.
 * 
 *
 */

    int count_pairs(const std::vector<int>& input, int n)
    {
        int comp = 9 - n;
        auto it = std::lower_bound(input.begin(), input.end(), n);
        auto it2 = std::lower_bound(it, input.end(), comp);

        int res = 0;

        while(*it++ == n && *it2++ == comp)
        {
            ++res;
        }

        return res;
    }
}

