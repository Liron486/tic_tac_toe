#ifndef _Liron486_CONFIGURATION_HPP_
#define _Liron486_CONFIGURATION_HPP_

#include <string>
#include <array>

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
    char GetPlayerChoice() const;

private:
    void SetNumRealPlayers();
    void SetDifficulty();
    void SetPlayerChoice();
    void SetNamesOfPlayers(int playerNumberToUse);

    int nRealPlayers = 1;
    Difficulty difficulty = Difficulty::HARD;
    std::array<std::string, 2> namesOfPlayers;
    char playerChoice = 'X';
};

} // namespace Liron486

#endif // _Liron486_CONFIGURATION_HPP_#pragma once
