#ifndef CHESS_ARRAY_HPP
#define CHESS_ARRAY_HPP

#include <algorithm>
#include <array>

namespace chess
{
    template <class T>
    class chess_array : private std::array<T, 8>
    {
    public:

        using base_type = std::array<T, 8>;
        using value_type = typename base_type::value_type;
        using reference = typename base_type::reference;
        using const_reference = typename base_type::const_reference;
        using pointer = typename base_type::pointer;
        using const_pointer = typename base_type::const_pointer;
        using size_type = typename base_type::size_type;
        using difference_type = typename base_type::difference_type;
        using iterator = typename base_type::iterator;
        using const_iterator = typename base_type::const_iterator;
        using reverse_iterator = typename base_type::reverse_iterator;
        using const_reverse_iterator = typename base_type::const_reverse_iterator;

        chess_array(std::initializer_list<T> init);

        reference operator[](char c);
        const_reference operator[](char c) const;

        reference at(char c);
        const_reference at(char c) const;

        using base_type::front;
        using base_type::back;

        using base_type::empty;
        using base_type::size;

        using base_type::begin;
        using base_type::end;
        using base_type::cbegin;
        using base_type::cend;
        
        using base_type::rbegin;
        using base_type::rend;

        using base_type::fill;
        using base_type::swap;

    private:

        size_type index(char c) const;
    };

    template <class T>
    void swap(chess_array<T>& ca1, chess_array<T>& ca2);

    /******************************
     * chess_array implementation *
     ******************************/

    template <class T>
    inline chess_array<T>::chess_array(std::initializer_list<T> init)
    {
        std::copy(init.begin(), init.end(), base_type::begin());
    }

    template <class T>
    inline auto chess_array<T>::operator[](char c) -> reference
    {
        return base_type::operator[](index(c));
    }

    template <class T>
    inline auto chess_array<T>::operator[](char c) const -> const_reference
    {
        return base_type::operator[](index(c));
    }

    template <class T>
    inline auto chess_array<T>::at(char c) -> reference
    {
        return base_type::at(index(c));
    }

    template <class T>
    inline auto chess_array<T>::at(char c) const -> const_reference
    {
        return base_type::at(index(c));
    }

    template <class T>
    inline auto chess_array<T>::index(char c) const -> size_type
    {
        return static_cast<size_type>(c - 'a');
    }

    template <class T>
    void swap(chess_array<T>& ca1, chess_array<T>& ca2)
    {
        ca1.swap(ca2);
    }
}

#endif
