#include <iostream>
#include "interpolation_impl.hpp"

namespace dauphine
{
	void test_spline_interpolation()
	{
		interpolation_impl* inter
			= make_interpolation({1., 2., 3., 4.},
								 {1., 4., 9., 16.},
								 interpolation_type::spline);						   
		double res = inter->interpolate(2.5);
		std::cout << res << std::endl;
		delete inter;
		
		interpolation_impl* inter2 = make_interpolation(...);
		*inter1 = *inter2;
		
		
		interpolation inter(x, y, interpolation_type::spline);
		inter.interpolate(...);
		interpolation inter2 = inter;
	
		interpolation x;
		
		func(x, x);
	}
}

int main(int argc, char* argv[])
{
	dauphine::test_spline_interpolation();
    return 0;
}

