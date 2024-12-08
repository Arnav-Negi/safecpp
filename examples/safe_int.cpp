//
// Created by arnavnegi on 12/7/24.
//

#include <iostream>

#include "../safe/safe_int.h"

int main()
{
    safe::safe_int<int> a(std::numeric_limits<int>::max());
    safe::safe_int<int> b(1);

    // This will throw an overflow error
    try
    {
        a += b;
    }
    catch (const std::overflow_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    a = std::numeric_limits<int>::min();
    b = -1;

    // This will throw an underflow error
    try
    {
        a += b;
    }
    catch (const std::underflow_error& e)
    {
        std::cout << e.what() << std::endl;
    }

}