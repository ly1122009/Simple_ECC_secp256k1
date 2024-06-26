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
        mpz_class private_key;
        static constexpr uint8_t A = 0;
        static constexpr uint8_t B = 7;
    public:
        /* Method */
        friend auto printECC(ellipticCurve Source) -> void;
        auto printG(void) -> void; 
        auto printP(void) -> void;
        auto printM(void) -> void;
        auto printR(void) -> void;
        auto printPrivateKey(void) -> void;
        auto printECC(void) -> void;
        
        auto _addECC(void) -> void;
        auto _mulECC(void) -> void;

        /* Constructor & Destructor */
        ellipticCurve(/* args */);
        ellipticCurve(const std::string private_key);
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
        if (this->P.getValueX() == this->G.getValueX() 
            && this->P.getValueY() == this->G.getValueY())
        {
            this->M = ((this->G.getValueX() * this->G.getValueX()) * 3 + A) / (2 * this->G.getValueY());
            x_temp = ((M * M) - (2*(this->G.getValueX()))) % p;
            y_temp = (M*(this->G.getValueX() - x_temp) - G.getValueY()) % p;
            R.setValue(x_temp, y_temp);
        }
        /* The two points are symmetrical about the horizontal axis */
        else if ((this->P.getValueY()) + (this->G.getValueY()) == static_cast<mpz_class>("0")
                 && this->P.getValueX() == this->G.getValueX())
        {
            this->R.setValue("0", "0");
        }

        /* The P point is a O point */
        else if (this->P.getValueX() == static_cast<mpz_class>("0") 
                && this->P.getValueY() == static_cast<mpz_class>("0"))
        {
            this->R.setValue(this->getValueX(), this->getValueY());
        }
        
        /* Two different points */
        else
        {
            this->M = (this->P.getValueY() - this->G.getValueY()) 
                    / (this->P.getValueX() - this->G.getValueX());            
            x_temp = ((M * M) - (G.getValueX() + P.getValueX())) % p;
            y_temp = (M*(G.getValueX() - x_temp) - G.getValueY()) % p;
            R.setValue(x_temp, y_temp);
        }
        P = R;
    }

    auto ellipticCurve::printECC(void) -> void
    {
        printG();
        printP();
        printM();
        printR();
        printPrivateKey();
    }

    auto ellipticCurve::printPrivateKey(void) -> void
    {
        std::cout << "Private Key: " << this->private_key << std::endl;
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

    ellipticCurve::ellipticCurve(const std::string private_key)
    {
        mpz_class x_temp;
        mpz_class y_temp;
        this->p.set_str("127", 10);

        x_temp.set_str("16", 10);
        x_temp = x_temp % p;
        y_temp.set_str("20", 10);
        y_temp = y_temp % p;
        this->G.setValue(x_temp, y_temp);

        x_temp.set_str("16", 10);
        x_temp = x_temp % p;
        y_temp.set_str("20", 10);
        y_temp = y_temp % p;
        this->P.setValue(x_temp, y_temp); 

        x_temp.set_str("0", 10);
        x_temp = x_temp % p;
        y_temp.set_str("0", 10); 
        y_temp = y_temp % p;       
        this->R.setValue(x_temp, y_temp);

        this->private_key.set_str(private_key, 16);
    }

    ellipticCurve::ellipticCurve(/* args */)
    {
        mpz_class x_temp;
        mpz_class y_temp;
        this->p.set_str("127", 10);

        x_temp.set_str("16", 10);
        x_temp = x_temp % p;
        y_temp.set_str("20", 10);
        y_temp = y_temp % p;
        this->G.setValue(x_temp, y_temp);

        x_temp.set_str("16", 10);
        x_temp = x_temp % p;
        y_temp.set_str("20", 10);
        y_temp = y_temp % p;
        this->P.setValue(x_temp, y_temp); 

        x_temp.set_str("0", 10);
        x_temp = x_temp % p;
        y_temp.set_str("0", 10); 
        y_temp = y_temp % p;       
        this->R.setValue(x_temp, y_temp);     
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
        //         mpz_class x_temp;
        // mpz_class y_temp;

        // x_temp.set_str("16", 10);
        // y_temp.set_str("20", 10);
        // this->G.setValue((x_temp % p),(y_temp % p));

        // x_temp.set_str("16", 10);
        // y_temp.set_str("20", 10);
        // this->P.setValue((x_temp % p),(y_temp % p)); 

        // x_temp.set_str("0", 10);
        // y_temp.set_str("0", 10);        
        // this->R.setValue((x_temp % p),(y_temp % p));
        
        // this->p.set_str("127", 10);