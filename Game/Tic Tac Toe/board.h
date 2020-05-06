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
    ~Board();
    Board(const Board& other_);
    Board& operator=(const Board& other_);
    char GetSquareContent(const Point& square_) const;
    void SetSquare(char playerType_, const Point& square_);
    void InitBoard();
    void ResetBoard();
    const std::vector<std::vector<char>>& GetBoard() const;
    bool IsSquareEmpty(const Point& square_) const;

private:
    std::vector<std::vector<char>> m_board;
};

} // namespace Liron486

#endif // _Liron486_BOARD_HPP_#pragma once
