#pragma once

#include <string>
#include <array>

#include "cell.h"

namespace Liron486
{
class Configuration
{
public:
    enum class Difficulty
    {
        EASY,
        HARD
    };

    explicit Configuration();
    int GetNumRealPlayers() const;
    Difficulty GetDifficulty() const;
    std::string GetPlayerName(int nPlayerToUse) const;
    CellTypes GetPlayerChoice() const;

private:
    void SetNumRealPlayers();
    void SetDifficulty();
    void SetPlayerChoice();
    void SetNamesOfPlayers(int playerNumberToUse);

    int nRealPlayers = 1;
    Difficulty difficulty = Difficulty::HARD;
    std::array<std::string, 2> namesOfPlayers;
    CellTypes playerChoice = CellTypes::Ex;
};

} // namespace Liron486
