#include <iostream>

#include "controller.h"

namespace Liron486
{
Controller::Controller(const std::string& playerName_)
    : m_playerName(playerName_)
{
}

std::string Controller::GetNextMove() const
{
    std::string nextMove_str;

    std::cout << m_playerName << " Enter your next move (1-9)" << std::endl;
    std::cin >> nextMove_str;

    return nextMove_str;
}

} // namespace Liron486