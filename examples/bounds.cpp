//
// Created by arnavnegi on 12/6/24.
//

#include <iostream>

#include "../safe/vector.h"
#include "../safe/array.h"
#include "../safe/deque.h"

int main()
{
    // safe vector is a drop-in replacement for std::vector
    // all methods use safe throwing at method instead of [] operator
    // or throw on empty vector
    safe::vector<int> v({1, 2, 3});
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }

    try
    {
        std::cout << v[3] << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Out of range exception caught" << std::endl;
    }

    v.assign(4, 4);
    safe::vector<int> b;
    try
    {
        std::cout << v.back() << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Out of range exception caught" << std::endl;
    }

    // array and deque are also available
    safe::array<int, 3> a({1, 2, 3});
    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << std::endl;
    }

    try
    {
        std::cout << a[4] << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Out of range exception caught" << std::endl;
    }

    safe::deque<int> d({1, 2, 3});
    for (size_t i = 0; i < d.size(); ++i)
    {
        std::cout << d[i] << std::endl;
    }

    try
    {
        std::cout << d[4] << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Out of range exception caught" << std::endl;
    }
}

