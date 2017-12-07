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
    void test_polymorphism(const volatility& v)
    {
        std::cout << v.get_volatility(1) << std::endl;
    }

    void test_polymorphism()
    {
        volatility* iv = make_volatility("JP Morgan", { 0.15, 0.20, 0.25, 0.26 });
        test_polymorphism(*iv);
        volatility* bv= make_volatility(iv, 0.01);
        test_polymorphism(*bv);
        delete bv;
        delete iv;
    }
}

int main(int argc, char* argv[])
{
    dauphine::test_polymorphism();
    return 0;
}

