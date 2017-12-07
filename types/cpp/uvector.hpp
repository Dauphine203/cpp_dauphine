#ifndef UVECTOR_HPP
#define UVECTOR_HPP

namespace dauphine
{
	
    class uvector
    {
    public:

        uvector(std::size_t size);
        uvector(std::size_t size, double value);

    private:

        double* p_data;
        std::size_t m_size;
    };
             
}

#endif
