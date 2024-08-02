#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "main.hpp"
#include <gmpxx.h>
#include "test-vector.hpp"

namespace ECC
{
    ECC::Point testPoint;
    //ECC::ellipticCurve testEllipticCurve(test::ECC::privateKey_bigNumber);
    
    /* y^2 = x^3 + 7 (Secp256k1) */
    // ECC::ellipticCurve testEllipticCurve_NewConstructor(0, 7, 
    // "55066263022277343669578718895168534326250603453777594175500187360389116729240", //Gx
    // "32670510020758816978083085130507043184471273380659243275938904335757337482424", //Gy
    // "115792089237316195423570985008687907853269984665640564039457584007908834671663", //p
    // test::ECC::privateKey_bigNumber); // private key

    /* y^2 = x^3 + 2x + 2 */
    ECC::ellipticCurve testEllipticCurve_NewConstructor(2, 2, 
    "5", //Gx
    "1", //Gy
    "17", // p
    "3");

    // TEST_CASE("ECC::testEllipticCurve::_mulECC -> Success")
    // {
    //     testPoint = testEllipticCurve._mulECC();
    //     mpz_class ValueX, ValueY;
    //     ValueX.set_str(test::ECC::publicKey_bigNumber_X, test::ECC::DecimalType);
    //     ValueY.set_str(test::ECC::publicKey_bigNumber_Y, test::ECC::DecimalType);
    //     REQUIRE(testPoint.getValueX() == ValueX);
    //     REQUIRE(testPoint.getValueY() == ValueY);
    // }

    // TEST_CASE("ECC::testEllipticCurve::_mulECC(with new constructor) -> Success")
    // {
    //     testPoint = testEllipticCurve_NewConstructor._mulECC();
    //     mpz_class ValueX, ValueY;
    //     ValueX.set_str(test::ECC::publicKey_bigNumber_X, test::ECC::DecimalType);
    //     ValueY.set_str(test::ECC::publicKey_bigNumber_Y, test::ECC::DecimalType);
    //     REQUIRE(testPoint.getValueX() == ValueX);
    //     REQUIRE(testPoint.getValueY() == ValueY);
    // }

        TEST_CASE("ECC::testEllipticCurve::_mulECC(with other elliptic curve) -> Success")
    {
        testPoint = testEllipticCurve_NewConstructor._mulECC();
        mpz_class ValueX, ValueY;
        ValueX.set_str("10", test::ECC::DecimalType);
        ValueY.set_str("6", test::ECC::DecimalType);
        REQUIRE(testPoint.getValueX() == ValueX);
        REQUIRE(testPoint.getValueY() == ValueY);
    }

    
} // namespace ECC
