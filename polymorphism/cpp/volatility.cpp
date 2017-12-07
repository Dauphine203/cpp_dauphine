#include "volatility.hpp"
#include <string>
#include <iostream>
#include <vector>

// Windows users:
// mkdir build
// cd build
// cmake -G "NMake Makefiles" ..
// nmake


namespace mathphi
{
	// Constructor
	volatility::volatility(const std::string& name)
		: m_name(name)
		{
		}
	
    const std::string& volatility::underlying_name() const{
        return m_name;
    }
	
	// Print
	void implied_volatility::print() const
	{
		std::cout << "implied volatility " << m_id << std::endl;
	}
	
	/*
	// AAA
	double volatility::get_volatility(size_t index) const
	{
		std::cout << volatility::get_volatility << std::endl;
		return 0.;
	}
	
	implied_volatility::implied_volatility(const std::string& name,
											std::vector<double>& vol);
	
	
	double implied_volatility::get_volatility(size_t index) const{
		std::cout << implied_volatility::get_volatility << std::endl;
		return m_volatility[index];
	
	*/
	
	}
	
/*
int main(int argc, char* argv[])
{
	// TEST 1
	mathphi::volatility v("SpaceX");
	std::cout << v.underlying_name() << std::endl;
	
	// TEST 2
    //mathphi::test_polymorphism();
    return 0;
}
*/