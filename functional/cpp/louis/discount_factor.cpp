//
//  discount_factor.cpp
//  
//
//  Created by Louis le Pas de Sécheval on 03/11/2017.
//

#include "discount_factor.hpp"
#include "discount_factor2.hpp"

#include <cmath>
namespace ds1
{
    double discount_factor(double rate, double maturity)
    {
        return std::exp(-rate * maturity);
    }
}
//std::vector<double> discount_factor(const std::vector<double> r, const std::vector<double> m)
//{
    // ...
//}
