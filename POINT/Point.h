
#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
private:
    double x;
    double y;

public:
    Point()
    {
        std::cout << "construtor padrao foi invocado" << std::endl;
    }

    Point(double x, double y)
    {
        this->x;
        this->y;
        std::cout << "costrutor com dois argumentos foi ivocado" << std::endl;
    }
    // Construtor de copia
    Point(const Point &point)
    {
        this->point.x;
        this->point.y;
    }

    void print()
    {
        std::cout << "(" << x << ","
                  << y
                  << ")" std::endl;
    }
};
#endif
