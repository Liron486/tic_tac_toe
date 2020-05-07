#ifndef _Liron486_POINT_HPP_
#define _Liron486_POINT_HPP_

namespace Liron486
{
class Point
{
public:
    Point() = default;
    explicit Point(int xToUse, int yToUse);
    int GetX() const;
    int GetY() const;
    void SetX(int xToUse);
    void SetY(int yToUse);
    bool IsPointUnique() const;
    static Point ConvertNumToPoint(int numToUse);

private:
    int x = 0;
    int y = 0;
};

} // namespace Liron486


#endif // _Liron486_POINT_HPP_#pragma once
