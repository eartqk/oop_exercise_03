#ifndef LAB3_SQUARE_H
#define LAB3_SQUARE_H

#include "Figure.h"
#include <iostream>

using namespace std;

// Class of square
class Square : public Figure {
private:
    double x, y, side;

public:
    // constructor
    Square(double i_x, double i_y, double i_side)
    {
        x = i_x;
        y = i_y;
        side = i_side;
    }
    // function to calculate square
    double Area() override
    {
        return side * side;
    }
    // function to calculate geometry center of figure
    Coordinate Center() override
    {
        return Coordinate(x + side / 2, y + side / 2);
    }
    // print this figure by overloaded operator
    void Print() override
    {
        cout << *this << endl;
    }
    // overloaded operator of output
    friend ostream& operator<<(ostream& out, const Square& square);
};

// Manually calculated all coordinates
ostream& operator<<(ostream& out, const Square& square)
{
    out << "Square: ";
    out << Coordinate(square.x, square.y) << ", ";
    out << Coordinate(square.x, square.y + square.side) << ", ";
    out << Coordinate(square.x + square.side, square.y + square.side) << ",";
    out << Coordinate(square.x + square.side, square.y) << ", ";
    return out;
}
#endif // LAB3_SQUARE_H
