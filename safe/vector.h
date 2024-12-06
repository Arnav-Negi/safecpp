//
// Created by arnavnegi on 12/6/24.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

namespace safe
{
    /// vector: imitates std::vector except it always using the throwing at method
    /// instead of [] operator
    /// @tparam T The underlying type
    template <typename T>
    class vector : public std::vector<T>
    {
    public:
        const T& operator[](size_t pos) { return std::vector<T>::at(pos); }

        const T& back()
        {
            if (std::vector<T>::size() == 0)
                throw std::out_of_range("safe::vector::back");
            return std::vector<T>::at(this->size() - 1);
        }

        const T& front() { return std::vector<T>::at(0); }

        void pop_back()
        {
            if (std::vector<T>::size() == 0)
                throw std::out_of_range("safe::vector::pop_back");
            std::vector<T>::pop_back();
        }
    };
}

#endif //VECTOR_H
