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
        Point R;
        /* Base Point */
        Point G;
        mpz_class p;
        mpz_class M;
        static constexpr uint8_t A = 0;
        static constexpr uint8_t B = 7;
    public:
        /* Method */
        friend auto printECC(ellipticCurve Source) -> void;
        auto printG(void) -> void; 
        auto printP(void) -> void;
        auto printM(void) -> void;
        auto printR(void) -> void;
        auto printECC(void) -> void;
        
        auto _addECC(void) -> void;
        auto _mulECC(void) -> void;

        /* Constructor & Destructor */
        ellipticCurve(/* args */);
        ~ellipticCurve() = default;
    };

    auto ellipticCurve::_mulECC(void) -> void
    {

    }

    auto ellipticCurve::_addECC(void) -> void
    {
        mpz_class x_temp;
        mpz_class y_temp;

        /* The two points overlap */
        if (this->P.getValueX() == this->G.getValueX() && this->P.getValueY() == this->G.getValueY())
        {
            this->M = ((this->P.getValueX() * this->P.getValueX()) * 3 + A) / (2 * this->P.getValueY());
            x_temp = ((M * M) - 2*(this->G.getValueX())) & p;
            y_temp = (M*(this->G.getValueX() - this->P.getValueX()) - G.getValueY()) % p;
            R.setValue(x_temp, y_temp);
            P = R;
        }
        /* The two points are symmetrical about the horizontal axis */
        else if (this->P.getValueY() + this->G.getValueY() == static_cast<mpz_class>("0")
                 && this->P.getValueX() == this->G.getValueX())
        {
            this->R.setValue("0", "0");
            P = G;
        }
        /* Two different points */
        else
        {
            this->M = (this->P.getValueY() - this->G.getValueY()) 
                    / (this->P.getValueX() - this->G.getValueX());            
            x_temp = ((M * M) - G.getValueX() - P.getValueX()) % p;
            y_temp = (M*(G.getValueX() - P.getValueX()) - G.getValueY()) % p;
            R.setValue(x_temp, y_temp);
            P = R;
        }
    }

    auto ellipticCurve::printECC(void) -> void
    {
        printG();
        printP();
        printM();
        printR();
    }

    auto ellipticCurve::printG(void) -> void
    {
        std::cout << "X value of G point: " << G.getValueX() << std::endl; 
        std::cout << "Y value of G point: " << G.getValueY() << std::endl;
    }

    auto ellipticCurve::printP(void) -> void
    {
        std::cout << "X value of P point: " << P.getValueX() << std::endl; 
        std::cout << "Y value of P point: " << P.getValueY() << std::endl;
    }

    auto ellipticCurve::printM(void) -> void
    {
        std::cout << "M value: " << this->M << std::endl;
    }

    auto ellipticCurve::printR(void) -> void
    {
        std::cout << "X value of R point: " << R.getValueX() << std::endl; 
        std::cout << "Y value of R point: " << R.getValueY() << std::endl;
    }

    ellipticCurve::ellipticCurve(/* args */)
    {
        this->G.setValue("16",
                        "20");
        this->P.setValue("41",
                        "120");        
        this->R.setValue("0", "0");
        this->p.set_str("127", 10);
    }
    
    auto printECC(ellipticCurve Source) -> void
    {
        std::cout << "Value X: " << Source.R.getValueX() << std::endl;
        std::cout << "Value Y: " << Source.R.getValueY() << std::endl;
    }


} // namespace ECC
        // this->G.setValue("55066263022277343669578718895168534326250603453777594175500187360389116729240",
        //                 "32670510020758816978083085130507043184471273380659243275938904335757337482424");
        // this->P.setValue("55066263022277343669578718895168534326250603453777594175500187360389116729240",
        //                 "32670510020758816978083085130507043184471273380659243275938904335757337482424");        
        // this->R.setValue("0", "0");
        // this->p.set_str("115792089237316195423570985008687907853269984665640564039457584007908834671663", 10);