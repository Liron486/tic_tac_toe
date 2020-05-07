#include <iostream>

#include "Board.h"

namespace Liron486
{
constexpr int numOfRows= 3;
constexpr int numOfCols = 3;

Board::Board()
{
    InitBoard();
}

char Board::GetSquareContent(const Point& squareToUse) const
{
    return board[squareToUse.GetX()][squareToUse.GetY()];
}

void Board::setSquare(char playerTypeToUse, const Point& squareToUse)
{
    board[squareToUse.GetX()][squareToUse.GetY()] = playerTypeToUse;
}

void Board::InitBoard()
{
    auto cell_number = '1';

    for (auto i = 0; i < numOfRows; ++i)
    {
        std::vector<char> newVector;
        board.push_back(newVector);

        for (auto j = 0; j < numOfCols; ++j)
        {
            board[i].push_back(cell_number);
            ++cell_number;
        }
    }
}

const std::vector<std::vector<char>>& Board::getBoard() const
{
    return board;
}

void Board::ResetBoard()
{
    for (auto i = 0; i < numOfRows; ++i)
    {
        auto& row = board[i];

        for (auto j = 0; j < numOfCols; ++j)
        {
            row[j] = ' ';
        }
    }
}

bool Board::IsSquareEmpty(const Point& square_) const
{
    if (board[square_.GetX()][square_.GetY()] == ' ')
    {
        return true;
    }

    return false;
}

} // namespace Liron486