#pragma once

#include <string>

#include "point.h"

namespace Liron486
{
class Controller
{
public:
    explicit Controller(const std::string& playerNameToUse);
    std::string getNextMove() const;

private:
    std::string playerName;
};

} // namespace Liron486

