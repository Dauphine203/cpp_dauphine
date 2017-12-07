#ifndef VECTOR_UTILS_HPP
#define VECTOR_UTILS_HPP

#include <vector>

namespace dauphine
{
	void print(const std::vector<double>& v);
	double mean(const std::vector<double>& v);
	void extend_vector(std::vector<double>& v);
	void appendv(std::vector<double>& v1, std::vector<double>& v2);
	double geometric_mean(const std::vector<double>& v);
}

#endif
