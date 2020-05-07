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
    explicit BrainHard(const Board& boardToUse, char typeToUse);
    Point getNextMove() const override;
    char getType() const override;
    void setType(char typeToUse) override;

private:
    const Board& board;
    char myType;
};

} // namespace Liron486

#endif // _Liron486_BRAIN_HARD_HPP_#pragma once
