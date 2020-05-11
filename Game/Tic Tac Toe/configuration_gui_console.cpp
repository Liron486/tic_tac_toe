#include <iostream>
#include <string>
#include <sstream>

#include "configurtion_gui_console.h"
#include "utils.h"

namespace Liron486
{
ConfigurationGuiConsole::ConfigurationGuiConsole(Configuration& confToUse)
    : conf(confToUse)
{
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

void ConfigurationGuiConsole::setNumRealPlayers() const
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

    conf.setNumRealPlayers(std::stoi(playerInput));
}

void ConfigurationGuiConsole::setDifficulty() const
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

    if (compareStrings(difficultyStr, "easy"))
        conf.setDifficulty(Configuration::Difficulty::EASY);
}

void ConfigurationGuiConsole::setDifficulty(
    Configuration::Difficulty difficultyToUse) const
{
    conf.setDifficulty(difficultyToUse);
}

void ConfigurationGuiConsole::setNamesOfPlayers(int playerNumberToUse) const
{
    std::string playerName;
    std::cout << "Please enter player " << playerNumberToUse + 1
              << " name: " << std::endl;
    std::cin >> playerName;

    conf.setPlayerName(playerName, playerNumberToUse);
}

void ConfigurationGuiConsole::setPlayerChoice() const
{
    std::cout << "Please Choose type (X or O)" << std::endl;

    auto typeChar = 'X';
    std::cin >> typeChar;

    while (!compareChars(typeChar, 'x') && !compareChars(typeChar, 'o')
           && !compareChars(typeChar, '0'))
    {
        std::cout << "Wrong input, try again\nChoose type (X or O)" << std::endl;

        std::cin >> typeChar;
    }

    auto type = Cell::charToCellType(typeChar);

    if (type == CellTypes::Circle)
        conf.setPlayerChoice(CellTypes::Circle);
}


} // namespace Liron486