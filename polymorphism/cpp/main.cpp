#include <iostream>
#include <string>
#include <vector>

#include "volatility.hpp"
#include "volatility.cpp"


// To compile for Windows users:

// mkdir build
// cd build
// cmake -G "NMake Makefiles" ..
// nmake


namespace dauphine 
{
	void test_polymorphism(const volatility& v)
	{
		std::cout << v.get_volatility(0) << std::endl;
	}
	
	void test_polymorphism()
	{
		// Volatility
		volatility* iv = make_volatility("SpaceX", {0.1, 0.2, 1.0});
		test_polymorphism(*iv);
		
		// Bumped volatility
		volatility* bv = make_volatility(iv, 1.0);
		test_polymorphism(*bv);
		
		delete bv;
		delete iv;
		
		
		/*
		volatility* iv1 = make_volatility("SpaceX", {0.3, 0.05, 0.43, 0.76, 0.34});
		volatility* iv2 = make_volatility("Google", {0.4, 0.42, 0.23, 0.42, 0.22});
		*iv1 = *iv2;
		
		iv1 -> print();
		iv2 -> print();
		
		volatility* bv = make_volatility(iv2, 1.0);
		
		*iv2 = *bv;
		
		iv2 -> print();
		bv -> print();
		
		delete bv;
		delete iv2;
		delete iv1;
		*/
	}
}

int main(int argc, char* argv[])
{
	dauphine::test_polymorphism();
	return 0;
}