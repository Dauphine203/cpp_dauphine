#ifndef VOLATILITY_HPP
#define VOLATILITY_HPP

#include <string>
#include <vector>

namespace dauphine
{
    class volatility
    {
    public:

        const std::string& underlying_name() const;
    };

    class implied_volatility : public volatility
    {
    };
}

#endif
