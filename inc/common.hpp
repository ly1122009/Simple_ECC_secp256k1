/**
 * @file func.hpp
 * @author Lynguyen
 * @brief Library file
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <iostream>
#include <gmpxx.h>
#include <cstdint>

namespace ECC
{
    class Common
    {
        public:
        Common() = delete;
        Common(Common&) = delete;
        Common(Common&&) = delete;
        ~Common() = delete;

        static bool modInverse(const mpz_class& a, const mpz_class& m, mpz_class& inv);

    };
    
    bool Common::modInverse(const mpz_class& InverseValue, const mpz_class& modValue, mpz_class& result) 
    {
        return mpz_invert(result.get_mpz_t(), InverseValue.get_mpz_t(), modValue.get_mpz_t()) != 0;
    }


} // namespace ECC


