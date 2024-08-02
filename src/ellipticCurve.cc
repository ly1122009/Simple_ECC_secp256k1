#include <iostream>
#include <gmpxx.h>
#include "ellipticCurve.hpp"
#include "point.hpp"

namespace ECC
{
    auto ellipticCurve::_double(Point& _P) -> Point
    {
        mpz_class x_result;
        mpz_class x_temp;
        mpz_class y_result;

        mpz_class _M;
        Point _R;

        mpz_class modInverse_Value;
        // Calculator M value
            Common::modInverse((2 * _P.getValueY()), this->p, modInverse_Value);
            _M = Common::mod((_P.getValueX() * _P.getValueX()), this->p);
            _M = Common::mod(_M * 3, this->p);
            _M = Common::mod(_M + A, this->p);
            _M = Common::mod(_M * modInverse_Value, this->p);
            // this->M = ((((this->G.getValueX() * this->G.getValueX()) * 3 + A) % p) * (modInverse_Value)) % p;
            
            // Calculator X value
            x_result = Common::mod(_M * _M, this->p);
            x_temp = Common::mod(2 * _P.getValueX(), this->p);
            x_result = Common::mod(x_result - x_temp, p);
            // x_result = (((M * M) % p) - ((2*(this->G.getValueX())) % p)) % p;
            
            // Calculator Y value
            y_result = Common::mod(_P.getValueX() - x_result, p);
            y_result = Common::mod(y_result * _M, p);
            y_result = Common::mod(y_result - _P.getValueY(), p);
            // y_result = (((M *((this->G.getValueX() - x_result) % p)) % p) - G.getValueY()) % p;
            
            _R.setValue(x_result, y_result); 
            return _R;       
    }

    auto ellipticCurve::getP(void) const -> Point
    {
        return this->P;
    }

    auto ellipticCurve::getG(void) const -> Point
    {
        return this->G;
    }

    auto ellipticCurve::getR(void) const -> Point
    {
        return this->R;
    }

    auto ellipticCurve::_mulECC(void) -> Point
    {
        Point P_temp = P;
        Point G_temp = G;
        mpz_class private_key_temp = private_key;

        /* Double and add algorithm */
        P_temp = G_temp;
        while (private_key_temp > 0)
        {
            if (mpz_tstbit(private_key_temp.get_mpz_t(), 0))
            {
                R = _addECC(P_temp, R);

            }
            P_temp = _double(P_temp);
            private_key_temp >>= 1;
        }
        return R;
    }

    // auto ellipticCurve::_mulECC_ver1(void) -> void
    // {
    //     while (private_key)
    //     {
    //         R = _addECC(G, P);
    //         P = R;
    //         private_key--;
    //     }
    // }



    auto ellipticCurve::_addECC(const Point& _G, const Point& _P) const -> Point
    {
        mpz_class x_result;
        mpz_class x_temp;
        mpz_class y_result;

        mpz_class _M;
        Point _R;

        mpz_class modInverse_Value;
        
        // P = R;        
        /* The two points overlap */
        if (_P.getValueX() == _G.getValueX() 
            && _P.getValueY() == _G.getValueY())
        {
            // Calculator M value
            Common::modInverse((2 * _G.getValueY()), this->p, modInverse_Value);
            _M = Common::mod((_G.getValueX() * _G.getValueX()), this->p);
            _M = Common::mod(_M * 3, this->p);
            _M = Common::mod(_M + A, this->p);
            _M = Common::mod(_M * modInverse_Value, this->p);
            // this->M = ((((this->G.getValueX() * this->G.getValueX()) * 3 + A) % p) * (modInverse_Value)) % p;
            
            // Calculator X value
            x_result = Common::mod(_M * _M, this->p);
            x_temp = Common::mod(2 * _G.getValueX(), this->p);
            x_result = Common::mod(x_result - x_temp, p);
            // x_result = (((M * M) % p) - ((2*(this->G.getValueX())) % p)) % p;
            
            // Calculator Y value
            y_result = Common::mod(_G.getValueX() - x_result, p);
            y_result = Common::mod(y_result * _M, p);
            y_result = Common::mod(y_result - _G.getValueY(), p);
            // y_result = (((M *((this->G.getValueX() - x_result) % p)) % p) - G.getValueY()) % p;
            
            _R.setValue(x_result, y_result);
        }

        /* The two points are symmetrical about the horizontal axis */
        else if (Common::mod(-(_G.getValueY()), p) == _P.getValueY()  
                 && _P.getValueX() == _G.getValueX())

        // else if ((this->P.getValueY()) + (this->G.getValueY()) == static_cast<mpz_class>("0")
        //          && this->P.getValueX() == this->G.getValueX())
        {
            _R.setValue("0", "0");
        }

        /* The P point is a O point */
        else if (_P.getValueX() == static_cast<mpz_class>("0") 
                && _P.getValueY() == static_cast<mpz_class>("0"))
        {
            _R.setValue(_G.getValueX(), _G.getValueY());
        }
        /* Two different points */
        else
        {
            // Calculator M value
            Common::modInverse((_P.getValueX() - _G.getValueX()), this->p, modInverse_Value);
            _M = Common::mod(_P.getValueY() - _G.getValueY(), p);
            _M = Common::mod(_M * modInverse_Value, p);
            // this->M = (((this->P.getValueY() - this->G.getValueY()) % p) 
            //         * (modInverse_Value)) % this->p;           
            
            // Calculator X value
            x_result = Common::mod(_M * _M, p);
            x_result = Common::mod(x_result - _G.getValueX(), p);
            x_result = Common::mod(x_result - _P.getValueX(), p);
            // x_result = (((M * M) % p) - ((G.getValueX() + P.getValueX()) % p)) % p;
            
            // Calculator Y value
            y_result = Common::mod(_G.getValueX() - x_result, p);
            y_result = Common::mod(y_result * _M, p);
            y_result = Common::mod(y_result - _G.getValueY(), p);
            // y_result = (M*(G.getValueX() - x_result) - G.getValueY()) % p;
            
            _R.setValue(x_result, y_result);
        }
        return _R;
    }
    // auto ellipticCurve::_addECC_ver1(void) -> void
    // {
    //     mpz_class x_result;
    //     mpz_class x_temp;
    //     mpz_class y_result;

