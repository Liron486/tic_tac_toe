#ifndef _Liron486_REAL_PLAYER_HPP_
#define _Liron486_REAL_PLAYER_HPP_

#include <string>

#include "player.h"
#include "controller.h"
#include "board.h"

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
    const std::string name;
    char type;
    Controller controller;
    const Board& board;
};

} // namespace Liron486

#endif // _Liron486_REAL_PLAYER_HPP_#pragma once
