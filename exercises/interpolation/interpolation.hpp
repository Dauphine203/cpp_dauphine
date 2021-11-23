#ifndef INTERPOLATION_HPP
#define INTERPOLATION_HPP

#include <vector>

namespace dauphine
{
	enum class interpolation_type
	{
		linear,
		spline
	};
	
	class interpolation_impl;
	
	class interpolation
	{
	public:
	
		interpolation(const std::vector<double>& x,
					  const std::vector<double>& y,
					  interpolation_type type);
		~interpolation();
		
		interpolation(const interpolation& rhs);
		interpolation& operator=(const interpolation& rhs);
		
		interpolation(interpolation&& rhs);
		interpolation& operator=(interpolation&& rhs);
		
		double interpolate(double x) const;
		
	private:
	
		interpolation_impl* p_impl;
	};
	
	
	
	
	
	
	
}

#endif

