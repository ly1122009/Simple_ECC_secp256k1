#pragma once
#include <iostream>
#include "common.hpp"
#include "point.hpp"
#include "ellipticCurve.hpp"
#include <gmpxx.h>

namespace ECC
{

    int testAdd(int a, int b)
    {
        return a + b;
    }
    
    mpz_class factorial(int n) {
    mpz_class result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

    #define EXIT_SUCCEED    0

} // namespace ECC


