#include <iostream>
#include <string>
#include <vector>
#include "polynomial.hpp"


/*
 * Compilation for windows users
 * mkdir build
 * cd build
 * cmake -G "NMake Makefiles" ..
 * nmake
 */

/*
 * Compilation for OSX / Linux users
 * mkdir build
 * cd build
 * cmake ..
 * make
 */

/*
 * See the instructions in polynomial.hpp
 * Uncomment the following test functions
 * once your implementation is done, to
 * check that it is valid
 */

namespace dauphine
{
    std::string get_checked_value(bool c)
    {
        return c ? "Ok" : "Failed";
    }

    /*
    void test_constructor()
    {
        std::cout << "POLYNOMIAL INTERFACE" << std::endl;
        polynomial p(3);
        p[0] = 2.;
        p[2] = 1.5;
        p[3] = 1.;
        std::cout << p << std::endl;
        // Should print "X^3 + 1.5 X^2 + 2. 
        bool deg_cond = p.degree() == 3;
        std::cout << "polynomial::degree check    : " << get_checked_value(deg_cond) << std::endl;
        double res = p.eval(2.);
        bool res_cond = (res == 16.);
        std::cout << "polynomial::eval check      : " << get_checked_value(res_cond) << std::endl;
        polynomial p2 = { 1., 1.5, 0., 2. };
        bool init_check = (p2[0] == p[0] &&
                           p2[1] == p[1] &&
                           p2[2] == p[2] &&
                           p2[3] == p[3]);
        std::cout << "Polynom initialization check: " << get_checked_value(init_check) << std::endl;
        std::cout << std::endl;
    }

    void test_comparison()
    {
        std::cout << "POLYNOMIAL COMPARISON" << std::endl;
        polynomial p1 = { 1., 2., 0., 4. };
        polynomial p2 = { 1., 3., 0., 4. };

        bool c1 = (p1 == p1);
        bool c2 = (p1 != p2);

        std::cout << "Polynomial operator==: " << get_checked_value(c1) << std::endl;
        std::cout << "Polynomial operator!=: " << get_checked_value(c2) << std::endl;
        std::cout << std::endl;
    }

    void test_addition()
    {
        std::cout << "POLYNOMIAL ADDITION" << std::endl;
        polynomial p1 = { 1., 2., 0., 4. };
        polynomial p2 = { 2., 2., 1., 3. };
        polynomial p3 = { 3., 4., 1., 7. };
        polynomial p4 = { 4., 5., 3., 7. };
        polynomial p5 = { 2., 1., 3., -1. };

        bool tapp = (p3 == p1 + p2);
        bool taps = (p4 == p1 + 3.);
        bool tasp = (p4 == 3. + p1);

        bool tspp = (p1 == p3 - p2);
        bool tsps = (p1 == p4 - 3);
        bool tssp = (p5 == 3 - p1);

        std::cout << "Polynomial + Polynomial: " << get_checked_value(tapp) << std::endl;
        std::cout << "Polynomial + Scalar    : " << get_checked_value(taps) << std::endl;
        std::cout << "Scalar + Polynomial    : " << get_checked_value(tasp) << std::endl;
        std::cout << "Polynomial - Polynomial: " << get_checked_value(tspp) << std::endl;
        std::cout << "Polynomial - Scalar    : " << get_checked_value(tsps) << std::endl;
        std::cout << "Scalar - Polynomial    : " << get_checked_value(tssp) << std::endl;
        std::cout << std::endl;
    }

    void test_multiplication()
    {
        std::cout << "POLYNOMIAL MULTIPLICATION" << std::endl;
        polynomial p1 = { 2., 1. };
        polynomial p2 = { 3., 4. };
        polynomial mres = { 6. 11. 4. };
        polynomial mresps = { 4., 2. };
        bool mpp = (mres == p1 * p2);
        bool mps = (mresps == p1 * 2);
        bool msp = (mresps == 2 * p1);

        std::cout << "Polynomial * Polynomial: " << get_checked_value(mpp) << std::endl;
        std::cout << "Polynomial * Scalar    : " << get_checked_value(mps) << std::endl;
        std::cout << "Scalar * Polynomial    : " << get_checked_value(msp) << std::endl;
        std::cout << std::endl;
    }

    void test_division()
    {
        std::cout << "POLYNOMIAL DIVISION" << std::endl;
        polynomial p1 = { 1, -1, -1, 3., -2., 0. };
        polynomial p2 = { 1., -1., 1. };
        polynomial qres = { 1., 0., -2., 1. };
        polynomial rres = { 1., -1. };

        bool qcond = (qres == p1 / p2);
        bool rcond = (rres == p1 % p2);

        std::cout << "Polynomial / Polynomial: " << get_checked_value(qcond) << std::endl;
        std::cout << "Polynomial % Polynomial: " << get_checked_value(rcond) << std::endl;
        std::cout << std::endl;
    }
    */
}

int main(int argc, char* argv[])
{
    //dauphine::test_constructor();
    //dauphine::test_comparison();
    //dauphine::test_addition();
    //dauphine::test_multiplication();
    //dauphine::test_division();
	
	
    return 0;
}

