
#include "board.h"

#include <memory>

namespace Liron486
{
constexpr int numOfRows = 3;
constexpr int numOfCols = 3;



Board::Board()
{
    resetBoardData();
}

Board::Board(const Board& boardToUse)
{
    resetBoardData();
    copyCells(boardToUse);
}

Board& Board::operator=(const Board& boardToUse)
{
    copyCells(boardToUse);

    return *this;
}

char Board::getCellContent(const Point& squareToUse) const
{
    return boardData->cells[squareToUse.GetX()][squareToUse.GetY()].getCellContent();
}

void Board::setCell(char playerTypeToUse, const Point& cellToUse) const
{
    boardData->cells[cellToUse.GetX()][cellToUse.GetY()].setCellContent(
        playerTypeToUse);
}

void Board::resetBoardData()
{
    boardData = std::make_unique<BoardData>();
}

bool Board::isSquareEmpty(const Point& cellToUse) const
{
    return (boardData->cells[cellToUse.GetX()][cellToUse.GetY()].getCellContent()
            == ' ');
}

void Board::copyCells(const Board& other)
{
    *boardData = *other.boardData;
}

BoardData::BoardData()
{
    for (auto r = 0; r < numOfRows; ++r)
    {
        std::vector<Cell> newRow;
        cells.push_back(newRow);

        for (auto c = 0; c < numOfCols; ++c)
            cells[r].emplace_back(r, c);
    }
}
}// namespace Liron486