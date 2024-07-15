/**
 * @file EllipticCurve.hpp
 * @author Lynguyen
 * @brief File store EllipticCurve class
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include <iostream>
#include <cstdint>
#include <gmpxx.h>
#include "common.hpp"
#include "point.hpp"

namespace ECC
{
    class ellipticCurve : public Point
    {
    private:
        Point P;
        Point R;
        /* Base Point */
        Point G;
        mpz_class p;
        mpz_class M;
        mpz_class private_key;
        mpz_class public_key;
        /* Secp256k1 */
        static constexpr uint8_t A = 0;
        static constexpr uint8_t B = 7;
        /* Decimal */
        static constexpr std::uint8_t DecimalType = 10;

        auto _double(Point& P) -> Point;

    
    public:
        /* Method */
        friend auto printECC(ellipticCurve Source) -> void;
        auto getP(void) const -> Point;
        auto getG(void) const -> Point;
        auto getR(void) const -> Point;
        auto printG(void) const -> void; 
        auto printP(void) const -> void;
        auto printM(void) const -> void;
        auto printR(void) const -> void;
        auto printPrivateKey(void) const -> void;
        auto printECC(void) const -> void;

        /* Function used to test _addECC_ver2 */
        auto _addECC_ver1(void) -> void;
        /* Function used to test _mulECC_ver2 */
        auto _mulECC_ver1(void) -> void;

        /**
         * @brief This function used to add two point exists in ECC
         * 
         * @param[in] _G : base point  
         * @param[in] _P : second point that exists in ECC
         * @return Point : result Point after the operation
         */
        auto _addECC(const Point& _G, const Point& _P) -> Point;

        /**
         * @brief This function used to mul a base point with a number base on ECC multiplication rule
         * 
         * @return Point : A point after the operation
         */
        auto _mulECC(void) -> Point;

        /* Constructor & Destructor */
        ellipticCurve(/* args */);
        ellipticCurve(const std::string private_key);
        ~ellipticCurve() = default;
    };
} // namespace ECC
        