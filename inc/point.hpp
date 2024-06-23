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
    
    auto moduloValueY(const Point& source, Point& other) -> Point
    {
        return Point(other.x, other.y % source.y);
    }

    auto moduloValueY(const std::string& y, Point& other) -> Point
    {
        Point temp;
        temp.y.set_str(y, 10);
        return Point(other.x, other.y % temp.y);
    }
    
    auto moduloValueX(const Point& source, Point& other) -> Point
    {
        return Point(other.x % source.x, other.y);
    }

    auto moduloValueX(const std::string& x, Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(x, 10);
        return Point(other.x % temp.x, other.y);        
    }

    auto divValueY(const Point& source, Point& other) -> Point
    {
        return Point(other.x, other.y / source.y);
    }

    auto divValueY(const std::string& y, Point& other) -> Point
    {
        Point temp;
        temp.y.set_str(y, 10);
        return Point(other.x, other.y / temp.y);
    }

    auto divValueX(const Point& source, Point& other) -> Point
    {
        return Point(other.x / source.x, other.y);
    }

    auto divValueX(const std::string& x, Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(x, 10);
        return Point(other.x / temp.x, other.y);
    }

    auto mulValueY(const Point& source, Point& other) -> Point
    {
        return Point(other.x, other.y * source.y);
    }

    auto mulValueY(const std::string& y, Point& other) -> Point
    {
        Point temp;
        temp.y.set_str(y, 10);
        return Point(other.x, other.y * temp.y);        
    }

    auto mulValueX(const Point& source, Point& other) -> Point
    {
        return Point(other.x * source.x, other.y);
    }

    auto mulValueX(const std::string& x, Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(x, 10);
        return Point(other.x * temp.x, other.y);
    }

    auto subtractValueY(const Point& source, Point& other) -> Point
    {
        return Point(other.x, other.y - source.y);
    }

    auto subtractValueY(const std::string& y, Point& other) -> Point
    {
        Point temp;
        temp.y.set_str(y, 10);
        return Point(other.x, other.y - temp.y);
    }

    auto subtractValueX(const Point& source, Point& other) -> Point
    {
        return Point(other.x - source.x, other.y);
    }

    auto subtractValueX(const std::string& x, Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(x, 10);
        return Point(other.x - temp.x, other.y);
    }

    auto addValueY(const Point& source, Point& other) -> Point
    {
        return Point(other.x, other.y + source.y);
    }

    auto addValueY(const std::string& y, Point& other) -> Point
    {
        Point temp;
        temp.y.set_str(y, 10);
        return Point(other.x, other.y + temp.y);        
    }

    auto addValueX(const Point& source, Point& other) -> Point
    {
        return Point(source.x + other.x, other.y);
    }

    auto addValueX(const std::string& x, Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(x, 10);
        return Point(temp.x + other.x, other.y);
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



