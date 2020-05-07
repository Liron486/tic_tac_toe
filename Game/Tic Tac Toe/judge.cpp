#include "judge.h"

namespace Liron486
{
Judge::Judge(const Board& boardToUse)
    : board(boardToUse)
{
}

bool Judge::CheckForWinner(const Point& lastMoveToUse) const
{
    constexpr auto tableDim = 3;
    auto row = 0;
    auto col = 0;
    auto diag = 0;
    auto antiDiagonal = 0;
    auto winner = false;
    auto playerType = board.GetSquareContent(lastMoveToUse);

    auto x_lastMove = lastMoveToUse.GetX();
    auto y_lastMove = lastMoveToUse.GetY();

    Point checkRow(x_lastMove, 0);
    Point checkCol(0, y_lastMove);
    Point checkDiag;
    Point checkAntiDiag;

    for (auto i = 0; i < tableDim; ++i)
    {
        checkRow.SetY(i);
        checkCol.SetX(i);
        checkDiag.SetX(i);
        checkDiag.SetY(i);
        checkAntiDiag.SetX(i);
        checkAntiDiag.SetY(3 - i - 1);

        if (board.GetSquareContent(checkRow) == playerType)
        {
            ++row;
        }

        if (board.GetSquareContent(checkCol) == playerType)
        {
            ++col;
        }

        if (board.GetSquareContent(checkDiag) == playerType)
        {
            ++diag;
        }

        if (board.GetSquareContent(checkAntiDiag) == playerType)
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
    return board;
}

} // namespace Liron486