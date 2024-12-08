//
// Created by arnavnegi on 12/7/24.
//

#ifndef SAFE_INTEGRAL_H
#define SAFE_INTEGRAL_H

#include <limits>

namespace safe
{
    template <typename T>
    class safe_int
    {
        static constexpr T min_val = std::numeric_limits<T>::min();
        static constexpr T max_val = std::numeric_limits<T>::max();

    public:
        // ctors
        explicit safe_int(T value) : value(value)
        {
        }

        safe_int() : value(0)
        {
        }

        safe_int(const safe_int& other) = default;

        safe_int(safe_int&& other) noexcept = default;

        safe_int& operator=(const safe_int& other) = default;

        safe_int& operator=(safe_int&& other) noexcept = default;

        safe_int& operator=(T value)
        {
            this->value = value;
            return *this;
        }

        // arithmetic
        safe_int operator+() const { return *this; }

        safe_int operator-() const
        {
            if (value == min_val)
            {
                throw std::underflow_error("Underflow error");
            }
            return safe_int(-value);
        }

        safe_int operator+(const safe_int& other) const
        {
            if (other.value > 0 && value > max_val - other.value)
                throw std::overflow_error("Overflow error");
            if (other.value < 0 && value < min_val - other.value)
                throw std::underflow_error("Underflow error");

            return safe_int(value + other.value);
        }

        safe_int operator-(const safe_int& other) const
        {
            if (other.value > 0 && value < min_val + other.value)
                throw std::underflow_error("Underflow error");
            if (other.value < 0 && value > max_val + other.value)
                throw std::overflow_error("Overflow error");

            return safe_int(value - other.value);
        }


        safe_int operator*(const safe_int& other) const
        {
            if (other.value == 0 || value == 0)
                return safe_int(0);
            if (other.value > 0 && value > max_val / other.value)
                throw std::overflow_error("Overflow error");
            if (other.value > 0 && value < min_val / other.value)
                throw std::underflow_error("Underflow error");
            if (other.value < 0 && value < max_val / other.value)
                throw std::overflow_error("Overflow error");
            if (other.value < 0 && value > min_val / other.value)
                throw std::underflow_error("Underflow error");

            return safe_int(value * other.value);
        }

        safe_int operator/(const safe_int& other) const
        {
            if (value == min_val && other.value == -1)
                throw std::overflow_error("Overflow error");
            return safe_int(value / other.value);
        }

        safe_int operator%(const safe_int& other) const
        {
            return safe_int(value % other.value);
        }

        safe_int operator+=(const safe_int& other)
        {
            *this = *this + other;
            return *this;
        }

        safe_int operator-=(const safe_int& other)
        {
            *this = *this - other;
            return *this;
        }

        safe_int operator*=(const safe_int& other)
        {
            *this = *this * other;
            return *this;
        }

        safe_int operator/=(const safe_int& other)
        {
            *this = *this / other;
            return *this;
        }

        safe_int operator%=(const safe_int& other)
        {
            *this = *this % other;
            return *this;
        }

        bool operator==(const safe_int& other) const
        {
            return value == other.value;
        }

        bool operator!=(const safe_int& other) const
        {
            return value != other.value;
        }

        bool operator<(const safe_int& other) const
        {
            return value < other.value;
        }

        bool operator>(const safe_int& other) const
        {
            return value > other.value;
        }

        bool operator<=(const safe_int& other) const
        {
            return value <= other.value;
        }

        bool operator>=(const safe_int& other) const
        {
            return value >= other.value;
        }

        T get() const
        {
            return value;
        }

    private:
        T value;
    };
}

#endif //SAFE_INTEGRAL_H
