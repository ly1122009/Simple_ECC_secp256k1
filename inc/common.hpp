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
        auto operator=(const Common&) -> Common& = delete;
        auto operator=(Common&&) -> Common& = delete;
        ~Common() = delete;

        static mpz_class mod(mpz_class a, mpz_class b);
        static bool modInverse(const mpz_class& InverseValue, const mpz_class& modValue, mpz_class& result);
    };
    



} // namespace ECC

