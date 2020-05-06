#ifndef _Liron486_POINT_HPP_
#define _Liron486_POINT_HPP_

namespace Liron486
{
class Point
{
public:
    explicit Point(int x_ = 0, int y_ = 0);
    ~Point();
    Point(const Point& other_);
    Point& operator=(const Point& other_);
    int GetX() const;
    int GetY() const;
    void SetX(int x_);
    void SetY(int y_);
    static Point ConvertNumToPoint(int num);
    bool IsPointUnique() const;

private:
    int m_x;
    int m_y;
};

} // namespace Liron486

#endif // _Liron486_POINT_HPP_#pragma once
