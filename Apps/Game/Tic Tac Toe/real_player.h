#pragma once

#include "player.h"
#include "gui.h"

namespace Liron486
{
class RealPlayer : public Player
{
public:
    explicit RealPlayer(const PlayerData& dataToUse);
    Move makeMove() const override;

};

} // namespace Liron486

