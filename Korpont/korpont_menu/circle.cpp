#include "circle.h"


bool Circle::contains(const Point &p) const
{
    return _c.distance(p) <= _r;
}


Point Circle::getCenter() const
{
	return _c;
}

double Circle::getRadius() const
{
	return _r;
}

void Circle::setCenter(const Point& p)
{
	_c = p;
}

void Circle::setRadius(double r)
{
	_r = r;
}
