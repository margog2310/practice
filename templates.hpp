#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>
#include <string>

template <class T>
T add(T x, T y)
{
    return x + y;
}

template <class T>
T mult(T x, int y)
{
    return x * y;
}

template <class T, class U>
auto sub(T x, U y)
{
    return x - y;
}

#endif