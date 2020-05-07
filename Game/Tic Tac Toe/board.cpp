#include <iostream>

#include "board.h"

namespace Liron486
{
const int num_of_rows = 3;
const int num_of_cols = 3;

Board::Board()
{
    InitBoard();
}

Board::Board(const Board& other_)
{
    m_board = other_.GetBoard();
}

Board& Board::operator=(const Board& other_)
{
    m_board = other_.GetBoard();
    return *this;
}

char Board::GetSquareContent(const Point& square_) const
{
    return m_board[square_.GetX()][square_.GetY()];
}

void Board::SetSquare(char playerType_, const Point& square_)
{
    m_board[square_.GetX()][square_.GetY()] = playerType_;
}

void Board::InitBoard()
{
    char cell_number = '1';

    for (int i = 0; i < num_of_rows; ++i)
    {
        std::vector<char> newVector;
        m_board.push_back(newVector);

        for (int j = 0; j < num_of_cols; ++j)
        {
            m_board[i].push_back(cell_number);
            ++cell_number;
        }
    }
}

const std::vector<std::vector<char>>& Board::GetBoard() const
{
    return m_board;
}

void Board::ResetBoard()
{
    for (int i = 0; i < num_of_rows; ++i)
    {
        std::vector<char>& raw = m_board[i];

        for (int j = 0; j < num_of_cols; ++j)
        {
            raw[j] = ' ';
        }
    }
}

bool Board::IsSquareEmpty(const Point& square_) const
{
    if (m_board[square_.GetX()][square_.GetY()] == ' ')
    {
        return true;
    }

    return false;
}

} // namespace Liron486