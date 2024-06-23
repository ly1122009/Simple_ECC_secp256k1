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
    class EllipticCurve
    {
    private:
        /* data */
    Point P;

    public:
        EllipticCurve();
        ~EllipticCurve();
    };
    
    EllipticCurve::EllipticCurve(/* args */) 
    {
        P.setValue("123", "3213");
        std::cout << P.getValueX();
    }
    
    EllipticCurve::~EllipticCurve()
    {
        
    }
    


} // namespace ECC
