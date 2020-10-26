#ifndef LAB3_OCTAGON_H
#define LAB3_OCTAGON_H

#include "Figure.h"
#include <iostream>

using namespace std;

// Class of octagon
class Octagon : public Figure {
private:
    double x, y, side;

public:
    // constructor
    Octagon(double i_x, double i_y, double i_side)
    {
        x = i_x;
        y = i_y;
        side = i_side;
    }
    // function to calculate square
    double Area() override
    {
        return 2 * side * side / tan(M_PI / 8);
    }
    // function to calculate geometry center of figure
    Coordinate Center() override
    {
        return Coordinate(x + side / 2, y + sqrt((1 + sqrt(2)) / sqrt(2)) * side);
    }
    // print this figure by overloaded operator
    void Print() override
    {
        cout << *this << endl;
    }
    // overloaded operator of output
    friend ostream& operator<<(ostream& out, const Octagon& octagon);
};

// Manually calculated all coordinates
ostream& operator<<(ostream& out, const Octagon& octagon)
{
    out << "Octagon: ";
    out << Coordinate(octagon.x, octagon.y) << ", ";
    out << Coordinate(octagon.x - octagon.side / sqrt(2),
                      octagon.y + octagon.side / sqrt(2))
        << ", ";
    out << Coordinate(octagon.x - octagon.side / sqrt(2),
                      octagon.y + octagon.side / sqrt(2) + octagon.side)
        << ", ";
    out << Coordinate(octagon.x, octagon.y + sqrt(2) * octagon.side + octagon.side) << ", ";
    out << Coordinate(octagon.x + octagon.side,
                      octagon.y + sqrt(2) * octagon.side + octagon.side)
        << ", ";
    out << Coordinate(octagon.x + octagon.side + octagon.side / sqrt(2),
                      octagon.y + octagon.side / sqrt(2) + octagon.side)
        << ", ";
    out << Coordinate(octagon.x + octagon.side + octagon.side / sqrt(2),
                      octagon.y + octagon.side / sqrt(2))
        << ", ";
    out << Coordinate(octagon.x + octagon.side, octagon.y);
    return out;
}
#endif // LAB3_OCTAGON_H
