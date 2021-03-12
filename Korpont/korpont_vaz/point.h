#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

struct Point
{
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
    double distance(const Point &p) const;
};

#endif // POINT_H_INCLUDED
