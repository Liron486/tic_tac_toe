#pragma once

#include "brain.h"
#include "board.h"

namespace Liron486
{
class BrainEasy : public Brain
{
public:
    explicit BrainEasy(const Board& boardToUse, CellTypes typeToUse);
    Move getNextMove() const override;
    CellTypes getType() const override;
    void setType(CellTypes typeToUse) override;

private:
    const Board& board;
    CellTypes myType;
};

} // namespace Liron486

