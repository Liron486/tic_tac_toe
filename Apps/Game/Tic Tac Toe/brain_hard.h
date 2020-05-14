#pragma once

#include "brain.h"
#include "board.h"

namespace Liron486
{
class BrainHard : public Brain
{
public:
    explicit BrainHard(const Board& boardToUse, CellTypes typeToUse);
    Move getNextMove() const override;
    CellTypes getType() const override;
    void setType(CellTypes typeToUse) override;

private:
    const Board& board;
    CellTypes myType;
};

} // namespace Liron486


