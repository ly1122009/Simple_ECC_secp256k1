#include <iostream>
#include "common.hpp"
#include <gmpxx.h>
#include <cstdint>

namespace ECC
{
    mpz_class Common::mod(mpz_class a, mpz_class b)
    {
        mpz_class result = a % b;
        if (result < 0) 
        {
            result += b;
        }
        return result;
    }
    
    bool Common::modInverse(const mpz_class& InverseValue, const mpz_class& modValue, mpz_class& result) 
    {
        return mpz_invert(result.get_mpz_t(), InverseValue.get_mpz_t(), modValue.get_mpz_t()) != 0;
    }
    
} // namespace ECC

