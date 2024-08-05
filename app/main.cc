/**
 * @file main.cc
 * @author Lynguyen 
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

    // ECC::ellipticCurve temp(2, 2, 
    // "5", //Gx
    // "1", //Gy
    // "17"); // p
    // ECC::Point Result;
    
    // /* Mul with 2 times */
    // Result = temp._mulECC("2");
    // std::cout << "Result: \n";
    // std::cout << "X value: " << Result.getValueX() << std::endl;
    // std::cout << "Y value: " << Result.getValueY() << std::endl;

    // std::cout << "After: \n";

    // /* mul with 9 times */
    // Result = temp._mulECC("7");
    // std::cout << "Result: \n";
    // std::cout << "X value: " << Result.getValueX() << std::endl;
    // std::cout << "Y value: " << Result.getValueY() << std::endl;

    // ECC::ellipticCurve NewEllipticCurve(2, 2,   // A = 2, B = 2
    //                                     "5", //Gx
    //                                     "1", //Gy
    //                                     "17"); // p
    // ECC::Point Result;

    // /* Mul with 2 times */
    // Result = NewEllipticCurve._mulECC("19");
    // std::cout << "Result: \n";
    // std::cout << "X value: " << Result.getValueX() << std::endl;
    // std::cout << "Y value: " << Result.getValueY() << std::endl;

    // std::cout << "After: \n";

    // /* mul with 9 times */
    // Result = NewEllipticCurve._mulECC("7");
    // std::cout << "Result: \n";
    // std::cout << "X value: " << Result.getValueX() << std::endl;
    // std::cout << "Y value: " << Result.getValueY() << std::endl;

    // Secp256k1
    ECC::ellipticCurve NewEllipticCurve(0, 7,   // A = 2, B = 2
                                        "55066263022277343669578718895168534326250603453777594175500187360389116729240", //Gx
                                        "32670510020758816978083085130507043184471273380659243275938904335757337482424", //Gy
                                        "115792089237316195423570985008687907853269984665640564039457584007908834671663"); // p
    ECC::Point Result;
    
    Result = NewEllipticCurve._mulECC("11302873530277286977317330088775295887228613968519091334644437952622729383175");
    std::cout << "\nAfter:\n";  
    
    std::cout << "X value: " << Result.getValueX() << std::endl;
    std::cout << "Y value: " << Result.getValueY() << std::endl;
    
// 43762022694931184757492607356752180905518342017728551120282167112666275442351
// 114384988717018399469597034834957578408750274128921832447140766594105794755401
    return EXIT_SUCCEED;
}

