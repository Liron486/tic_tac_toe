#include <iostream>

#include "board.h"

namespace Liron486
{
Board::Board()
    : m_board()
{
    InitBoard();
}

Board::~Board()
{
}

Board::Board(const Board& other_)
    : m_board()
{
    m_board = other_.GetBoard();
}

Board& Board::operator=(const Board& other_)
{
    m_board = other_.GetBoard();
    return (*this);
}

char Board::GetSquareContent(const Point& square_) const
{
    return (m_board[square_.GetX()][square_.GetY()]);
}

void Board::SetSquare(char playerType_, const Point& square_)
{
    m_board[square_.GetX()][square_.GetY()] = playerType_;
}

void Board::InitBoard()
{
    char counter = '1';

    for (int i = 0; i < 3; ++i)
    {
        std::vector<char> newVector;
        m_board.push_back(newVector);

        for (int j = 0; j < 3; ++j)
        {
            m_board[i].push_back(counter);
            ++counter;
        }
    }
}

const std::vector<std::vector<char>>& Board::GetBoard() const
{
    return (m_board);
}

void Board::ResetBoard()
{
    for (int i = 0; i < 3; ++i)
    {
        std::vector<char>& raw = m_board[i];

        for (int j = 0; j < 3; ++j)
        {
            raw[j] = ' ';
        }
    }
}

bool Board::IsSquareEmpty(const Point& square_) const
{
    if (' ' == m_board[square_.GetX()][square_.GetY()])
    {
        return (true);
    }

    return (false);
}

} // namespace Liron486