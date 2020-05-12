
#include "board.h"

namespace Liron486
{
Point::Point(int xToUse, int yToUse)
    : x(xToUse)
    , y(yToUse)
{
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int xToUse)
{
    x = xToUse;
}

void Point::setY(int yToUse)
{
    y = yToUse;
}

Point Point::convertNumToPoint(int numToUse)
{
    Point new_point;

    new_point.setX((numToUse - 1) / 3);
    new_point.setY((numToUse - 1) % 3);

    return new_point;
}

bool Point::isPointUnique() const
{
    return (x == 3) && (y == 3);
}

} // namespace Liron486