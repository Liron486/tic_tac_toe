#include "judge.h"

namespace Liron486
{
Judge::Judge(const Board& board_)
    : m_board(board_)
{
}

bool Judge::CheckForWinner(const Point& lastMove_) const
{
    const int tableDim = 3;
    int row = 0;
    int col = 0;
    int diag = 0;
    int antiDiagonal = 0;
    bool winner = false;
    char playerType = m_board.GetSquareContent(lastMove_);

    int x_lastMove = lastMove_.GetX();
    int y_lastMove = lastMove_.GetY();

    Point checkRow(x_lastMove, 0);
    Point checkCol(0, y_lastMove);
    Point checkDiag;
    Point checkAntiDiag;

    for (int i = 0; i < tableDim; ++i)
    {
        checkRow.SetY(i);
        checkCol.SetX(i);
        checkDiag.SetX(i);
        checkDiag.SetY(i);
        checkAntiDiag.SetX(i);
        checkAntiDiag.SetY(3 - i - 1);

        if (m_board.GetSquareContent(checkRow) == playerType)
        {
            ++row;
        }

        if (m_board.GetSquareContent(checkCol) == playerType)
        {
            ++col;
        }

        if (m_board.GetSquareContent(checkDiag) == playerType)
        {
            ++diag;
        }

        if (m_board.GetSquareContent(checkAntiDiag) == playerType)
        {
            ++antiDiagonal;
        }
    }

    if ((row == 3) || (col == 3) || (diag == 3) || (antiDiagonal == 3))
    {
        winner = true;
    }

    return winner;
}

const Board& Judge::GetBoard() const
{
    return m_board;
}

} // namespace Liron486