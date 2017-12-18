#include "volatility.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

namespace dauphine
{
	
	// VOLATILITY IMPLEMENTATION
	volatility::volatility(const std::string& name)
		: m_name(name)
	{ std::cout << "V Constructor" << std::endl; }
	
	volatility::~volatility()
	{ std::cout << "V destructor" << std::endl; }
	
	const std::string& volatility::underlying_name() const
	{ return m_name; }
	
	void volatility::print() const
	{ std::cout << "Underlying: " << underlying_name() << std::endl; }
	
	
	// IMPLED VOLATILITY IMPLEMENTATION
	implied_volatility::implied_volatility(const std::string& name, const std::vector<double>& vol)
        : volatility(name), m_volatility(vol)
    {
        std::cout << "IV: Constructor" << std::endl;
    }
	
	implied_volatility::~implied_volatility()
	{
		std::cout << "IV: Destructor" << std::endl;
	}
	
	double implied_volatility::get_volatility(size_t index) const
	{
		return m_volatility[index];
	}
	
	void implied_volatility::print() const
	{
		volatility::print();
		std::cout << "Volatility : (";
		std::copy(m_volatility.begin(), m_volatility.end(), std::ostream_iterator<double>(std::cout, ", "));
		std::cout << ")" << std::endl;
	}
	
	
	// BUMPED VOLATILITY IMPLEMENTATION
	
	// Constructor
	bumped_volatility::bumped_volatility(volatility* vol, double bump)
        :volatility(vol->underlying_name()), p_volatility(vol), m_bump(bump)
    { std::cout << "BV: Constructor" << std::endl; }
	
	// Destructor
    bumped_volatility::~bumped_volatility()
    { std::cout << "BV: Destructor" << std::endl; }
	
	// Function
    double bumped_volatility::get_volatility(size_t index) const
    {
        return p_volatility -> get_volatility(index) + m_bump;
    }
	
	void bumped_volatility::print() const
	{
		std::cout << "BV: init = " << std::endl;
		p_volatility -> print();
		std::cout << "BV: m_bump = " << m_bump << std::endl;
	}
	
	
	// MAKE VOLATILITY VOLATILITY IMPLEMENTATION
	
	volatility* make_volatility(const std::string& ud, const std::vector<double>& vol)
    {
        return new implied_volatility(ud, vol);
    }

    volatility* make_volatility(volatility* vol, double bump)
    {
        return new bumped_volatility(vol, bump);
    }
	
}