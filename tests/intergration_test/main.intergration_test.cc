#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "main.hpp"
#include <gmpxx.h>
#include "test-vector.hpp"

namespace ECC
{
    ECC::Point testPoint;
    ECC::ellipticCurve testEllipticCurve(test::ECC::privateKey_bigNumber);

    TEST_CASE("ECC::testEllipticCurve::_mulECC_ver2 -> Success")
    {
        testPoint = testEllipticCurve._mulECC_ver2();
        mpz_class ValueX, ValueY;
        ValueX.set_str(test::ECC::publicKey_bigNumber_X, 10);
        ValueY.set_str(test::ECC::publicKey_bigNumber_Y, 10);
        REQUIRE(testPoint.getValueX() == ValueX);
        REQUIRE(testPoint.getValueY() == ValueY);
    }


    
} // namespace ECC
