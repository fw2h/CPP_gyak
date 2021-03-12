#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point
{
    public:
        double x, y;

        Point(double x = 0, double y = 0) : x(x), y(y) {}

        double distance(const Point &p) const;
};

#endif // POINT_H_INCLUDED
