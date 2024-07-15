#include "point.hpp"
#include <iostream>
#include <gmpxx.h>

namespace ECC
{
    auto moduloValueY(const Point& source, Point& other) -> Point
    {
        return Point(other.x, other.y % source.y);
    }

    auto moduloValueY(const std::string& y, Point& other) -> Point
    {
        Point temp;
        temp.y.set_str(y, Point::DecimalType);
        return Point(other.x, other.y % temp.y);
    }
    
    auto moduloValueX(const Point& source, Point& other) -> Point
    {
        return Point(other.x % source.x, other.y);
    }

    auto moduloValueX(const std::string& x, Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(x, Point::DecimalType);
        return Point(other.x % temp.x, other.y);        
    }

    auto divValueY(const Point& source, Point& other) -> Point
    {
        return Point(other.x, other.y / source.y);
    }

    auto divValueY(const std::string& y, Point& other) -> Point
    {
        Point temp;
        temp.y.set_str(y, Point::DecimalType);
        return Point(other.x, other.y / temp.y);
    }

    auto divValueX(const Point& source, Point& other) -> Point
    {
        return Point(other.x / source.x, other.y);
    }

    auto divValueX(const std::string& x, Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(x, Point::DecimalType);
        return Point(other.x / temp.x, other.y);
    }

    auto mulValueY(const Point& source, Point& other) -> Point
    {
        return Point(other.x, other.y * source.y);
    }

    auto mulValueY(const std::string& y, Point& other) -> Point
    {
        Point temp;
        temp.y.set_str(y, Point::DecimalType);
        return Point(other.x, other.y * temp.y);        
    }

    auto mulValueX(const Point& source, Point& other) -> Point
    {
        return Point(other.x * source.x, other.y);
    }

    auto mulValueX(const std::string& x, Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(x, Point::DecimalType);
        return Point(other.x * temp.x, other.y);
    }

    auto subtractValueY(const Point& source, Point& other) -> Point
    {
        return Point(other.x, other.y - source.y);
    }

    auto subtractValueY(const std::string& y, Point& other) -> Point
    {
        Point temp;
        temp.y.set_str(y, Point::DecimalType);
        return Point(other.x, other.y - temp.y);
    }

    auto subtractValueX(const Point& source, Point& other) -> Point
    {
        return Point(other.x - source.x, other.y);
    }

    auto subtractValueX(const std::string& x, Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(x, Point::DecimalType);
        return Point(other.x - temp.x, other.y);
    }

    auto addValueY(const Point& source, Point& other) -> Point
    {
        return Point(other.x, other.y + source.y);
    }

    auto addValueY(const std::string& y, Point& other) -> Point
    {
        Point temp;
        temp.y.set_str(y, Point::DecimalType);
        return Point(other.x, other.y + temp.y);        
    }

    auto addValueX(const Point& source, Point& other) -> Point
    {
        return Point(source.x + other.x, other.y);
    }

    auto addValueX(const std::string& x, Point& other) -> Point
    {
        Point temp;
        temp.x.set_str(x, Point::DecimalType);
        return Point(temp.x + other.x, other.y);
    }
    auto Point::setValueY(const mpz_class& y) -> void
    {
        this->y = y;
    }

    auto Point::setValueY(const std::string& y) -> void
    {
        this->y.set_str(y, Point::DecimalType);
    }

    auto Point::setValueX(const mpz_class& x) -> void
    {
        this->x = x;
    }

    auto Point::setValueX(const std::string& x) -> void
    {
        this->x.set_str(x, Point::DecimalType);
    }

    auto Point::setValue(const mpz_class& x, const mpz_class& y) -> void
    {
        this->x = x;
        this->y = y;
    }

    auto Point::setValue(const std::string& x, const std::string& y) -> void
    {
        this->x.set_str(x, Point::DecimalType);
        this->y.set_str(y, Point::DecimalType);
    }

    auto Point::getValueX(void) const -> mpz_class
    {
        return this->x;
    }

    auto Point::getValueY(void) const -> mpz_class
    {
        return this->y;
    }

} // namespace ECC

