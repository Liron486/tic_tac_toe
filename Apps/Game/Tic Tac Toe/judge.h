#pragma once

#include "board.h"

namespace Liron486
{
class Judge
{
public:
    explicit Judge(const Board& boardToUse);
    bool checkForWinner(const Point& lastMoveToUse) const;
    const Board& getBoard() const;

private:
    const Board& board;
};

} // namespace Liron486
