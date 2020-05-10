#ifndef _Liron486_REAL_PLAYER_HPP_
#define _Liron486_REAL_PLAYER_HPP_


#include "player.h"
#include "controller.h"

namespace Liron486
{
class RealPlayer : public Player
{
public:
    explicit RealPlayer(const std::string& nameToUse,
                        char typeToUse,
                        const Board& boardToUse);
    Point makeMove() const override;
    std::string getName() const override;
    char getPlayerType() const override;
    void setPlayerType(char newTypeToUse) override;

private:
    playerData playerData;
    Controller controller;

};

} // namespace Liron486

#endif // _Liron486_REAL_PLAYER_HPP_#pragma once
