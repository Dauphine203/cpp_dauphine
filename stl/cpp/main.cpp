#include <iostream>
#include "vector_utils.hpp"
#include "additional_exercises.hpp"
#include <cmath>
#include <vector>
#include <algorithm>

#include <iterator>

// Printing vector elements with iterators

void print(const std::vector<double>& x){
	for (auto i = x.begin(); i != x.end(); ++i){
		std::cout << *i << "," ;
	}
	std::cout << std::endl;
}

// Main

int main(int argc, char* argv[])
{
     std::cout << "Blade Runner" << std::endl;
	 std::cout << exp(log(2.0)) << std::endl;
	 
	 std::vector<double> x = {1.0, 2.0, 3.0, 4.0};
	 print(x);
	 
     return 0;
}

