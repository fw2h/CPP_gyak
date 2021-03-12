#include <cmath>
#include "point.h"

double Point::distance(const Point &p) const
{
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2))
}

