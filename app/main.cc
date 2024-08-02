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


int main()
{

    // ECC::ellipticCurve temp("11302873530277286977317330088775295887228613968519091334644437952622729383175");
    // ECC::Point Result;
    
    // temp.printECC();
    // Result = temp._mulECC();
    // std::cout << "\n\nAfter:\n\n";  
    
    // std::cout << "X value: " << Result.getValueX() << std::endl;
    // std::cout << "Y value: " << Result.getValueY() << std::endl;
    
    // std::cout << "\n\nAfter:\n\n";
    // temp.printECC();

    ECC::ellipticCurve temp(2, 2, 
    "5", //Gx
    "1", //Gy
    "17"); // p
    ECC::Point Result;
    
    /* Mul with 2 times */
    Result = temp._mulECC("2");
    std::cout << "Result: \n";
    std::cout << "X value: " << Result.getValueX() << std::endl;
    std::cout << "Y value: " << Result.getValueY() << std::endl;

    std::cout << "After: \n";

    /* mul with 9 times */
    Result = temp._mulECC("7");
    std::cout << "Result: \n";
    std::cout << "X value: " << Result.getValueX() << std::endl;
    std::cout << "Y value: " << Result.getValueY() << std::endl;



    
    

    return EXIT_SUCCEED;
}

