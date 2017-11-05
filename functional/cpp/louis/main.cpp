#include <iostream>
#include <iomanip>
#include <cmath>
#include "discount_factor.hpp"
//static int check=1;
//double discount_factor(double rate, double maturity)
//    {
//        double res = std::exp(-rate * maturity);
//        return res;
//    }

//void print_discount_factor(double rate, double maturity=1.0)
//    {
//        double df = discount_factor(rate, maturity);
//        std::cout << "DF(" << maturity << "," << rate << ") = " << df << std::endl;
        // No return statement here
//    }
//

void inc(int i1, int i2)
{
    ++i1;
    ++i2;
}

void client()
{
    int i = 4;
    int j = 5;
    inc(i, j);
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
}

int main(int argc, char* argv[])
{
    double df = ds1::discount_factor(0.04, 1.5);
    return 0;
}
