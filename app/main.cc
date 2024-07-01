/**
 * @file main.cc
 * @author Lynguyen (you@domain.com)
 * @brief Executable file
 * @version 0.1
 * @date 2024-05-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "main.hpp"
#include "common.hpp"
#include "point.hpp"
#include "ellipticCurve.hpp"
#include <gmpxx.h>


void doubleAndAddMultiplication(const mpz_class& G, const mpz_class& private_Key, mpz_class & public_Key) {
    
    mpz_class addend = G; 
    mpz_class multiplier = private_Key; 

    while (multiplier > 0) {
        // Nếu bit thấp nhất của multiplier là 1, thêm addend vào result
        if (mpz_tstbit(multiplier.get_mpz_t(), 0)) {
            public_Key += addend;
        }
        // Nhân đôi addend
        addend <<= 1;
        // Dịch phải multiplier để xử lý bit tiếp theo
        multiplier >>= 1;
    }

    
}

int main()
{

    // mpz_class a = -14;
    // mpz_class b = 17;
    // mpz_class result;
    // result = ECC::Common::mod(a, b);
    // std::cout << "-14 mod 17 = " << ECC::Common::mod(a, b) << std::endl;

    // mpz_class a("2");
    // mpz_class mod("17");
    // mpz_class result;
    // ECC::Common::modInverse(a, mod, result);
    // std::cout << result << std::endl;
    

    // mpz_class a, b, result;

    // std::cout << "Nhập số thứ nhất: ";
    // std::cin >> a;
    // std::cout << "Nhập số thứ hai: ";
    // std::cin >> b;

    // doubleAndAddMultiplication(a, b, result);
    // std::cout << a << " * " << b << " = " << result << std::endl;

    ECC::ellipticCurve temp("17");
    //temp.printECC();
    // // std::cout << "\nAfter\n"; 
  
    temp._mulECC_ver1();
    temp.printECC();

    // temp._addECC_ver1();
    // temp.printECC();


    // temp._mulECC_ver1();
    // temp.printECC();


    // mpz_class a, b, result;

    // // Gán giá trị cho các biến dưới dạng số thập phân
    // a.set_str("1234567", 10);
    // b.set_str("-764353", 10);
    // result = a + b;
    // std::cout << result << std::endl;


    // // Thực hiện phép cộng
    // result = a + 12;
    // std::cout << "Kết quả của phép cộng là: " << result << std::endl;

    // result = a % b;
    // std::cout << "Kết quả của phép mod là: " << result << std::endl;

    // ECC::Point P;
    // ECC::Point Q;
    // ECC::Point Result;

    // P.setValue("123", "-123");
    // Q.setValue("321", "-321");
    // P = Q;
    // std::cout << "P point: \n";
    // std::cout << "X value is: " << P.getValueX() << std::endl;
    // std::cout << "Y value is: " << P.getValueY() << std::endl;

    // Result = divValueX(P, P);
    // Result = mulValueX("3", Result);
    // //Result = divValueX(P, Result);

    // Khởi tạo số nguyên lớn từ chuỗi hex
    // mpz_class hexNumber("115792089237316195423570985008687907853269984665640564039457584007908834671663");

    // // In ra số thập phân tương ứng
    // std::cout << "Số thập phân tương ứng của 0x1A2B3C4D5E6F là: " << hexNumber << std::endl;

    // mpz_class num("55066263022277343669578718895168534326250603453777594175500187360389116729240");
    // mpz_class p("55066263022277343669578718895168534326250603453777594175500187360389116729240");
    // //mpz_class result;

    // if (num == p)
    // std::cout << "same" << std::endl;
    // else
    // std::cout << "diff" << std::endl;
    // Tính căn bậc hai và làm tròn xuống
    //result  = sqrt(((num * num * num) + 7) % p);
    //result = sqrt(num);

    

    // ECC::ellipticCurve temp;
    // //temp.calculatorM();
    // temp.printECC();
    // ECC::Point Result;
    // std::cout << temp.M_point();
    // Result = temp.M_point();
    
    // // ECC::printECC(Result);

    // std::cout << "Result point: \n";
    // std::cout << "X value is: " << Result.getValueX() << std::endl;
    // std::cout << "Y value is: " << Result.getValueY() << std::endl;

    // std::cout << "after\n";
    // std::cout << "Result point: \n";
    // std::cout << "X value is: " << Result.getValueX() << std::endl;
    // std::cout << "Y value is: " << Result.getValueY() << std::endl;
    
    // P.addValueX("12345");
    
    // Addition operator
    // Result = P + Q;
    
    // std::cout << "P point: \n";
    // std::cout << "X value is: " << P.getValueX() << std::endl;
    // std::cout << "Y value is: " << P.getValueY() << std::endl;

    // std::cout << "Q point: \n";
    // std::cout << "X value is: " << Q.getValueX() << std::endl;
    // std::cout << "Y value is: " << Q.getValueY() << std::endl;

    // std::cout << "Result point: \n";
    // std::cout << "X value is: " << Result.getValueX() << std::endl;
    // std::cout << "Y value is: " << Result.getValueY() << std::endl;

    // Result = "123456" + P;
    // std::cout << "Result point: \n";
    // std::cout << "X value is: " << Result.getValueX() << std::endl;
    // std::cout << "Y value is: " << Result.getValueY() << std::endl;

    // Result = P + "123456";
    // std::cout << "Result point: \n";
    // std::cout << "X value is: " << Result.getValueX() << std::endl;
    // std::cout << "Y value is: " << Result.getValueY() << std::endl;

    // Subtract operator 
    //Result = P - Q;
    
    // std::cout << "P point: \n";
    // std::cout << "X value is: " << P.getValueX() << std::endl;
    // std::cout << "Y value is: " << P.getValueY() << std::endl;

    // std::cout << "Q point: \n";
    // std::cout << "X value is: " << Q.getValueX() << std::endl;
    // std::cout << "Y value is: " << Q.getValueY() << std::endl;

    // std::cout << "Result point: \n";
    // std::cout << "X value is: " << Result.getValueX() << std::endl;
    // std::cout << "Y value is: " << Result.getValueY() << std::endl;

    // Result = 3*Q
    // std::cout << "Result point: \n";
    // std::cout << "X value is: " << Result.getValueX() << std::endl;
    // std::cout << "Y value is: " << Result.getValueY() << std::endl;

    // Result = 12345U - P;
    // std::cout << "Result point: \n";
    // std::cout << "X value is: " << Result.getValueX() << std::endl;
    // std::cout << "Y value is: " << Result.getValueY() << std::endl;

    // Result = "123456" + P;
    // std::cout << "Result point: \n";
    // std::cout << "X value is: " << Result.getValueX() << std::endl;
    // std::cout << "Y value is: " << Result.getValueY() << std::endl;

    // Result = P + "123456";
    // std::cout << "Result point: \n";
    // std::cout << "X value is: " << Result.getValueX() << std::endl;
    // std::cout << "Y value is: " << Result.getValueY() << std::endl;

    return EXIT_SUCCEED;
}

