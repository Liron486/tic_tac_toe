#ifndef _Liron486_BOARD_HPP_
#define _Liron486_BOARD_HPP_

#include <vector>
#include <memory>

#include "cell.h"
#include "point.h"

namespace Liron486
{
struct BoardData
{
    BoardData();

    std::vector<std::vector<Cell>> cells;
};

class Board
{
public:
    explicit Board();
    Board(const Board& boardToUse);
    Board& operator=(const Board& boardToUse);
    char getCellContent(const Point& squareToUse) const;
    void setCell(char playerTypeToUse, const Point& cellToUse) const;
    void resetBoardData();
    bool isSquareEmpty(const Point& cellToUse) const;

private:
    void copyCells(const Board& other);
    std::unique_ptr<BoardData> boardData;
};

} // namespace Liron486

#endif // _Liron486_BOARD_HPP_#pragma once
