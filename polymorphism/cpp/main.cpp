#include <iostream>
#include "volatility.hpp"

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
namespace dauphine
{
    /*void test_access()
    {
        implied_volatility v;
        std::cout << v.underlying_name() << std::endl;
    }*/
	void test_polymorphism(const volatility& vol) //need the const et by ref parce que on passe une IV et non une V mais elle inhérite so ok, parce que il faut que ça reconnaisse que c'est une V.
	//alors que si on passe par value ça ne va pas marcher puisque pas de constructor
    {
        //std::cout << vol.underlying_name() << std::endl;
		//std::cout << vol.get_volatility(1) << std::endl;
    }

    /*void test_polymorphism()
    {
        implied_volatility* iv = new implied_volatility("JP Morgan", { 0.15, 0.20, 0.25, 0.26});
        test_polymorphism(*iv);
        bumped_volatility* bv = new bumped_volatility(iv, 0.01);
        test_polymorphism(*bv);
        delete bv;
        delete iv;
    }*/
	
	void test_polymorphism()
    {
        volatility* iv = make_volatility("JP Morgan", { 0.15, 0.20, 0.25, 0.26});
        test_polymorphism(*iv);
        volatility* bv = make_volatility(iv, 0.01);
        test_polymorphism(*bv);
        delete bv;
        delete iv;
    }
}

int main(int argc, char* argv[])
{
    //dauphine::test_access();
	//dauphine::volatility v("JP"); //create a volatility instance in the namespace dauphine 
	//std::cout << v.underlying_name() << std::endl;
	//std::cout << iv.get_volatility(1) << std::endl;
	dauphine::test_polymorphism();
    return 0;
}

