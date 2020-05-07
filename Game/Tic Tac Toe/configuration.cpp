#include <iostream>
#include <string>
#include <sstream>

#include "configuration.h"
#include "utils.h"

namespace Liron486
{
Configuration::Configuration()
{
    SetNumRealPlayers();

    if (nRealPlayers != 2)
    {
        SetDifficulty();
    }

    namesOfPlayers[0] = "Player1";
    namesOfPlayers[1] = "Player2";

    auto player_number = 1;
    while (player_number <= nRealPlayers)
    {
        SetNamesOfPlayers(player_number - 1);
        ++player_number;
    }

    if (GetNumRealPlayers() == 1)
    {
        SetPlayerChoice();

        if (GetPlayerChoice() == 'O')
        {
            namesOfPlayers[1] = namesOfPlayers[0];
            namesOfPlayers[0] = "Player1";
        }
    }
}

int Configuration::GetNumRealPlayers() const
{
    return nRealPlayers;
}

Configuration::Difficulty Configuration::GetDifficulty() const
{
    return difficulty;
}

std::string Configuration::GetPlayerName(int nPlayerToUse) const
{
    return namesOfPlayers[static_cast<int>(nPlayerToUse - 1)];
}

char Configuration::GetPlayerChoice() const
{
    return playerChoice;
}

inline bool IsValidInput(const std::string& strToUse)
{
    auto it = strToUse.begin();
    if (std::isdigit(*it))
    {
        ++it;
    }

    return (!strToUse.empty() && it == strToUse.end()
            && ((strToUse == "0") || (strToUse == "1") || (strToUse == "2")));
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
    sstream >> nRealPlayers;
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
        difficulty = Difficulty::HARD;
    }
    else
    {
        difficulty = Difficulty::EASY;
    }
}

void Configuration::SetNamesOfPlayers(int playerNumberToUse)
{
    std::cout << "Please enter player " << playerNumberToUse + 1
              << " name: " << std::endl;
    std::cin >> namesOfPlayers[playerNumberToUse];
}

void Configuration::SetPlayerChoice()
{
    std::cout << "Please Choose type (X or O)" << std::endl;

    auto type = 'X';
    std::cin >> type;

    while (!compareChars(type, 'x') && !compareChars(type, 'o')
           && !compareChars(type, '0'))
    {
        std::cout << "Wrong input, try again\nChoose type (X or O)" << std::endl;

        std::cin >> type;
    }

    if (compareChars(type, 'x'))
    {
        playerChoice = 'X';
    }
    else
    {
        playerChoice = 'O';
    }
}

} // namespace Liron486