#include <iostream>
#include <sstream>

#include "real_player.h"
#include "utils.h"

namespace Liron486
{
RealPlayer::RealPlayer(const std::string& nameToUse,
                       char typeToUse,
                       const Board& boardToUse)
    : playerData {nameToUse, typeToUse, boardToUse}
    , controller(nameToUse)

{
}

inline bool isValidDigit(const std::string& str)
{
    auto it = str.begin();
    if (std::isdigit(*it))
    {
        ++it;
    }

    return (!str.empty() && it == str.end() && (str != "0"));
}

Point RealPlayer::makeMove() const
{
    std::string nextMove_str;
    Point unique(3, 3);
    auto isValid = false;
    auto nextMove = 0;
    Point newMove;

    while (isValid == false)
    {
        nextMove_str = controller.GetNextMove();
        if (compareStrings(nextMove_str, "r"))
            return unique;

        isValid = isValidDigit(nextMove_str);

        if (isValid)
        {
            std::stringstream sstream(nextMove_str);
            sstream >> nextMove;
            newMove = Point::ConvertNumToPoint(nextMove);

            if (compareChars(playerData.board.getCellContent(newMove), ' '))
                break;
        }

        std::cout << "Wrong Move, try again\n";
        isValid = false;
    }

    return newMove;
}

std::string RealPlayer::getName() const
{
    return playerData.name;
}

char RealPlayer::getPlayerType() const
{
    return playerData.type;
}

void RealPlayer::setPlayerType(char newTypeToUse)
{
    playerData.type = newTypeToUse;
}

} // namespace Liron486