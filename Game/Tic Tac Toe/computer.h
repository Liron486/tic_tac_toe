#ifndef _Liron486_COMPUTER_HPP_
#define _Liron486_COMPUTER_HPP_

#include <memory>

#include "player.h"
#include "brain.h"
#include "configuration.h"

namespace Liron486
{
class Computer : public Player
{
public:
    explicit Computer(const std::string& nameToUse,
                      char typeToUse,
                      const Board& boardToUse,
                      Configuration::Difficulty difficultyToUse);
    Point makeMove() const override;
    std::string getName() const override;
    char getPlayerType() const override;
    void setPlayerType(char newTypeToUse) override;

private:
    playerData playerData;
    Configuration::Difficulty difficulty;
    std::unique_ptr<Brain> brain;
};

} // namespace Liron486

#endif // _Liron486_COMPUTER_HPP_#pragma once
