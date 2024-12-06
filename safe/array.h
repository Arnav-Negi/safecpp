//
// Created by arnavnegi on 12/6/24.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <array>
#include <stdexcept>

namespace safe
{
    /// array: imitates std::array except it always using the throwing at method
    /// instead of [] operator
    /// @tparam T The underlying type
    /// @tparam N The size of the array
    template <typename T, size_t N>
    class array : public std::array<T, N>
    {
    public:
        const T& operator[](size_t pos) { return std::array<T, N>::at(pos); }

        const T& back()
        {
            if (std::array<T, N>::size() == 0)
                throw std::out_of_range("safe::array::back");
            return std::array<T, N>::at(this->size() - 1);
        }

        const T& front() { return std::array<T, N>::at(0); }
    };
}

#endif //ARRAY_H
