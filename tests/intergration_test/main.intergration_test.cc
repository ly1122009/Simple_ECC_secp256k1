#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "main.hpp"
#include <gmpxx.h>
#include "test-vector.hpp"

namespace ECC
{
    ECC::Point testPoint;
    ECC::ellipticCurve testEllipticCurve("11302873530277286977317330088775295887228613968519091334644437952622729383175");

    TEST_CASE("12312312")
    {
        testPoint = testEllipticCurve._mulECC_ver2();
        mpz_class ValueX, ValueY;
        ValueX.set_str("43762022694931184757492607356752180905518342017728551120282167112666275442351", 10);
        ValueY.set_str("114384988717018399469597034834957578408750274128921832447140766594105794755401", 10);
        REQUIRE(testPoint.getValueX() == ValueX);
        REQUIRE(testPoint.getValueY() == ValueY);
    }

    // TEST_CASE("asdasdadsad")
    // {
    //     //ECC::Point testPoint;
    //     mpz_class ValueX;
    //     testPoint.setValue("123", "456");
    //     ValueX.set_str("123", 10);
    //     //ValueY.set_str("456", 10);
    //     // ValueX = testPoint.getValueX();
    //     // ValueY = testPoint.getValueY();
    //     REQUIRE(testPoint.getValueX() == ValueX);
    // }
    
} // namespace ECC




    // TEST_CASE("ECC::ellipticCurve::_mulECC_ver2 -> Success")
    // {
    //     ECC::ellipticCurve testEllipticCurve(test::privateKey_bigNumber);
    //     ECC::Point result;
    //     mpz_class X_result, Y_result;

    //     result = testEllipticCurve._mulECC_ver2();
    //     X_result = result.getValueX();
    //     Y_result = result.getValueY();
    //     // REQUIRE( X_result == test::Output_XValue_bigNumber );
    // }

// TEST_CASE("ECC::Point::getValueX -> Success")
// {
//     //ECC::Point testPoint;
//     testPoint.setValue("123", "456");
//     mpz_class ValueX, ValueY;
//     //ValueX.set_str("123", 10);
//     ValueY.set_str("456", 10);
//     // ValueX = testPoint.getValueX();
//     // ValueY = testPoint.getValueY();
//     REQUIRE(testPoint.getValueX() == ValueX.set_str("123", 10));
// }