    //     mpz_class modInverse_Value;
        
    //     // P = R;
        
    //     /* The two points overlap */
    //     if (this->P.getValueX() == this->G.getValueX() 
    //         && this->P.getValueY() == this->G.getValueY())
    //     {
    //         // Calculator M value
    //         Common::modInverse((2 * this->G.getValueY()), this->p, modInverse_Value);
    //         this->M = Common::mod((this->G.getValueX() * this->G.getValueX()), this->p);
    //         this->M = Common::mod(M * 3, this->p);
    //         this->M = Common::mod(M + A, this->p);
    //         this->M = Common::mod(M * modInverse_Value, this->p);
    //         // this->M = ((((this->G.getValueX() * this->G.getValueX()) * 3 + A) % p) * (modInverse_Value)) % p;
            
    //         // Calculator X value
    //         x_result = Common::mod(this->M * this->M, this->p);
    //         x_temp = Common::mod(2 * this->G.getValueX(), this->p);
    //         x_result = Common::mod(x_result - x_temp, p);
    //         // x_result = (((M * M) % p) - ((2*(this->G.getValueX())) % p)) % p;
            
    //         // Calculator Y value
    //         y_result = Common::mod(this->G.getValueX() - x_result, p);
    //         y_result = Common::mod(y_result * M, p);
    //         y_result = Common::mod(y_result - G.getValueY(), p);
    //         // y_result = (((M *((this->G.getValueX() - x_result) % p)) % p) - G.getValueY()) % p;
            
    //         R.setValue(x_result, y_result);
    //     }
    //     /* The two points are symmetrical about the horizontal axis */
    //     else if (Common::mod(-(this->G.getValueY()), p) == P.getValueY()  
    //              && this->P.getValueX() == this->G.getValueX())

    //     // else if ((this->P.getValueY()) + (this->G.getValueY()) == static_cast<mpz_class>("0")
    //     //          && this->P.getValueX() == this->G.getValueX())
    //     {
    //         this->R.setValue("0", "0");
    //     }

    //     /* The P point is a O point */
    //     else if (this->P.getValueX() == static_cast<mpz_class>("0") 
    //             && this->P.getValueY() == static_cast<mpz_class>("0"))
    //     {
    //         this->R.setValue(this->G.getValueX(), this->G.getValueY());
    //     }
        
    //     /* Two different points */
    //     else
    //     {
    //         // Calculator M value
    //         Common::modInverse((this->P.getValueX() - this->G.getValueX()), this->p, modInverse_Value);
    //         M = Common::mod(this->P.getValueY() - this->G.getValueY(), p);
    //         M = Common::mod(M * modInverse_Value, p);
    //         // this->M = (((this->P.getValueY() - this->G.getValueY()) % p) 
    //         //         * (modInverse_Value)) % this->p;           
            
    //         // Calculator X value
    //         x_result = Common::mod(M * M, p);
    //         x_result = Common::mod(x_result - G.getValueX(), p);
    //         x_result = Common::mod(x_result - P.getValueX(), p);
    //         // x_result = (((M * M) % p) - ((G.getValueX() + P.getValueX()) % p)) % p;
            
    //         // Calculator Y value
    //         y_result = Common::mod(G.getValueX() - x_result, p);
    //         y_result = Common::mod(y_result * M, p);
    //         y_result = Common::mod(y_result - G.getValueY(), p);
    //         // y_result = (M*(G.getValueX() - x_result) - G.getValueY()) % p;
            
    //         R.setValue(x_result, y_result);
    //     }
        
    // }

    auto ellipticCurve::printECC(void) const -> void
    {
        printG();
        printP();
        printM();
        printR();
        printPrivateKey();
    }

