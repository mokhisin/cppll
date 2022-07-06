#include "number.h"
#include <cmath>
#include <iostream>

int main()
{
    using namespace cppll;
    std::cout
        << std::pow(e, ln2) / 2 << ' '
        << std::pow(std::cosh(pi), 2) - std::pow(std::sinh(pi), 2) << ' '
        << std::sqrt(pi) * inv_sqrtpi << ' '
        << std::pow(sqrt2 * sqrt3, 2) / 6 << ' '
        << sqrt3 * inv_sqrt3 << ' '
        << log2e * ln2 << ' '
        << log10e * ln10 << ' '
        << pi * inv_pi << ' '
        << phi * phi - phi << '\n';
    return 0;
}
