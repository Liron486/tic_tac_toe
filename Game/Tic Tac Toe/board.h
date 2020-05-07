#ifndef _Liron486_BOARD_HPP_
#define _Liron486_BOARD_HPP_

#include <vector>

#include "point.h"

namespace Liron486
{
class Board
{
public:
    explicit Board();
    char GetSquareContent(const Point& squareToUse) const;
    void setSquare(char playerTypeToUse, const Point& squareToUse);
    void InitBoard();
    void ResetBoard();
    const std::vector<std::vector<char>>& getBoard() const;
    bool IsSquareEmpty(const Point& square_) const;

private:
    std::vector<std::vector<char>> board;
};

} // namespace Liron486

#endif // _Liron486_BOARD_HPP_#pragma once
