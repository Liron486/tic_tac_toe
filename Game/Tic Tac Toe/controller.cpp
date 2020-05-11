#include <iostream>

#include "controller.h"

namespace Liron486
{
Controller::Controller(const std::string& playerNameToUse)
    : playerName(playerNameToUse)
{
}

std::string Controller::getNextMove() const
{
    std::string nextMove_str;

    std::cout << playerName << " Enter your next move (1-9)" << std::endl;
    std::cin >> nextMove_str;

    return nextMove_str;
}

} // namespace Liron486