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
    void test_access()
    {
        implied_volatility v;
        std::cout << v.underlying_name() << std::endl;
    }
}

int main(int argc, char* argv[])
{
    dauphine::test_access();
    return 0;
}

