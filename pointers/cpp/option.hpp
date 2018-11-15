#ifndef OPTION_HPP
#define OPATION_HPP

#include <memory>
#include <iostream>

namespace dauphine
{
    class volatility
    {
    public:

        volatility();
        ~volatility();

        double get_volatility(double maturity, double strike) const;
    };

    volatility* make_volatility();

    class underlying
    {
    public:

        underlying(volatility* vol);
        ~underlying();

    private:

        volatility* p_volatility;
    };

    class option
    {
    public:

        option(underlying* underlying, volatility* vol);
        ~option();

    private:

        underlying* p_underlying;
        volatility* p_volatility;
    };
}

#endif
