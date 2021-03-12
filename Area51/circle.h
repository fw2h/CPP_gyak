#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "point.h"

class Circle
{
    private:
        Point _c;
        double _r;

    public:
        Circle() {}
        Circle(const Point& center, double radius) : _c(center), _r(radius) {}

        bool contains(const Point &p) const;

		Point getCenter() const;
		double getRadius() const;

		void setCenter(const Point& p);
		void setRadius(double r);
};

#endif // CIRCLE_H_INCLUDED
