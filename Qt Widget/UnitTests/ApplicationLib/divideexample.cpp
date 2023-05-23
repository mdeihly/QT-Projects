#include "divideexample.h"

#include <stdexcept>

namespace Example
{
double DivideExample::divide(double a, double b)
{
    if(0 == b)
    {
        throw std::invalid_argument("divisor (b) cannot be 0");
    }

    return a / b;
}
}
