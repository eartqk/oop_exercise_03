#ifndef LAB3_TRIANGLE_H
#define LAB3_TRIANGLE_H

#include "Figure.h"
#include <iostream>

using namespace std;

// Class of triangle
class Triangle : public Figure {
private:
    double x, y, side;

public:
    // constructor
    Triangle(double i_x, double i_y, double i_side)
    {
        side = i_side;
        x = i_x;
        y = i_y;
    }
    // function to calculate square
    double Area() override
    {
        return side * side * sqrt(3) / 4;
    }
    // function to calculate geometry center of figure
    Coordinate Center() override
    {
        return Coordinate(x + side / 2, y + side * sqrt(3) / 6);
    }
    // print this figure by overloaded operator
    void Print() override
    {
        cout << *this << endl;
    }
    // overloaded operator of output
    friend ostream& operator<<(ostream& out, const Triangle& triangle);
};

// Manually calculated all coordinates
ostream& operator<<(ostream& out, const Triangle& triangle)
{
    out << "Triangle: ";
    out << Coordinate(triangle.x, triangle.y) << ", ";
    out << Coordinate(triangle.x + triangle.side / 2,
                      triangle.y + triangle.side * sqrt(3) / 2)
        << ", ";
    out << Coordinate(triangle.x + triangle.side, triangle.y);
    return out;
}

#endif // LAB3_TRIANGLE_H
