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

        /**
         * @brief Double calculator a points
         * 
         * @param P : a point want to double
         * @return Point : result after double
         */
        auto _double(Point& P) -> Point;

        /* Print attribute of ECC */
        auto printG(void) const -> void; 
        auto printP(void) const -> void;
        auto printM(void) const -> void;
        auto printR(void) const -> void;
        auto printPrivateKey(void) const -> void;
    
    public:
        /* Constructor & Destructor */
        ellipticCurve(/* args */);
        ellipticCurve(const std::string private_key);
        ~ellipticCurve() = default;

        /* Method */
        //friend auto printECC(ellipticCurve Source) -> void;
        /**
         * @brief Get P point from ECC and assign it to another point
         * 
         * @return Point : same value with P point from ECC
         */
        auto getP(void) const -> Point;

        /**
         * @brief Get G point from ECC and assign it to another point
         * 
         * @return Point : same value with G point from ECC
         */        
        auto getG(void) const -> Point;

        /**
         * @brief Get R point from ECC and assign it to another point
         * 
         * @return Point : same value with R point from ECC
         */
        auto getR(void) const -> Point;

        /**
         * @brief Print all attribute of ECC
         * 
         */
        auto printECC(void) const -> void;

        /* Function used to test _addECC_ver2 (Not necessary now) */
        //auto _addECC_ver1(void) -> void;
        /* Function used to test _mulECC_ver2 (Not necessary now)  */
        //auto _mulECC_ver1(void) -> void;

        /**
         * @brief This function used to add two point exists in ECC
         * 
         * @param[in] _G : base point  
         * @param[in] _P : second point that exists in ECC
         * @return Point : result Point after the operation
         */
        auto _addECC(const Point& _G, const Point& _P) const -> Point;

        /**
         * @brief This function used to mul a base point with a number base on ECC multiplication rule
         * 
         * @return Point : A point after the operation
         */
        auto _mulECC(void) -> Point;

    };
} // namespace ECC
        