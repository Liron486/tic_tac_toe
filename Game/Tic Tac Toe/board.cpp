
#include "board.h"

namespace Liron486
{
constexpr int numOfRows = 3;
constexpr int numOfCols = 3;

inline void initializeBoard(BoardData& boardDataToUse)
{
    for (auto r = 0; r < numOfRows; ++r)
    {
        std::vector<Cell> newRow;
        boardDataToUse.cells.push_back(newRow);

        for (auto c = 0; c < numOfCols; ++c)
        {
            boardDataToUse.cells[r].emplace_back(r, c);
        }
    }
}

Board::Board()
    : boardData(new BoardData)
{
    initializeBoard(*boardData);
}

inline void copyCells(std::unique_ptr<BoardData>& boardDataToUse,
                      const Board& boardToUse)
{
    for (auto r = 0; r < numOfRows; ++r)
    {
        std::vector<Cell> newRow;
        boardDataToUse->cells.push_back(newRow);

        for (auto c = 0; c < numOfCols; ++c)
        {
            boardDataToUse->cells[r].emplace_back(r, c);
            boardDataToUse->cells[r][c].setCellContent(
                boardToUse.getBoardData()->cells[r][c].getCellContent());
        }
    }
}

Board::Board(const Board& boardToUse)
    : boardData(new BoardData)
{
    copyCells(boardData, boardToUse);
}

Board& Board::operator=(const Board& boardToUse)
{
    copyCells(boardData, boardToUse);

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
    boardData.reset(new BoardData);
    initializeBoard(*boardData);
}

bool Board::isSquareEmpty(const Point& cellToUse) const
{
    return (boardData->cells[cellToUse.GetX()][cellToUse.GetY()].getCellContent()
            == ' ');
}

const std::unique_ptr<BoardData>& Board::getBoardData() const
{
    return boardData;
}

} // namespace Liron486