#ifndef RESOURCE_HPP
#define RESOURCE_HPP

namespace dauphine
{
    // Simple class to track calls to construtors / destructor / assignments
    // In a real application, resource could hold a dynamic allocated array,
    // a connection to a database, an handler on a file or anything that
    // requires user-defined value semantic.
    // Each resource has a unique id (this is guaranteed by construction),
    // and a value that may be copied / moved from another resource.
    // A value of 0 means an uninitialized resource (or a resource that has been
    // reset after a move example)
    class resource
    {
    public:

        resource(int value = 0);
        ~resource();

        resource(const resource& rhs);
        resource& operator=(const resource& rhs);

        resource(resource&& rhs);
        resource& operator=(resource&& rhs);

        int get_id() const;
        int get_value() const;

    private:

        int m_id;
        int m_value;
    };

    std::ostream& operator<<(std::ostream& out, const resource& r);
}

#endif
