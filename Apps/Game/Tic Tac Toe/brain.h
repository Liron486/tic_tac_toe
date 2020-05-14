#pragma once

#include "player.h"

namespace Liron486
{
class Brain
{
public:
    virtual ~Brain() = default;
    virtual Move getNextMove() const = 0;
    virtual CellTypes getType() const = 0;
    virtual void setType(CellTypes typeToUse) = 0;
};

} // namespace Liron486

