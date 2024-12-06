//
// Created by arnavnegi on 12/6/24.
//

#ifndef DEQUE_H
#define DEQUE_H

#include <deque>
#include <stdexcept>

namespace safe
{
    /// deque: imitates std::deque except it always using the throwing at method
    /// instead of [] operator
    /// @tparam T The underlying type
    template <typename T>
    class deque : public std::deque<T>
    {
    public:
        const T& operator[](size_t pos) { return std::deque<T>::at(pos); }

        const T& back()
        {
            if (std::deque<T>::size() == 0)
                throw std::out_of_range("safe::deque::back");
            return std::deque<T>::at(this->size() - 1);
        }

        const T& front() { return std::deque<T>::at(0); }

        void pop_back()
        {
            if (std::deque<T>::size() == 0)
                throw std::out_of_range("safe::deque::pop_back");
            std::deque<T>::pop_back();
        }

        void pop_front()
        {
            if (std::deque<T>::size() == 0)
                throw std::out_of_range("safe::deque::pop_front");
            std::deque<T>::pop_front();
        }
    };
}

#endif //DEQUE_H
