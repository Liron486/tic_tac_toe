#include <iostream>
#include <string>
#include <sstream>

#include "configuration.h"
#include "cross_platform_funcs.h"

namespace Liron486
{
Configuration::Configuration()
{
    SetNumRealPlayers();
    int nPlayers = GetNumRealPlayers();

    if (nPlayers != 2)
    {
        SetDifficulty();
    }

    m_namesOfPlayers[0] = "Player1";
    m_namesOfPlayers[1] = "Player2";

    int player_number = 1;
    while (player_number <= nPlayers)
    {
        SetNamesOfPlayers(player_number - 1);
        ++player_number;
    }

    if (GetNumRealPlayers() == 1)
    {
        SetPlayerChoice();

        if (GetPlayerChoice() == 'O')
        {
            m_namesOfPlayers[1] = m_namesOfPlayers[0];
            m_namesOfPlayers[0] = "Player1";
        }
    }
}

int Configuration::GetNumRealPlayers() const
{
    return m_nRealPlayers;
}

Configuration::Difficulty Configuration::GetDifficulty() const
{
    return m_difficulty;
}

std::string Configuration::GetPlayerName(int nPlayer_) const
{
    return m_namesOfPlayers[static_cast<int>(nPlayer_ - 1)];
}

char Configuration::GetPlayerChoice() const
{
    return m_playerChoice;
}

inline bool IsValidInput(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    if (std::isdigit(*it))
    {
        ++it;
    }

    return (!str.empty() && it == str.end()
            && ((str == "0") || (str == "1") || (str == "2")));
}

void Configuration::SetNumRealPlayers()
{
    std::cout << "Welcome!\n\nPlease input number of players (0 - 2)" << std::endl;
    std::string playerInput;
    std::cin >> playerInput;

    while (IsValidInput(playerInput) == false)
    {
        std::cout << "Wrong input, try again\nInput number of players (0 - 2)"
                  << std::endl;

        std::cin >> playerInput;
    }

    std::stringstream sstream(playerInput);
    sstream >> m_nRealPlayers;
}

void Configuration::SetDifficulty()
{
    std::cout << "Please input required difficulty (EASY or HARD)" << std::endl;

    std::string difficultyStr;
    std::cin >> difficultyStr;

    while (!compareStrings(difficultyStr, "easy")
           && !compareStrings(difficultyStr, "hard"))
    {
        std::cout
            << "Wrong input, try again\nInput required difficulty (EASY or HARD)"
            << std::endl;

        std::cin >> difficultyStr;
    }

    if (compareStrings(difficultyStr, "hard"))
    {
        m_difficulty = Difficulty::HARD;
    }
    else
    {
        m_difficulty = Difficulty::EASY;
    }
}

void Configuration::SetNamesOfPlayers(int playerNumber_)
{
    std::cout << "Please enter player " << playerNumber_ + 1
              << " name: " << std::endl;
    std::cin >> m_namesOfPlayers[playerNumber_];
}

void Configuration::SetPlayerChoice()
{
    std::cout << "Please Choose type (X or O)" << std::endl;

    char type = 'X';
    std::cin >> type;

    while (!compareChars(type, 'x') && !compareChars(type, 'o')
           && !compareChars(type, '0'))
    {
        std::cout << "Wrong input, try again\nChoose type (X or O)" << std::endl;

        std::cin >> type;
    }

    if (compareChars(type, 'x'))
    {
        m_playerChoice = 'X';
    }
    else
    {
        m_playerChoice = 'O';
    }
}

} // namespace Liron486