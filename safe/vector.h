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
    /// Has most of the methods for std::vector, but can be extended
    template <typename T>
    class vector
    {
        std::vector<T> base;
    public:

    };
}

#endif //VECTOR_H
