#include "resource.hpp"
#include "option.hpp"
#include "pricer.hpp"

// TO COMPILE:
//
// WINDOWS USERS
// mkdir build
// cd build
// cmake -G "NMake Makefiles" ..
// nmake
//
// OSX USERS
// mkdir build
// cd build
// cmake ..
// make

namespace dauphine
{
    void test_resource()
    {
        resource r;
        r.acquire();
        r.print_message();
        r.release();
    }

    void test_volatility()
    {
        volatility* vol = make_volatility();
        underlying u(vol);
        option opt(&u, vol);
    }

    void test_pricer()
    {
        product_ptr prod = product_ptr(new product);
        data_model_ptr data = std::make_shared<data_model>(prod);
        pricer p(prod, data);
    }
}

int main(int artc, char* argv[])
{
    dauphine::test_resource();
    return 0;
}

