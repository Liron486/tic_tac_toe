#pragma once

#include "board.h"

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
