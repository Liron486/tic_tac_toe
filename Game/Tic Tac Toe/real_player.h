#pragma once

#include "player.h"
#include "controller.h"

namespace Liron486
{
class RealPlayer : public Player
{
public:
    explicit RealPlayer(const PlayerData& dataToUse);
    Point makeMove() const override;

private:

    Controller controller;

};

} // namespace Liron486

