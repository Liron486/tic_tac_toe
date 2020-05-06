#ifndef _Liron486_COMPUTER_HPP_
#define _Liron486_COMPUTER_HPP_

#include <memory>
#include <string>

#include "player.h"
#include "board.h"
#include "brain.h"
#include "configuration.h"
#include "judge.h"

namespace Liron486
{
class Computer : public Player
{
public:
    explicit Computer(const std::string& name_,
                      char type_,
                      const Board& board_,
                      Configuration::Difficulty difficulty_);
    ~Computer();
    Point MakeMove() const;
    const std::string GetName() const;
    char GetPlayerType() const;
    void SetPlayerType(char newType_);

private:
    const std::string m_name;
    char m_type;
    const Board& m_board;
    Configuration::Difficulty m_difficulty;
    std::unique_ptr<Brain> m_brain;
};

} // namespace Liron486

#endif // _Liron486_COMPUTER_HPP_#pragma once
