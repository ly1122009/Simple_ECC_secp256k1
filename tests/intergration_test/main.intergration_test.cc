#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "main.hpp"
#include <gmpxx.h>
#include "test-vector.hpp"

namespace ECC
{
    ECC::Point testPoint;
    ECC::ellipticCurve testEllipticCurve(test::ECC::privateKey_bigNumber);

    TEST_CASE("ECC::testEllipticCurve::_mulECC -> Success")
    {
        testPoint = testEllipticCurve._mulECC();
        mpz_class ValueX, ValueY;
        ValueX.set_str(test::ECC::publicKey_bigNumber_X, test::ECC::DecimalType);
        ValueY.set_str(test::ECC::publicKey_bigNumber_Y, test::ECC::DecimalType);
        REQUIRE(testPoint.getValueX() == ValueX);
        REQUIRE(testPoint.getValueY() == ValueY);
    }


    
} // namespace ECC
