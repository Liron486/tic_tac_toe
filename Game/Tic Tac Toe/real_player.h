#ifndef _Liron486_REAL_PLAYER_HPP_
#define _Liron486_REAL_PLAYER_HPP_


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

#endif // _Liron486_REAL_PLAYER_HPP_#pragma once
