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
    explicit RealPlayer(const std::string name_,
                        const char type_,
                        const Board& board_);
    Point MakeMove() const;
    const std::string GetName() const;
    char GetPlayerType() const;
    void SetPlayerType(char newType_);

private:
    const std::string m_name;
    char m_type;
    Controller m_controller;
    const Board& m_board;
};

} // namespace Liron486

#endif // _Liron486_REAL_PLAYER_HPP_#pragma once
