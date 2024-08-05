#pragma once

#include <iostream>
#include <cstdint>


namespace test
{
    namespace ECC
    {
        static constexpr std::uint8_t DecimalType = 10;
        
        /* Test _mullECC with Secp256k1 (y^2 = x^3 + 7)
        * mod: 115792089237316195423570985008687907853269984665640564039457584007908834671663
        * A = 0
        * B = 7
        * G = (55066263022277343669578718895168534326250603453777594175500187360389116729240,
               32670510020758816978083085130507043184471273380659243275938904335757337482424)  */

        const std::string G_x = "55066263022277343669578718895168534326250603453777594175500187360389116729240";
        const std::string G_y = "32670510020758816978083085130507043184471273380659243275938904335757337482424";
        const std::string LimitsValue = "115792089237316195423570985008687907853269984665640564039457584007908834671663";
        const std::string privateKey_bigNumber = 
            "11302873530277286977317330088775295887228613968519091334644437952622729383175";
        const std::string publicKey_bigNumber_X = 
            "43762022694931184757492607356752180905518342017728551120282167112666275442351";
        const std::string publicKey_bigNumber_Y = 
            "114384988717018399469597034834957578408750274128921832447140766594105794755401";
    
        /* Test _mulECC with other elliptic curve (y^2 = x^3 + 2x+ 2)
        * mod: 17
        * A = 2
        * B = 2
        * G = (5; 1) */
        const std::string publicKey_2G_X = "6";  // Private key = 2
        const std::string publicKey_2G_Y = "3";

        const std::string publicKey_3G_X = "10"; // Private key = 3
        const std::string publicKey_3G_Y = "6";

        const std::string publicKey_4G_X = "3";
        const std::string publicKey_4G_Y = "1";

        const std::string publicKey_5G_X = "9";
        const std::string publicKey_5G_Y = "16";

        const std::string publicKey_18G_X = "5";  // Private key = 18
        const std::string publicKey_18G_Y = "16"; 

        const std::string publicKey_19G_X = "0"; // Private key = 19
        const std::string publicKey_19G_Y = "0";           

    } // namespace ECC

} // namespace test

        
