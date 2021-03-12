#include <cmath>
#include "point.h"


double Point::distance(const Point &p) const
{
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}
