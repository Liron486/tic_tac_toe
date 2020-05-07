#ifndef _Liron486_BRAIN_HARD_HPP_
#define _Liron486_BRAIN_HARD_HPP_

#include "brain.h"
#include "board.h"
#include "judge.h"

namespace Liron486
{
class BrainHard : public Brain
{
public:
    explicit BrainHard(const Board& board_, char type_);
    virtual Point GetNextMove() const;
    virtual char GetType() const;
    virtual void SetType(char type_);

private:
    const Board& m_board;
    char m_myType;
};

} // namespace Liron486

#endif // _Liron486_BRAIN_HARD_HPP_#pragma once
