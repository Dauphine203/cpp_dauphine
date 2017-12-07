#include <iostream>
#include "vector_utils.hpp"
#include "additional_exercises.hpp"

int main(int argc, char* argv[])
{
	const std::vector<double> v(10, 1.);
	//double mean = dauphine::mean(v);
	//std::cout << mean;
	std::vector<double> v2={1,2,3,4};
	dauphine::extend_vector(v2);
	//dauphine::appendv(v,v2);
	std::cout << dauphine::mean(v) << std::endl;
	std::cout << dauphine::geometric_mean(v)<< std::endl;
}
