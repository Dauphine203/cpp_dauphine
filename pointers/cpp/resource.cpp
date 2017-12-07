#include <iostream>
#include "resource.hpp"

namespace dauphine
{
    void resource::acquire()
    {
        std::cout << "resource::acquire" << std::endl;
    }

    void resource::release()
    {
        std::cout << "resource::release" << std::endl;
    }
	/*
    void resource::print_message()
    {
        std::cout << "resource::print_message START" << std::endl;
        throw std::runtime_error("resource could not print message");
        std::cout << "resource::print_message STATUS" << std::endl;
        std::cout << "resource::print_message END" << std::endl;
    }
	*/
}

