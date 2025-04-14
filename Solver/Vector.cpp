#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;
using VECTOR::Vector;

void Vector::setx()
{
    x = module * cos(angle);
}

void Vector::sety()
{
    y = module * sin(angle);
}

void Vector::setModule()
{
    module = sqrt(x * x + y * y);
}

void Vector::setAngle()
{
    if (abs(y) < std::numeric_limits<double>::epsilon())
    {
        if (x < 0)
        {
            angle = M_PI;
        }
        else
        {
            angle = 0.0;
        }
    }
    else
    {
        angle = atan2(y, x);
    }
}

Vector::Vector()
{
    x = y = module = angle = 0;
    mode = RECT;
}

Vector::Vector(const double param1, const double param2,
    const Mode mode) : mode{ mode }
{
    if (mode == RECT)
    {
        x = param1;
        y = param2;
        setAngle();
        setModule();
    }
    else if (mode == POL)
    {
        module = param1;
        angle = param2;
        setx();
        sety();
    }
    else
    {
        std::cout << "Ошибка!" << std::endl;
        abort();
    }
}

double Vector::getx() const
{
    return x;
}

double Vector::gety() const
{
    return y;
}

double Vector::getModule() const
{
    return module;
}

double Vector::getAngle() const
{
    return angle;
}

VECTOR::Vector::Mode VECTOR::Vector::getMode() const
{
    return mode;
}

void Vector::setRectMode()
{
    mode = RECT;
}

void Vector::setPolMode()
{
    mode = POL;
}

Vector Vector::operator+(const Vector& other) const
{
    return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector& other) const
{
    return Vector(x - other.x, y - other.y);
}

Vector Vector::operator-() const
{
    return Vector(-x, -y);
}

Vector Vector::operator*(const double coef) const
{
    return Vector(coef * x, coef * y);
}

Vector VECTOR::operator*(const double coef, const Vector& other)
{
    return other * coef;
}

std::ostream& VECTOR::operator<<(std::ostream& os,
    const Vector& other)
{
    if (other.mode == Vector::RECT)
    {
        os << "(x,y) = (" << other.x << ","
            << other.y << ")" << endl;
    }
    else if (other.mode == Vector::POL)
    {
        os << "(module,angle) = (" << other.module << ","
            << other.angle << ")" << endl;
    }
    else
    {
        os << "Ошибочное значение режима" << endl;
    }
    return os;
}
