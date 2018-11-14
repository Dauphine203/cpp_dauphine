#ifndef PRICER_HPP
#define PRICER_HPP

#include <memory>

namespace dauphine
{   
    class data_model;
    class product;

    using data_model_ptr = std::shared_ptr<data_model>;
    using product_ptr = std::shared_ptr<product>;

    class data_model
    {
    public:

        data_model(product_ptr prod);
        ~data_model();

    private:

        product_ptr p_product;
    };

    class product
    {
    public:

        product();
        ~product();
    };

    class pricer
    {
    public:

        pricer(product_ptr prod, data_model_ptr data);
        ~pricer();

    private:

        product_ptr p_product;
        data_model_ptr p_data;
    };

}

#endif
