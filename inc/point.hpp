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

    public:
        /* Constructor and Destructor */
        Point() = default;
        Point(mpz_class a, mpz_class b) : x(a), y(b) {}
        ~Point() = default;

        /* Method */
        auto setValue(const std::string& x, const std::string& y) -> void;
        auto getValueX(void) -> mpz_class;
        auto getValueY(void) -> mpz_class;
        
        /* Operator */
        auto operator+(const Point& other) const -> Point;
        friend auto operator+(const Point& other, const int32_t& numberForY) -> Point; 
        friend auto operator+(const int32_t& numberForX, const Point& other) -> Point;
        friend auto operator+(const std::string& numberForX, const Point& other) -> Point;
        friend auto operator+(const Point& other, const std::string& numberForY) -> Point; 
        
        auto operator-(const Point& other) const -> Point;
        

    };
    
    auto operator+(const Point& other, const std::string& numberForY) -> Point
    {
        Point temp;
        temp.y.set_str(numberForY, 10);
        return Point(other.x , other.y + temp.y);  
    }

    auto operator+(const std::string& numberForX, const Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(numberForX, 10);
        return Point(temp.x + other.x , other.y);
    }

    auto Point::operator+(const Point& other) const -> Point
    {
        return Point(this->x + other.x, this->y + other.y);
    }

    auto operator+(const Point& other, const int32_t& numberForY) -> Point
    {
        return Point(other.x, other.y + numberForY);
    }

    auto operator+(const int32_t& numberForX, const Point& other) -> Point
    {
        return Point(other.x + numberForX, other.y);
    }

    auto Point::setValue(const std::string& x, const std::string& y) -> void
    {
        this->x.set_str(x, 10);
        this->y.set_str(y, 10);
    }

    auto Point::getValueX(void) -> mpz_class
    {
        return this->x;
    }

    auto Point::getValueY(void) -> mpz_class
    {
        return this->y;
    }



    


} // namespace ECC



