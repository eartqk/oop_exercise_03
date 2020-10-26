#ifndef LAB3_FIGURE_H
#define LAB3_FIGURE_H

#include <cmath>
#include <istream>

using namespace std;
// Class of coordinates
class Coordinate {
protected:
    double x;
    double y;

public:
    // default constructor
    Coordinate()
    {
        x = NAN;
        y = NAN;
    }
    // constructor with agruments
    Coordinate(double a, double b)
    {
        x = a;
        y = b;
    }
    // destructor
    ~Coordinate(){};

    // friend overloading operator of output
    friend ostream& operator<<(ostream& out, const Coordinate& coordinate);
};

ostream& operator<<(ostream& out, const Coordinate& coordinate)
{
    out << "(" << coordinate.x << ", " << coordinate.y << ")";
    return out;
}

// Class of figures
class Figure {
public:
    // Pure virtual functions
    virtual double Area() = 0;
    virtual Coordinate Center() = 0;
    virtual void Print() = 0;
};

#endif // LAB3_FIGURE_H
