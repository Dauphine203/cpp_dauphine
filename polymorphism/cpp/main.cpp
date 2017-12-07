#include <iostream>
#include <string>
#include <vector>

#include "volatility.hpp"
#include "volatility.cpp"

// To compile
//
// Windows users:
// mkdir build
// cd build
// cmake -G "NMake Makefiles" ..
// nmake
//
// OSX / Linux users:
// mkdir build
// cd build
// cmake ..
// make



namespace mathphi
{
    
	/*
	void test_access()
    {
        implied_volatility v;
        std::cout << v.underlying_name() << std::endl;
    }

	void test_polymorphism(const volatility& vol)
	{
		std::cout << vol.underlying_name() << std::endl;
	}
	
	void test_polymorphism()
	{
		implied_volatility iv("SpaceX");
		test_polymorphism(iv);
	}
	*/
	
}


int main(int argc, char* argv[])
{
	// TEST 1
	mathphi::volatility v("SpaceX");
	std::cout << v.underlying_name() << std::endl;
	
	// TEST 2
    //mathphi::test_polymorphism();
    return 0;
}
