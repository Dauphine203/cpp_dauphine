#ifndef VOLATILITY_HPP
#define VOLATILITY_HPP

#include <string>

namespace dauphine
{
    class volatility
    {
    public:

        std::string underlying_name() const;
    };

    class implied_volatility : public volatility
    {
    };
}

#endif
