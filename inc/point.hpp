/**
 * @file point.hpp
 * @author Lynguyen
 * @brief File stored Point class
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <iostream>
#include <cstdint>
#include <gmpxx.h>

namespace ECC
{
    class Point
    {
    private:
        /* data */
        mpz_class x;
        mpz_class y;

        static constexpr std::uint8_t DecimalType = 10;

    public:
        /* Constructor and Destructor */
        Point() = default;
        Point(mpz_class a, mpz_class b) : x(a), y(b) {}
        ~Point() = default;

        /* Method */
        auto setValueX(const std::string& x) -> void;
        auto setValueX(const mpz_class& x) -> void;
        auto setValueY(const std::string& y) -> void;
        auto setValueY(const mpz_class& y) -> void;
        auto setValue(const std::string& x, const std::string& y) -> void;
        auto setValue(const mpz_class& x, const mpz_class& y) -> void;

        auto getValueX(void) const -> mpz_class;
        auto getValueY(void) const -> mpz_class;
        
        friend auto addValueX(const std::string& x, Point& other) -> Point;
        friend auto addValueX(const Point& source, Point& other) -> Point;
        friend auto addValueY(const std::string& y, Point& other) -> Point;
        friend auto addValueY(const Point& source, Point& other) -> Point;

        friend auto subtractValueX(const std::string& x, Point& other) -> Point;
        friend auto subtractValueX(const Point& source, Point& other) -> Point;
        friend auto subtractValueY(const std::string& y, Point& other) -> Point;
        friend auto subtractValueY(const Point& source, Point& other) -> Point;

        friend auto mulValueX(const std::string& x, Point& other) -> Point;
        friend auto mulValueX(const Point& source, Point& other) -> Point;
        friend auto mulValueY(const std::string& y, Point& other) -> Point;
        friend auto mulValueY(const Point& source, Point& other) -> Point;

        friend auto divValueX(const std::string& x, Point& other) -> Point;
        friend auto divValueX(const Point& source, Point& other) -> Point;
        friend auto divValueY(const std::string& y, Point& other) -> Point;
        friend auto divValueY(const Point& source, Point& other) -> Point;   

        friend auto moduloValueX(const std::string& x, Point& other) -> Point;
        friend auto moduloValueX(const Point& source, Point& other) -> Point;
        friend auto moduloValueY(const std::string& y, Point& other) -> Point;
        friend auto moduloValueY(const Point& source, Point& other) -> Point;      
    };
    




    


} // namespace ECC



