#ifndef _Liron486_POINT_HPP_
#define _Liron486_POINT_HPP_

namespace Liron486
{
class Point
{
public:
    Point() = default;
    explicit Point(int x_, int y_);
    int GetX() const;
    int GetY() const;
    void SetX(int x_);
    void SetY(int y_);
    static Point ConvertNumToPoint(int num);
    bool IsPointUnique() const;

private:
    int m_x = 0;
    int m_y = 0;
};

} // namespace Liron486


#endif // _Liron486_POINT_HPP_#pragma once
