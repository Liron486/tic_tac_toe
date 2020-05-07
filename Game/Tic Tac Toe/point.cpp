#include <iostream>

#include "board.h"

namespace Liron486
{
Point::Point(int xToUse, int yToUse)
    : x(xToUse)
    , y(yToUse)
{
}

int Point::GetX() const
{
    return x;
}

int Point::GetY() const
{
    return y;
}

void Point::SetX(int xToUse)
{
    x = xToUse;
}

void Point::SetY(int yToUse)
{
    y = yToUse;
}

Point Point::ConvertNumToPoint(int numToUse)
{
    Point new_point;

    new_point.SetX(numToUse / 3);
    new_point.SetY(numToUse % 3);

    return new_point;
}

bool Point::IsPointUnique() const
{
    return (x == 3) && (y == 3);
}

} // namespace Liron486