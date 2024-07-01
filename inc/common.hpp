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

        static mpz_class mod(mpz_class a, mpz_class b);
        static bool modInverse(const mpz_class& a, const mpz_class& m, mpz_class& inv);

    };
    
    mpz_class Common::mod(mpz_class a, mpz_class b)
    {
        mpz_class result = a % b;
        if (result < 0) 
        {
            result += b;
        }
        return result;
    }

    bool Common::modInverse(const mpz_class& InverseValue, const mpz_class& modValue, mpz_class& result) 
    {
        return mpz_invert(result.get_mpz_t(), InverseValue.get_mpz_t(), modValue.get_mpz_t()) != 0;
    }


} // namespace ECC


// auto ellipticCurve::_addECC_ver2(Point& _G, Point& _P) -> Point
//     {
//         mpz_class x_result;
//         mpz_class x_temp;
//         mpz_class y_result;

//         mpz_class _M;
//         Point _R;

//         mpz_class modInverse_Value;
        
//         // P = R;        
//         /* The two points overlap */
//         if (_P.getValueX() == _G.getValueX() 
//             && _P.getValueY() == _G.getValueY())
//         {
//             // Calculator M value
//             Common::modInverse((2 * _G.getValueY()), this->p, modInverse_Value);
//             _M = Common::mod((_G.getValueX() * _G.getValueX()), this->p);
//             _M = Common::mod(_M * 3, this->p);
//             _M = Common::mod(_M + A, this->p);
//             _M = Common::mod(_M * modInverse_Value, this->p);
//             // this->M = ((((this->G.getValueX() * this->G.getValueX()) * 3 + A) % p) * (modInverse_Value)) % p;
            
//             // Calculator X value
//             x_result = Common::mod(_M * _M, this->p);
//             x_temp = Common::mod(2 * _G.getValueX(), this->p);
//             x_result = Common::mod(x_result - x_temp, p);
//             // x_result = (((M * M) % p) - ((2*(this->G.getValueX())) % p)) % p;
            
//             // Calculator Y value
//             y_result = Common::mod(_G.getValueX() - x_result, p);
//             y_result = Common::mod(y_result * _M, p);
//             y_result = Common::mod(y_result - _G.getValueY(), p);
//             // y_result = (((M *((this->G.getValueX() - x_result) % p)) % p) - G.getValueY()) % p;
            
//             _R.setValue(x_result, y_result);
//         }

//         /* The two points are symmetrical about the horizontal axis */
//         else if (Common::mod(-(_G.getValueY()), p) == _P.getValueY()  
//                  && _P.getValueX() == _G.getValueX())

//         // else if ((this->P.getValueY()) + (this->G.getValueY()) == static_cast<mpz_class>("0")
//         //          && this->P.getValueX() == this->G.getValueX())
//         {
//             _R.setValue("0", "0");
//         }

//         /* The P point is a O point */
//         else if (_P.getValueX() == static_cast<mpz_class>("0") 
//                 && _P.getValueY() == static_cast<mpz_class>("0"))
//         {
//             _R.setValue(_G.getValueX(), _G.getValueY());
//         }
//         /* Two different points */
//         else
//         {
//             // Calculator M value
//             Common::modInverse((_P.getValueX() - _G.getValueX()), this->p, modInverse_Value);
//             _M = Common::mod(_P.getValueY() - _G.getValueY(), p);
//             _M = Common::mod(_M * modInverse_Value, p);
//             // this->M = (((this->P.getValueY() - this->G.getValueY()) % p) 
//             //         * (modInverse_Value)) % this->p;           
            
//             // Calculator X value
//             x_result = Common::mod(_M * _M, p);
//             x_result = Common::mod(x_result - _G.getValueX(), p);
//             x_result = Common::mod(x_result - _P.getValueX(), p);
//             // x_result = (((M * M) % p) - ((G.getValueX() + P.getValueX()) % p)) % p;
            
//             // Calculator Y value
//             y_result = Common::mod(_G.getValueX() - x_result, p);
//             y_result = Common::mod(y_result * _M, p);
//             y_result = Common::mod(y_result - _G.getValueY(), p);
//             // y_result = (M*(G.getValueX() - x_result) - G.getValueY()) % p;
            
//             _R.setValue(x_result, y_result);
//         }
//         return _R;
//     }