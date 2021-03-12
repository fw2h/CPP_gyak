#include "circle.h"

void Circle::setc(const Point &c)
{
    this->c = c;
}

void Circle::setr(const double r)
{
    if (r>= 0) this->r = r;
    else throw "Negativ sugar nem lehet";
}

bool Circle::contains(const Point &p) const
{
    return this->c.distance(p) <= this->r;
}
