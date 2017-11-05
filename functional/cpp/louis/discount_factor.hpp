//
//  discount_factor.hpp
//  
//
//  Created by Louis le Pas de Sécheval on 03/11/2017.
//

#ifndef DISCOUNT_FACTOR_HPP
#define DISCOUNT_FACTOR_HPP

#include <cmath>
namespace ds1
{
    double discount_factor(double rate, double maturity);
}
void print_discount_factor();
std::vector<double> discount_factor(const std::vector<double> r, const std::vector<double> m);
#endif
