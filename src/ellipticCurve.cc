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

    auto ellipticCurve::getP(void) -> Point
    {
        return this->P;
    }

    auto ellipticCurve::getG(void) -> Point
    {
        return this->G;
    }

    auto ellipticCurve::getR(void) -> Point
    {
        return this->R;
    }

    auto ellipticCurve::_mulECC_ver3(void) -> Point
    {
        P = G;
        while (private_key > 0)
        {
            //if (private_key % 2 == 1)
            if (mpz_tstbit(private_key.get_mpz_t(), 0))
            {
                R = _addECC_ver2(P, R);
                //P = R;
                // private_key--;        
            }
            P = _double(P);
            private_key >>= 1;
        }
        return R;
        //R = _addECC_ver2(R, P);
    }

    auto ellipticCurve::_mulECC_ver2(void) -> void
    {
        while (private_key > 0)
        {
            if (private_key % 2 == 1)
            {
                R = _addECC_ver2(G, P);
                //P = R;
                // private_key--;        
            }
            P = _addECC_ver2(P, P);
            private_key = private_key / 2;
        }
    }

    auto ellipticCurve::_mulECC_ver1(void) -> void
    {
        while (private_key)
        {
            R = _addECC_ver2(G, P);
            P = R;
            private_key--;
        }
    }

    auto ellipticCurve::_addECC_ver3(Point& _G, Point& _P) -> Point
    {
        Point Result;
        return Result;
    }

    auto ellipticCurve::_addECC_ver2(Point& _G, Point& _P) -> Point
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

    auto ellipticCurve::_addECC_ver1(void) -> void
    {
        mpz_class x_result;
        mpz_class x_temp;
        mpz_class y_result;

        mpz_class modInverse_Value;
        
        // P = R;
        
        /* The two points overlap */
        if (this->P.getValueX() == this->G.getValueX() 
            && this->P.getValueY() == this->G.getValueY())
        {
            // Calculator M value
            Common::modInverse((2 * this->G.getValueY()), this->p, modInverse_Value);
            this->M = Common::mod((this->G.getValueX() * this->G.getValueX()), this->p);
            this->M = Common::mod(M * 3, this->p);
            this->M = Common::mod(M + A, this->p);
            this->M = Common::mod(M * modInverse_Value, this->p);
            // this->M = ((((this->G.getValueX() * this->G.getValueX()) * 3 + A) % p) * (modInverse_Value)) % p;
            
            // Calculator X value
            x_result = Common::mod(this->M * this->M, this->p);
            x_temp = Common::mod(2 * this->G.getValueX(), this->p);
            x_result = Common::mod(x_result - x_temp, p);
            // x_result = (((M * M) % p) - ((2*(this->G.getValueX())) % p)) % p;
            
            // Calculator Y value
            y_result = Common::mod(this->G.getValueX() - x_result, p);
            y_result = Common::mod(y_result * M, p);
            y_result = Common::mod(y_result - G.getValueY(), p);
            // y_result = (((M *((this->G.getValueX() - x_result) % p)) % p) - G.getValueY()) % p;
            
            R.setValue(x_result, y_result);
        }
        /* The two points are symmetrical about the horizontal axis */
        else if (Common::mod(-(this->G.getValueY()), p) == P.getValueY()  
                 && this->P.getValueX() == this->G.getValueX())

        // else if ((this->P.getValueY()) + (this->G.getValueY()) == static_cast<mpz_class>("0")
        //          && this->P.getValueX() == this->G.getValueX())
        {
            this->R.setValue("0", "0");
        }

        /* The P point is a O point */
        else if (this->P.getValueX() == static_cast<mpz_class>("0") 
                && this->P.getValueY() == static_cast<mpz_class>("0"))
        {
            this->R.setValue(this->G.getValueX(), this->G.getValueY());
        }
        
        /* Two different points */
        else
        {
            // Calculator M value
            Common::modInverse((this->P.getValueX() - this->G.getValueX()), this->p, modInverse_Value);
            M = Common::mod(this->P.getValueY() - this->G.getValueY(), p);
            M = Common::mod(M * modInverse_Value, p);
            // this->M = (((this->P.getValueY() - this->G.getValueY()) % p) 
            //         * (modInverse_Value)) % this->p;           
            
            // Calculator X value
            x_result = Common::mod(M * M, p);
            x_result = Common::mod(x_result - G.getValueX(), p);
            x_result = Common::mod(x_result - P.getValueX(), p);
            // x_result = (((M * M) % p) - ((G.getValueX() + P.getValueX()) % p)) % p;
            
            // Calculator Y value
            y_result = Common::mod(G.getValueX() - x_result, p);
            y_result = Common::mod(y_result * M, p);
            y_result = Common::mod(y_result - G.getValueY(), p);
            // y_result = (M*(G.getValueX() - x_result) - G.getValueY()) % p;
            
            R.setValue(x_result, y_result);
        }
        
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
        this->p.set_str("17", 10);

        x_temp.set_str("5", 10);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("1", 10);
        y_temp = Common::mod(y_temp, p);
        this->G.setValue(x_temp, y_temp);

        x_temp.set_str("5", 10);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("1", 10);
        y_temp = Common::mod(y_temp, p);
        this->P.setValue(x_temp, y_temp); 

        x_temp.set_str("0", 10);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("0", 10); 
        y_temp = Common::mod(y_temp, p);       
        this->R.setValue(x_temp, y_temp);

        this->private_key.set_str(private_key, 10);
    }

    ellipticCurve::ellipticCurve(/* args */)
    {
        mpz_class x_temp;
        mpz_class y_temp;
        this->p.set_str("17", 10);

        x_temp.set_str("5", 10);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("1", 10);
        y_temp = Common::mod(y_temp, p);
        this->G.setValue(x_temp, y_temp);

        x_temp.set_str("5", 10);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("1", 10);
        y_temp = Common::mod(y_temp, p);
        this->P.setValue(x_temp, y_temp); 

        x_temp.set_str("0", 10);
        x_temp = Common::mod(x_temp, p);
        y_temp.set_str("0", 10); 
        y_temp = Common::mod(y_temp, p);       
        this->R.setValue(x_temp, y_temp);     
    }
    
    auto printECC(ellipticCurve Source) -> void
    {
        std::cout << "Value X: " << Source.R.getValueX() << std::endl;
        std::cout << "Value Y: " << Source.R.getValueY() << std::endl;
    }

} // namespace ECC
