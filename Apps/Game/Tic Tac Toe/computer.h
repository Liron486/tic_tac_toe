#pragma once

#include <memory>

#include "player.h"
#include "brain.h"
#include "configuration.h"

namespace Liron486
{
class Computer : public Player
{
public:
    explicit Computer(const PlayerData& dataToUse,
                      Configuration::Difficulty difficultyToUse);
    Move makeMove() const override;

private:

    Configuration::Difficulty difficulty;
    std::unique_ptr<Brain> brain;
};

} // namespace Liron486


