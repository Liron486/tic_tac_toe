#ifndef _Liron486_JUDGE_HPP_
#define _Liron486_JUDGE_HPP_

#include "Board.h"

namespace Liron486
{
class Judge
{
public:
    explicit Judge(const Board& boardToUse);
    bool CheckForWinner(const Point& lastMoveToUse) const;
    const Board& GetBoard() const;

private:
    const Board& board;
};

} // namespace Liron486

#endif // _Liron486_JUDGE_HPP_#pragma once
