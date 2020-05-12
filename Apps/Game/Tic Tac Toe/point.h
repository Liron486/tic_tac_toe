#pragma once

namespace Liron486
{
class Point
{
public:
    Point() = default;
    explicit Point(int xToUse, int yToUse);
    int getX() const;
    int getY() const;
    void setX(int xToUse);
    void setY(int yToUse);
    bool isPointUnique() const;
    static Point convertNumToPoint(int numToUse);

private:
    int x = 0;
    int y = 0;
};

} // namespace Liron486

