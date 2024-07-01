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


mpz_class doubleAndAddMultiplication(const mpz_class& a, const mpz_class& b) {
    mpz_class result = 0; // Khởi tạo kết quả
    mpz_class addend = a; // Giá trị bắt đầu là a
    mpz_class multiplier = b; // Giá trị bắt đầu là b

    while (multiplier > 0) {
        // Nếu bit thấp nhất của multiplier là 1, thêm addend vào result
        if (mpz_tstbit(multiplier.get_mpz_t(), 0)) {
            result += addend;
        }
        // Nhân đôi addend
        addend <<= 1;
        // Dịch phải multiplier để xử lý bit tiếp theo
        multiplier >>= 1;
    }

    return result;
}

mpz_class montgomeryLadder(const mpz_class &base, const mpz_class &exponent, const mpz_class &mod) {
    mpz_class R0 = 1;
    mpz_class R1 = base;

    for (ssize_t i = mpz_sizeinbase(exponent.get_mpz_t(), 2) - 1; i >= 0; --i) {
        if (mpz_tstbit(exponent.get_mpz_t(), i)) {
            R0 = (R0 * R1) % mod;
            R1 = (R1 * R1) % mod;
        } else {
            R1 = (R0 * R1) % mod;
            R0 = (R0 * R0) % mod;
        }
    }
    return R0;
}

int main()
{
    // mpz_class base("5");
    // mpz_class exponent("2");
    // mpz_class mod("1212");

    // mpz_class result = montgomeryLadder(base, exponent, mod);
    // std::cout << "Result: " << result << std::endl;

    // mpz_class a, b;

    // std::cout << "Nhập số thứ nhất: ";
    // std::cin >> a;
    // std::cout << "Nhập số thứ hai: ";
    // std::cin >> b;

    // mpz_class result = doubleAndAddMultiplication(a, b);
    // std::cout << a << " * " << b << " = " << result << std::endl;

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

    ECC::ellipticCurve temp("2");
    ECC::Point Result;
    // ECC::Point _G;
    // _G.setValue("5", "1");
    // ECC::Point _P;
    // _P.setValue("5", "1");

    //temp.printECC();
    // // std::cout << "\nAfter\n"; 
    temp.printPrivateKey();
    Result = temp._mulECC_ver3();
    //temp._mulECC_ver1();
    //temp.printECC();
    
    //temp._addECC_ver1();
    // Result = temp._addECC_ver2(_G, _P);
    // Result = temp._addECC_ver2(_G, Result);
    //std::cout << "M value: " << temp.printPrivateKey() << std::endl;
    
    std::cout << "X value: " << Result.getValueX() << std::endl;
    std::cout << "Y value: " << Result.getValueY() << std::endl;
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

