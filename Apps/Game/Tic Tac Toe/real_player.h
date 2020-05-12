#pragma once

#include "player.h"
#include "gui.h"

namespace Liron486
{
class RealPlayer : public Player
{
public:
    explicit RealPlayer(const PlayerData& dataToUse, const Gui* guiToUse);
    Point makeMove() const override;

private:

    const Gui* gui;

};

} // namespace Liron486

