#include <iostream>

#include "board.h"

namespace Liron486
{
Point::Point(int x_, int y_)
    : m_x(x_)
    , m_y(y_)
{
}

Point::~Point()
{
}

Point::Point(const Point& other_)
{
    m_x = other_.m_x;
    m_y = other_.m_y;
}

Point& Point::operator=(const Point& other_)
{
    m_x = other_.m_x;
    m_y = other_.m_y;

    return (*this);
}

int Point::GetX() const
{
    return (m_x);
}

int Point::GetY() const
{
    return (m_y);
}

void Point::SetX(int x_)
{
    m_x = x_;
}

void Point::SetY(int y_)
{
    m_y = y_;
}

Point Point::ConvertNumToPoint(int num)
{
    Point new_point;

    new_point.SetX(num / 3);
    new_point.SetY(num % 3);

    return (new_point);
}

bool Point::IsPointUnique() const
{
    return ((m_x == 3) && (m_y == 3));
}

} // namespace Liron486