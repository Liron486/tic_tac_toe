#pragma once

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

