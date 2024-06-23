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
#include "func.hpp"
#include "point.hpp"
#include "ellipticCurve.hpp"
#include <gmpxx.h>

int main()
{
    // mpz_class a, b, result;

    // // Gán giá trị cho các biến dưới dạng số thập phân
    // a.set_str("1234567", 10);
    // b.set_str("-764353", 10);

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
    // Result = divValueX("12345", P);
    //Result = divValueX(P, Result);
    ECC::EllipticCurve P;

    // std::cout << "P point: \n";
    // std::cout << "X value is: " << P.getValueX() << std::endl;
    // std::cout << "Y value is: " << P.getValueY() << std::endl;

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

