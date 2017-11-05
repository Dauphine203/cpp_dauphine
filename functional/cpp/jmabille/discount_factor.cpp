#include <iostream>
#include <iomanip>
#include <cmath>

#include "discount_factor.hpp"

double discount_factor(double rate, double maturity)
{
    double res = std::exp(-rate * maturity);
    return res;
}

void print_discount_factor(double rate, double maturity)
{
    double df = discount_factor(rate, maturity);
    std::cout << "DF(" << maturity << "," << rate << ") = " << df << std::endl;
    // No return statement here
}

