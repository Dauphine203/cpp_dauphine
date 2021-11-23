#include "interpolation.hpp"
#include "interpolation_impl.hpp"


namespace dauphine
{
	interpolation_impl*
	make_interpolation(const std::vector<double>& x,
					   const std::vector<double>& y,
					   interpolation_type t)
	{
		switch(t)
		{
		case interpolation_type::linear:
			return new linear_interpolation(x, y);
		case interpolation_type::spline:
			return new spline_interpolation(x, y);
		}
	}
	
	interpolation::interpolation(const std::vector<double>& x,
								 const std::vector<double>& y,
								 interpolation_type type)
		: p_impl(make_interpolation(x, y, type))
	{
	}
	
	interpolation::~interpolation()
	{
		delete p_impl;
		p_impl = nullptr;
	}
	
	interpolation::interpolation(const interpolation& rhs)
		: p_impl(rhs.p_impl->clone())
	{
	}
	
	interpolation& interpolation::operator=(const interpolation& rhs)
	{
		interpolation tmp(rhs);
		std::swap(tmp.p_impl, this->p_impl);
		return *this;
	}
		
	interpolation::interpolation(interpolation&& rhs)
		: p_impl(rhs.p_impl)
	{
		rhs.p_impl = nullptr;
	}
	
	interpolation& operator=(interpolation&& rhs)
	{
		std::swap(p_impl, rhs.p_impl);
		return *this;
	}
		
	double interpolation::interpolate(double x) const
	{
		return p_impl->interpolate(x);
	}
}
