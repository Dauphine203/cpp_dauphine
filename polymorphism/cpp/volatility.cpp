#include "volatility.hpp"
#include <iostream>
#include <vector>
namespace dauphine
{
	volatility::volatility(const std::string& udlname)
	: m_udlname(udlname) //constructor to initialize name
	{
		std::cout<<"volatility constructor"<<std::endl;
	}
	
    const std::string& volatility::underlying_name() const //just want to read the name so const + by ref the name ->&
    {
        return m_udlname;
    }
	volatility::~volatility()
	{
		std::cout<<"volatility destructor"<<std::endl;
	}
	
	implied_volatility::implied_volatility(const std::string& name, const std::vector<double>& vol	)
        : volatility(name), m_volatility(vol) // call constructor of mother class
    {
		std::cout<<"implied volatility constructor"<<std::endl;
	}
	
	void implied_volatility::printid() const
	{
		std::cout << id << std::endl;
	}
	
    double implied_volatility::get_volatility(size_t index) const
	{
		std::cout << "implied volatility" << std::endl;
		return m_volatility[index];
	}
	
	double volatility::get_volatility(size_t index) const //copy so no need of const
	{
		std::cout << "V" << std::endl;
		return 0;
	}
	
	implied_volatility::~implied_volatility()
	{
		std::cout<<"implied volatility destructor"<<std::endl;
	}
	
	bumped_volatility::~bumped_volatility()
	{
		std::cout<<"bumped_volatility destructor"<<std::endl;
		p_volatility = nullptr;
	}

	bumped_volatility::bumped_volatility(volatility* v, const double& bump)
        : volatility(v->underlying_name()), p_volatility(v),m_bump(bump) // call constructor of mother class
    {
		std::cout<<"bumped_volatility constructor"<<std::endl;
	}
	
	double bumped_volatility::get_volatility(size_t index) const
	{
		std::cout << "bumped_volatility" << std::endl;
		return p_volatility->get_volatility(index)+m_bump;	
	}
	
	volatility* make_volatility(const std::string& ud, const std::vector<double>& vol)
    {
        return new implied_volatility(ud, vol);
    }
	
    volatility* make_volatility(volatility* vol, double bump)
    {
        return new bumped_volatility(vol, bump);
    }
       
}
