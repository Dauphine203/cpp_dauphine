#include "option.hpp"

namespace dauphine
{
    volatility::volatility()
    {
        std::cout << "volatility constructor" << std::endl;
    }

    volatility::~volatility()
    {
        std::cout << "volatility destructor" << std::endl;
    }

    double volatility::get_volatility(double maturity, double strike) const
    {
        return 0.14;
    }

    volatility* make_volatility()
    {
        return new volatility;
    }

    underlying::underlying(volatility* vol)
    {
    }

    underlying::~underlying()
    {
    }

    option::option(underlying* underlying, volatility* vol)
    {
    }
    
    option::~option()
    {
    }
}

