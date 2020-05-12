
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

CellTypes Board::getCellContent(const Point& squareToUse) const
{
    return boardData->cells[squareToUse.getX()][squareToUse.getY()].getCellContent();
}

void Board::setCell(CellTypes playerTypeToUse, const Point& cellToUse) const
{
    boardData->cells[cellToUse.getX()][cellToUse.getY()].setCellContent(
        playerTypeToUse);
}

void Board::resetBoardData()
{
    boardData = std::make_unique<BoardData>();
}

bool Board::isSquareEmpty(const Point& cellToUse) const
{
    return (boardData->cells[cellToUse.getX()][cellToUse.getY()].getCellContent()
            == CellTypes::Empty);
}

void Board::copyCells(const Board& other) const
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