    auto ellipticCurve::printPrivateKey(void) const -> void
    {
        std::cout << "Private Key: " << this->private_key << std::endl;
    }

    auto ellipticCurve::printG(void) const -> void
    {
        std::cout << "X value of G point: " << G.getValueX() << std::endl; 
        std::cout << "Y value of G point: " << G.getValueY() << std::endl;
    }

    auto ellipticCurve::printP(void) const -> void
    {
        std::cout << "X value of P point: " << P.getValueX() << std::endl; 
        std::cout << "Y value of P point: " << P.getValueY() << std::endl;
    }

    auto ellipticCurve::printM(void) const -> void
    {
        std::cout << "M value: " << this->M << std::endl;
    }

    auto ellipticCurve::printR(void) const -> void
    {
        std::cout << "X value of R point: " << R.getValueX() << std::endl; 
        std::cout << "Y value of R point: " << R.getValueY() << std::endl;
    }

    ellipticCurve::ellipticCurve(const std::string private_key)
    {
        mpz_class x_temp;
        mpz_class y_temp;
        this->p.set_str("115792089237316195423570985008687907853269984665640564039457584007908834671663", ellipticCurve::DecimalType);

        x_temp.set_str("55066263022277343669578718895168534326250603453777594175500187360389116729240", ellipticCurve::DecimalType);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("32670510020758816978083085130507043184471273380659243275938904335757337482424", ellipticCurve::DecimalType);
        y_temp = Common::mod(y_temp, p);
        this->G.setValue(x_temp, y_temp);

        x_temp.set_str("55066263022277343669578718895168534326250603453777594175500187360389116729240", ellipticCurve::DecimalType);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("32670510020758816978083085130507043184471273380659243275938904335757337482424", ellipticCurve::DecimalType);
        y_temp = Common::mod(y_temp, p);
        this->P.setValue(x_temp, y_temp); 

        x_temp.set_str("0", ellipticCurve::DecimalType);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("0", ellipticCurve::DecimalType); 
        y_temp = Common::mod(y_temp, p);       
        this->R.setValue(x_temp, y_temp);

        this->private_key.set_str(private_key, ellipticCurve::DecimalType);
    }

    ellipticCurve::ellipticCurve(/* args */)
    {
        mpz_class x_temp;
        mpz_class y_temp;
        this->p.set_str("115792089237316195423570985008687907853269984665640564039457584007908834671663", ellipticCurve::DecimalType);

        x_temp.set_str("55066263022277343669578718895168534326250603453777594175500187360389116729240", ellipticCurve::DecimalType);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("32670510020758816978083085130507043184471273380659243275938904335757337482424", ellipticCurve::DecimalType);
        y_temp = Common::mod(y_temp, p);
        this->G.setValue(x_temp, y_temp);

        x_temp.set_str("55066263022277343669578718895168534326250603453777594175500187360389116729240", ellipticCurve::DecimalType);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("32670510020758816978083085130507043184471273380659243275938904335757337482424", ellipticCurve::DecimalType);
        y_temp = Common::mod(y_temp, p);
        this->P.setValue(x_temp, y_temp); 

        x_temp.set_str("0", ellipticCurve::DecimalType);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("0", ellipticCurve::DecimalType); 
        y_temp = Common::mod(y_temp, p);       
        this->R.setValue(x_temp, y_temp);     
    }

    ellipticCurve::ellipticCurve(const std::uint32_t A, const std::uint32_t B, const std::string G_x, const std::string G_y, const std::string p, const std::string private_key)
    {
        this->A = A;
        this->B = B;
        
        mpz_class x_temp;
        mpz_class y_temp;
        this->p.set_str(p, ellipticCurve::DecimalType);

        x_temp.set_str(G_x, ellipticCurve::DecimalType);
        x_temp = Common::mod(x_temp, this->p);
        y_temp.set_str(G_y, ellipticCurve::DecimalType);
        y_temp = Common::mod(y_temp, this->p);
        this->G.setValue(x_temp, y_temp);

        x_temp.set_str(G_x, ellipticCurve::DecimalType);
        x_temp = Common::mod(x_temp, this->p);
        y_temp.set_str(G_y, ellipticCurve::DecimalType);
        y_temp = Common::mod(y_temp, this->p);
        this->P.setValue(x_temp, y_temp); 

        x_temp.set_str("0", ellipticCurve::DecimalType);
        x_temp = Common::mod(x_temp, this->p);
        y_temp.set_str("0", ellipticCurve::DecimalType); 
        y_temp = Common::mod(y_temp, this->p);       
        this->R.setValue(x_temp, y_temp);

        this->private_key.set_str(private_key, ellipticCurve::DecimalType);
    }
    
    // auto printECC(ellipticCurve Source)  -> void
    // {
    //     std::cout << "Value X: " << Source.R.getValueX() << std::endl;
    //     std::cout << "Value Y: " << Source.R.getValueY() << std::endl;
    // }

} // namespace ECC

