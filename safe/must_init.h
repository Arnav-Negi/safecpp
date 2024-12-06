//
// Created by arnavnegi on 12/6/24.
//

#ifndef MUST_INIT_H
#define MUST_INIT_H

namespace safe
{
    /// @brief A wrapper around a type that must be initialized with some value to avoid UB
    /// @tparam T The underlying type
    /// Can be used with any POD type, user defined types are also supported.
    template <typename T>
    class must_init
    {
        T base;
    public:
        // explicitly delete default constructor - must initialize with some value
        must_init() = delete;

        // ctors
        template <typename... Args>
        must_init(Args&&... args) : base(std::forward<Args>(args)...) {}
        must_init(const T& t) : base(t) {}
        must_init(const must_init& other) : base(other.base) {}
        must_init& operator=(const must_init& other) { base = other.base; return *this; }

        // explicit conversion to underlying type
        explicit operator T() const { return base; }

        // arithmetic
        must_init operator+() const { return +base; }
        must_init operator-() const { return -base; }

        // increment/decrement
        must_init& operator++() { ++base; return *this; }
        must_init operator++(int) { return base++; }
        must_init& operator--() { --base; return *this; }
        must_init operator--(int) { return base--; }

        // binary ops
        must_init operator+(const must_init& other) const { return base + other.base; }
        must_init operator-(const must_init& other) const { return base - other.base; }
        must_init operator*(const must_init& other) const { return base * other.base; }
        must_init operator/(const must_init& other) const { return base / other.base; }
        must_init operator%(const must_init& other) const { return base % other.base; }

        // bitwise
        must_init operator&(const must_init& other) const { return base & other.base; }
        must_init operator|(const must_init& other) const { return base | other.base; }
        must_init operator^(const must_init& other) const { return base ^ other.base; }
        must_init operator<<(const must_init& other) const { return base << other.base; }
        must_init operator>>(const must_init& other) const { return base >> other.base; }

        // comparison
        bool operator==(const must_init& other) const { return base == other.base; }
        bool operator!=(const must_init& other) const { return base != other.base; }
        bool operator<(const must_init& other) const { return base < other.base; }
        bool operator>(const must_init& other) const { return base > other.base; }
        bool operator<=(const must_init& other) const { return base <= other.base; }
        bool operator>=(const must_init& other) const { return base >= other.base; }
    };
}

#endif //MUST_INIT_H
