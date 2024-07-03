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

int main()
{


    ECC::ellipticCurve temp("11302873530277286977317330088775295887228613968519091334644437952622729383175");
    ECC::Point Result;

    temp.printPrivateKey();
    Result = temp._mulECC_ver2();

    
    std::cout << "X value: " << Result.getValueX() << std::endl;
    std::cout << "Y value: " << Result.getValueY() << std::endl;


    return EXIT_SUCCEED;
}

