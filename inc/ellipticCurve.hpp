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
#include "point.hpp"

namespace ECC
{
    class ellipticCurve : public Point
    {
    private:
        /* data */
        Point P;
        mpz_class M;

    public:
        /* Method */
        friend auto printECC(ellipticCurve Source) -> void; 
        auto printPoint(void) -> void;
        auto M_point(void) -> Point;

        /* Constructor & Destructor */
        ellipticCurve(/* args */);
        ~ellipticCurve();
    };
    
    auto ellipticCurve::M_point(void) -> Point
    {
        Point X_temp;
        X_temp = mulValueX(P, P);
        X_temp = mulValueX("3", X_temp);
        return X_temp;

        // Point Y_temp;
        // Y_temp = mulValueY("2", P);

        // mpz_class Result;
        // Result = X_temp.getValueX() / Y_temp.getValueY();
        // return Result;
        //return (3 * (this->P.getValueX() * this->P.getValueX())) / (2 * this->P.getValueY());
    }

    auto ellipticCurve::printPoint(void) -> void
    {
        std::cout << "X value: " << P.getValueX() << std::endl; 
        std::cout << "Y value: " << P.getValueY() << std::endl;
    }

    ellipticCurve::ellipticCurve(/* args */)
    {
        P.setValue("123", "456");
    }
    
    ellipticCurve::~ellipticCurve()
    {
    }
    
    auto printECC(ellipticCurve Source) -> void
    {
        std::cout << "Value X: " << Source.P.getValueX() << std::endl;
        std::cout << "Value Y: " << Source.P.getValueY() << std::endl;
    }


} // namespace ECC
