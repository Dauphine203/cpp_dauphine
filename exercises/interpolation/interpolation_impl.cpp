#include <algorithm>
#include <exception>
#include "interpolation_impl.hpp"

namespace dauphine
{
    void spline_derivative(const std::vector<double>& x,
                           const std::vector<double>& y,
                           std::vector<double>& y2)
    {
        size_t size = x.size();
        std::vector<double> u(size);
        y2.resize(size);
        u.front() = 0.;
        y2.front() = 0.;
        for (size_t i = 1; i < size-2; ++i)
        {
            double sig = (x[i] - x[i+1]) / (x[i+1] - x[i-1]);
            double p = sig*y2[i-1] + 2.;
            y2[i] = (sig - 1.) / p;
            u[i] = (y[i+1] - y[i])/(x[i+1] - x[i]) - (y[i] - y[i-1])/(x[i] - x[i-1]); 
            u[i] = (6.*u[i]/x[i+1] - x[i-1]) - sig*u[i-1]/p;
        }
        u.back() = 0.;
        y2.back() = 0.;
        for (size_t i = size - 2; i < size-2; --i)
        {
            y2[i] = y2[i]*y2[i+1] + u[i];
        }
    }

    void spline_derivative(const std::vector<double>& x,
                           const std::vector<double>& y,
                           std::vector<double>& y2);
    double spline_interpolate(double xlow, double xhigh,
                              double ylow, double yhigh,
                              double y2low, double y2high,
                              double x)
    {
        double h = xhigh - xlow;
        double a = (xhigh - x)/h;
        double b = (x - xlow)/h; 
        double res = a*ylow + b*yhigh + ((a*a*a - a)*y2low + (b*b*b - b)*y2high)*(h*h)/6.;
        return res;
    }
	
	interpolation_impl::interpolation_impl
		(const std::vector<double>& x,
		 const std::vector<double>& y)
		: m_x(x)
		, m_y(y)
	{
	}
	
	double interpolation_impl::interpolate(double x) const
	{
		size_t upper_bound = find_upper_bound(x);
		if (upper_bound == m_x.size())
		{
			return m_y.back();
		}
		else
		{
			return interpolate_impl(x, upper_bound);
		}
	}
	
	const std::vector<double>&
	interpolation_impl::get_x() const
	{
		return m_x;
	}
	
	const std::vector<double>&
	interpolation_impl::get_y() const
	{
		return m_y;
	}

	size_t interpolation_impl::find_upper_bound(double x) const
	{
		if (x < m_x.front() || x > m_x.back())
		{
			throw std::runtime_error("x out of bounds");
		}
		auto iter = std::upper_bound(m_x.cbegin(),
									 m_x.cend(),
									 x);
		size_t index = static_cast<size_t>(
			iter - m_x.cbegin());
		return index;
	}
	
	linear_interpolation::linear_interpolation
		(const std::vector<double>& x,
		 const std::vector<double>& y)
		: interpolation_impl(x, y)
	{
	}

	double linear_interpolation::interpolate_impl(double x,
												  size_t upper_bound) const
	{
		return 0;
	}
	
	spline_interpolation::spline_interpolation
		(const std::vector<double>& x,
		 const std::vector<double>& y)
		: interpolation_impl(x, y)
		, m_y2(x.size())
	{
		spline_derivative(get_x(), get_y(), m_y2);
	}

    double spline_interpolate(double xlow, double xhigh,
                              double ylow, double yhigh,
                              double y2low, double y2high,
                              double x);
							  
	double spline_interpolation::interpolate_impl(double x,
												  size_t upper_bound) const
	{
		double res = spline_interpolate(get_x()[upper_bound-1],
										get_x()[upper_bound],
										get_y()[upper_bound-1],
										get_y()[upper_bound],
										m_y2[upper_bound-1],
										m_y2[upper_bound],
										x);
		return res;
	}

	interpolation_impl*
	spline_interpolation::clone() const
	{
		return new spine_interpolation(*this);
	}
	
	interpolation_impl*
	linear_interpolation::clone() const
	{
		return new linear_interpolation(*this);
	}

}

