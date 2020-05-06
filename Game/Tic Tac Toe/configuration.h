#ifndef _Liron486_CONFIGURATION_HPP_
#define _Liron486_CONFIGURATION_HPP_

#include <string>

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
    std::string GetPlayerName(int nPlayer_) const;
    char GetPlayerChoice() const;

private:
    void SetNumRealPlayers();
    void SetDifficulty();
    void SetPlayerChoice();
    void SetNamesOfPlayers(int playerNumber_);

    int m_nRealPlayers;
    Difficulty m_difficulty;
    std::string m_namesOfPlayers[2];
    char m_playerChoice;
};

} // namespace Liron486

#endif // _Liron486_CONFIGURATION_HPP_#pragma once
