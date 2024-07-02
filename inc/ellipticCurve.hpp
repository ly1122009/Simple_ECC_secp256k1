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
        static constexpr uint8_t A = 2;
        static constexpr uint8_t B = 2;
    public:
        /* Method */
        friend auto printECC(ellipticCurve Source) -> void;
        auto getP(void) -> Point;
        auto getG(void) -> Point;
        auto getR(void) -> Point;
        auto printG(void) -> void; 
        auto printP(void) -> void;
        auto printM(void) -> void;
        auto printR(void) -> void;
        auto printPrivateKey(void) -> void;
        auto printECC(void) -> void;
        
        auto _double(Point& P) -> Point;

        auto _addECC_ver1(void) -> void;
        auto _addECC_ver2(Point& _G, Point& _P) -> Point;
        auto _addECC_ver3(Point& _G, Point& _P) -> Point;

        auto _mulECC_ver1(void) -> void;
        auto _mulECC_ver2(void) -> void;
        auto _mulECC_ver3(void) -> Point;

        /* Constructor & Destructor */
        ellipticCurve(/* args */);
        ellipticCurve(const std::string private_key);
        ~ellipticCurve() = default;
    };
} // namespace ECC
        