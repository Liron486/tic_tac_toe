#pragma once

#include "board.h"

namespace Liron486
{
class Judge
{
public:
    explicit Judge(const Board& boardToUse);
    bool checkForWinner(const Point& lastMoveToUse) const;

private:
    const Board& board;
};

} // namespace Liron486
