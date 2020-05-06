#ifndef _Liron486_JUDGE_HPP_
#define _Liron486_JUDGE_HPP_

#include "board.h"

namespace Liron486
{

    class Judge
    {
    public:
        explicit Judge(const Board& board_);
        bool CheckForWinner(const Point& lastMove_) const;
        const Board& GetBoard() const;

    private:
        const Board& m_board;
    };

} // namespace Liron486

#endif // _Liron486_JUDGE_HPP_#pragma once
