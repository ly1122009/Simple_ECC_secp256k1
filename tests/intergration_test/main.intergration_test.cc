#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "main.hpp"
#include <gmpxx.h>
#include "test-vector.hpp"

namespace ECC
{
    
    //ECC::ellipticCurve testEllipticCurve(test::ECC::privateKey_bigNumber);
    
    /* y^2 = x^3 + 7 (Secp256k1) */
    // ECC::ellipticCurve testEllipticCurve_NewConstructor(0, 7, 
    // "55066263022277343669578718895168534326250603453777594175500187360389116729240", //Gx
    // "32670510020758816978083085130507043184471273380659243275938904335757337482424", //Gy
    // "115792089237316195423570985008687907853269984665640564039457584007908834671663"); //p



    

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

    // TEST_CASE("ECC::testEllipticCurve::_mulECC(with new elliptic curve) -> Success")
    // {
        
    //     /* y^2 = x^3 + 2x + 2 */
    //     ECC::ellipticCurve testEllipticCurve_NewConstructor(2, 2, 
    //                                                         "5", //Gx
    //                                                         "1", //Gy
    //                                                         "17"); // p 
    //     mpz_class ValueX, ValueY;   
    //     /* Private Key = 2 */
    //     testPoint = testEllipticCurve_NewConstructor._mulECC("2"); 
    //     ValueX.set_str(test::ECC::publicKey_2G_X, test::ECC::DecimalType);
    //     ValueY.set_str(test::ECC::publicKey_2G_Y, test::ECC::DecimalType);
    //     REQUIRE(testPoint.getValueX() == ValueX);
    //     REQUIRE(testPoint.getValueY() == ValueY);

    //     // /* Private Key = 19 */
    //     // testPoint = testEllipticCurve_NewConstructor._mulECC("19"); 
    //     // ValueX.set_str(test::ECC::publicKey_19G_X, test::ECC::DecimalType);
    //     // ValueY.set_str(test::ECC::publicKey_19G_Y, test::ECC::DecimalType);
    //     // REQUIRE(testPoint.getValueX() == ValueX);
    //     // REQUIRE(testPoint.getValueY() == ValueY);
    // }

    //     TEST_CASE("ECC::testEllipticCurve::_mulECC Ver2(with new elliptic curve) -> Success")
    // {
    //     /* y^2 = x^3 + 2x + 2 */
    //     ECC::ellipticCurve testEllipticCurve_NewConstructor(2, 2, 
    //                                                         "5", //Gx
    //                                                         "1", //Gy
    //                                                         "17"); // p 
    //     mpz_class ValueX, ValueY;   
    //     /* Private Key = 2 */
    //     testPoint = testEllipticCurve_NewConstructor._mulECC("2"); 
    //     ValueX.set_str(test::ECC::publicKey_2G_X, test::ECC::DecimalType);
    //     ValueY.set_str(test::ECC::publicKey_2G_Y, test::ECC::DecimalType);
    //     REQUIRE(testPoint.getValueX() == ValueX);
    //     REQUIRE(testPoint.getValueY() == ValueY);
    // }

    //     TEST_CASE("ECC::testEllipticCurve::_mulECC(with Secp256k1 elliptic curve) -> Success")
    // {
    //     ECC::Point testPoint;
    //     /* y^2 = x^3 + 7 */
    //     ECC::ellipticCurve testEllipticCurve_NewConstructor(0, 7,  // A = 0, B = 7
    //                                     "55066263022277343669578718895168534326250603453777594175500187360389116729240", //Gx
    //                                     "32670510020758816978083085130507043184471273380659243275938904335757337482424", //Gy
    //                                     "115792089237316195423570985008687907853269984665640564039457584007908834671663"); // p
    //     mpz_class ValueX, ValueY;   
    //     testPoint = testEllipticCurve_NewConstructor._mulECC("11302873530277286977317330088775295887228613968519091334644437952622729383175"); 
    //     ValueX.set_str("43762022694931184757492607356752180905518342017728551120282167112666275442351", test::ECC::DecimalType);
    //     ValueY.set_str("114384988717018399469597034834957578408750274128921832447140766594105794755401", test::ECC::DecimalType);
    //     REQUIRE(testPoint.getValueX() == ValueX);
    //     REQUIRE(testPoint.getValueY() == ValueY);
    // }
    
    TEST_CASE("ECC::testEllipticCurve::_mulECC(with Secp256k1 elliptic curve) -> Success")
    {
        /* y^2 = x^3 + 7 (Secp256k1) */ 
        ECC::ellipticCurve testEllipticCurve_NewConstructor(0, 7,  // A = 0, B = 7
                                        "55066263022277343669578718895168534326250603453777594175500187360389116729240", //Gx
                                        "32670510020758816978083085130507043184471273380659243275938904335757337482424", //Gy
                                        "115792089237316195423570985008687907853269984665640564039457584007908834671663"); // p
        ECC::Point Result;
        Result = testEllipticCurve_NewConstructor._mulECC("11302873530277286977317330088775295887228613968519091334644437952622729383175");
        mpz_class valueOfX, valueOfY;
        valueOfX.set_str("43762022694931184757492607356752180905518342017728551120282167112666275442351", 10);
        valueOfY.set_str("114384988717018399469597034834957578408750274128921832447140766594105794755401", 10);
        REQUIRE(Result.getValueX() == valueOfX);
        REQUIRE(Result.getValueY() == valueOfY);
    }


} // namespace ECC
