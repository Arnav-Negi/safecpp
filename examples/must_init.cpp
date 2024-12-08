//
// Created by arnavnegi on 12/6/24.
//

#include <iostream>

#include "../safe/must_init.h"

#include "safe_int.h"

int main()
{
    // safe::must_init<int> a; // This line will not compile

    // must initialize with some value to avoid UB
    safe::must_init<int> a = 5;
    safe::must_init<int> b = 9;

    // underlying value can be accessed using explicit conversion
    // arithmetic operations are supported
    std::cout << static_cast<int>(a + b) << std::endl;
    std::cout << static_cast<int>(a - b) << std::endl;
    std::cout << static_cast<int>(a * b) << std::endl;
    std::cout << static_cast<int>(a / b) << std::endl;

    // bitwise operations are supported
    std::cout << static_cast<int>(a & b) << std::endl;
    std::cout << static_cast<int>(a | b) << std::endl;

    // comparison operations are supported
    std::cout << (a == b) << std::endl;
    std::cout << (a != b) << std::endl;

    // other POD types are supported as well
    safe::must_init<double> c = 5.5;
    safe::must_init<char> ch = 'A';
    safe::must_init<int**> p = nullptr;

    // user defined types are supported as well
    struct S
    {
        int a;
        double b;
    };
    safe::must_init<S> s = {5, 5.5};
    std::cout << "S { " << static_cast<S>(s).a << ", " << static_cast<S>(s).b << " }" << std::endl;

    // also works with enums
    enum color
    {
        red, blue, yellow
    };
    safe::must_init<color> col = red;
    std::cout << static_cast<color>(col) << std::endl;
}
