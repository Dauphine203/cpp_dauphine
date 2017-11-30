#include "allocation.hpp"

namespace dauphine
{
    /*
    volatility::volatility()
    {
        std::cout << "volatility constructor" << std::endl;
    }

    volatility::~volatility()
    {
        std::cout << "volatility destructor" << std::endl;
    }

    double volatility::get_volatility(double maturity, double strike) const
    {
        return 0.14;
    }

    volatility* make_volatility()
    {
        return new volatility;
    }
    */

    // PART 2
    
    data_model::data_model(product_ptr prod)
        : p_product(prod)
    {
        std::cout << "data_model constructor" << std::endl;
    }

    data_model::~data_model()
    {
        std::cout << "data_model destructor" << std::endl;
    }

    product::product()
    {
        std::cout << "product constructor" << std::endl;
    }

    product::~product()
    {
        std::cout << "product destructor" << std::endl;
    }

    pricer::pricer(product_ptr prod, data_model_ptr data)
        : p_product(prod), p_data(data)
    {
        std::cout << "pricer constructor" << std::endl;
    }

    pricer::~pricer()
    {
        std::cout << "pricer destructor" << std::endl;
    }
}

