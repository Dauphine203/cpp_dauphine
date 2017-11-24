#include <iostream>
#include "resource.hpp"

namespace dauphine
{
    int next_id()
    {
        static int id = 0;
        return id++;
    }

    resource::resource(int value)
        : m_id(next_id()), m_value(value)
    {
        std::cout << "Resource constructor: " << *this << std::endl;
    }

    resource::~resource()
    {
        std::cout << "Resource destructor: " << *this << std::endl;
    }

    resource::resource(const resource& rhs)
        : m_id(next_id()), m_value(rhs.m_value) // We don't copy the id since we want it to be unique
    {
        std::cout << "Resource copy constructor: " << *this << " from resource: " << rhs << std::endl;
    }

    resource& resource::operator=(const resource& rhs)
    {
        std::cout << "Resource copy assign operator: " << *this << " from resource: " << rhs << std::endl;
        m_value = rhs.m_value;
        return *this;
    }

    resource::resource(resource&& rhs)
        : m_id(next_id()), m_value(std::move(rhs.m_value))
    {
        std::cout << "Resource move constructor: " << *this << " from resource:  " << rhs << std::endl;
        rhs.m_value = 0;
    }

    resource& resource::operator=(resource&& rhs)
    {
        std::cout << "Resource move assign operator: " << *this << "from resource: " << rhs << std::endl;
        std::swap(m_value, rhs.m_value);
        return *this;
    }

    int resource::get_id() const
    {
        return m_id;
    }

    int resource::get_value() const
    {
        return m_value;
    }

    std::ostream& operator<<(std::ostream& out, const resource& r)
    {
        out << "id = " << r.get_id() << " - " << "value = " << r.get_value();
        return out;
    }
}

