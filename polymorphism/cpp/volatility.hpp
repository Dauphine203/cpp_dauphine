#ifndef VOLATILITY_HPP
#define VOLATILITY_HPP

#include <string>
#include <vector>

namespace dauphine
{
    class volatility
    {
    public:

        explicit volatility(const std::string& name = "");
        virtual ~volatility();
        
        const std::string& underlying_name() const;

        virtual double get_volatility(size_t index) const = 0;

    private:

        std::string m_name;
    };

    class implied_volatility : public volatility
    {
    public:

        implied_volatility(const std::string& name, const std::vector<double>& vol);
        virtual ~implied_volatility();

        virtual double get_volatility(size_t index) const;

    private:

        std::vector<double> m_volatility;
    };

    class bumped_volatility : public volatility
    {
    public:

        bumped_volatility(volatility* vol, double bump);
        virtual ~bumped_volatility();

        virtual double get_volatility(size_t index) const;

    private:

        volatility* p_volatility;
        double m_bump;
    };

    volatility* make_volatility(const std::string& ud, const std::vector<double>& vol);
    volatility* make_volatility(volatility* vol, double bump);
}

#endif
