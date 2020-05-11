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

    int getNumRealPlayers() const;
    Difficulty getDifficulty() const;
    std::string getPlayerName(int nPlayerToUse) const;
    CellTypes getPlayerChoice() const;
    void setDifficulty(Difficulty difficultyToUse);
    void setNumRealPlayers(int nRealPlayersToUse);
    void setPlayerChoice(CellTypes playerChosenTypeToUse);
    void setPlayerName(const std::string& playerNameToUse, int playerIndexToUse);

private:
    int nRealPlayers = 1;
    Difficulty difficulty = Difficulty::HARD;
    std::array<std::string, 2> namesOfPlayers;
    CellTypes playerChoice = CellTypes::Ex;
};

} // namespace Liron486
