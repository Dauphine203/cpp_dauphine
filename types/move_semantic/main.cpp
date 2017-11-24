#include <iostream>
#include "resource.hpp"

namespace dauphine
{
    resource get_resource(int i)
    {
        return resource(i);
    }

    void compute(const resource& param)
    {
        std::cout << "compute(const resource& param) - id = " << param.get_id() << std::endl;
    }

    void compute(resource&& param)
    {
        std::cout << "compute(resource&& param) - id = " << param.get_id() << std::endl;
    }

    void test_copy()
    {
        std::cout << "TEST COPY" << std::endl;
        resource r1(1);
        resource r2 = r1;
        resource r3(4);
        r2 = r3;
    }

    void test_move()
    {
        std::cout << "TEST MOVE" << std::endl;
        resource r1(10);
        // r1 should not be used after beeing moved
        resource r2 = std::move(r1);
        resource r3(20);
        r2 = std::move(r3);
    }

    void test_lvalue_ref()
    {
        std::cout << "TEST LVALUE REF" << std::endl;
        resource r(15);
        compute(r);
    }

    void test_rvalue_ref()
    {
        std::cout << "TEST RVALUE REF" << std::endl;
        compute(get_resource(20));
    }

    void test_rvalue_ref_as_lvalue()
    {
        std::cout << "TEST RVALUE REF AS LVALUE" << std::endl;
        resource&& r = get_resource(48);
        compute(r);
        compute(std::move(r));
    }

    void full_test()
    {
        test_copy();
        test_move();
        test_lvalue_ref();
        test_rvalue_ref();
        test_rvalue_ref_as_lvalue();
    }
}


int main(int argc, char* argv[])
{
    dauphine::full_test();
    return 0;
}

