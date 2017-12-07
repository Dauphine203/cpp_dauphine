#include <iostream>
#include <algorithm>
#include "vector_utils.hpp"
#include <iterator>
#include <numeric>
#include <string>
#include <cmath>
#include <cctype>

namespace dauphine
{
	/*void print( std::vector<double>& myvector)
	{
		for(int i=0;i<myvector.size();i++)
		{
			if(i<myvector.size()-1)
			{
				std::cout << myvector[i] << ",";
			}
			else
			{
				std::cout << myvector[i];    
			}
		}
		std::cout << std::endl;
	}*/
	
	/*void print(std::vector<double>& v)
    {
        for(auto iter = v.begin(); iter != v.end(); ++iter)
        {
            std::cout << *iter << ",";
        }
        std::cout << std::endl;
    }*/
	
	void print(const std::vector<double>& v)
	{
		std::ostream_iterator<double> out_it(std::cout, ", ");
		// oastream_iterator fait que cout devient un conteneur dans lequel on stock les valeurs double
		std::copy(v.begin(), v.end(), out_it);
		std::cout << std::endl;
	}
	
	double mean(const std::vector<double>& v)
    {
		double res = std::accumulate(v.begin(), v.end(), 0);
        return res / v.size();
    }
	
	void extend_vector(std::vector<double>& v)
	{	
		size_t s=v.size();
		v.resize(s*2);
		std::transform(v.begin(),v.begin()+s, v.begin()+s, [](double arg1) { return arg1 *2; });
		print(v);
	}
	/*void extend_vector(std::vector<double>& v)
    {
        size_t size = v.size();
        v.resize(2 * size);
        for(size_t i = 0; i < size; ++i)
        {
            //v[i + size] = 2 * v[i];
			v.push_back(v[i]*2);
        }
    }*/
	double geometric_mean(const std::vector<double>& v)
	{
		double res = std::accumulate(v.begin(), v.end(), 1., std::multiplies<double>());
		return std::pow(res, 1./v.size());
	}
	
	void appendv(std::vector<double>& v1, std::vector<double>& v2)
	{
		size_t v1size= v1.size();
		v1.resize(v1.size()+v2.size());
		std::copy(v2.begin(), v2.end(),v1.begin()+v1size);
	}
	
	void extend_vector(std::vector<double>& v, double factor)
    {
        size_t size = v.size();
        v.resize(2 * size);
        std::transform(v.begin(), v.begin() + size, v.begin() + size,
                       [](double arg) { return factor * arg; });
    }
                        

    void extend_vector(std::vector<double>& v, double factor)
    {
        size_t size = v.size();
        v.resize(2 * size);
        std::transform(v.begin(), v.begin() + size, v.begin() + size,
                       [factor](double arg) { return factor * arg; }); // captures the factor, automatically by value
    }
	
	/*void appendv(std::vector<double>& v1, std::vector<double>& v2)
	{
		for(int i=0; i<v2.size(); i++)
			{
				v1.push_back(v2[i]);
			}
	}*/
}