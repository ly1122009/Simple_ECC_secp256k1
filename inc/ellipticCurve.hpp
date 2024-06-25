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
        Point P;
        /* Base Point */
        Point G;
        mpz_class M;
        static constexpr uint8_t A = 0;
        static constexpr uint8_t B = 7;
    public:
        /* Method */
        friend auto printECC(ellipticCurve Source) -> void; 
        auto printP(void) -> void;
        auto printM(void) -> void;
        auto printG(void) -> void;
        auto printECC(void) -> void;

        auto _addECC(void) -> void;
        /* Constructor & Destructor */
        ellipticCurve(/* args */);
        ~ellipticCurve();
    };
    auto ellipticCurve::printECC(void) -> void
    {
        printP();
        printG();
        printM();
    }

    auto ellipticCurve::printG(void) -> void
    {
        std::cout << "X value of G point: " << G.getValueX() << std::endl; 
        std::cout << "Y value of G point: " << G.getValueY() << std::endl;
    }

    auto ellipticCurve::printM(void) -> void
    {
        std::cout << "M value: " << this->M << std::endl;
    }

    auto ellipticCurve::printP(void) -> void
    {
        std::cout << "X value of P point: " << P.getValueX() << std::endl; 
        std::cout << "Y value of P point: " << P.getValueY() << std::endl;
    }

    ellipticCurve::ellipticCurve(/* args */)
    {
        this->G.setValue("55066263022277343669578718895168534326250603453777594175500187360389116729240",
                        "32670510020758816978083085130507043184471273380659243275938904335757337482424");
        this->P.setValue("55066263022277343669578718895168534326250603453777594175500187360389116729240", 
                         "32670510020758816978083085130507043184471273380659243275938904335757337482424");
        this->M = ((this->P.getValueX() * this->P.getValueX()) * 3) / (2 * this->P.getValueY());
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
