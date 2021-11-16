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
}

