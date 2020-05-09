#include <iostream>
#include <sstream>

#include "real_player.h"
#include "utils.h"

namespace Liron486
{
RealPlayer::RealPlayer(const std::string& nameToUse,
                       char typeToUse,
                       const Board& boardToUse)
    : name(nameToUse)
    , type(typeToUse)
    , controller(nameToUse)
    , board(boardToUse)
{
}

inline bool IsValidDigit(const std::string& str)
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
	auto nextMove_str = controller.GetNextMove();

    Point unique(3, 3);

    if (compareStrings(nextMove_str, "r"))
        return unique;

    std::stringstream sstream(nextMove_str);
    auto IsValid = IsValidDigit(nextMove_str);
    Point newMove;
    auto nextMove = 0;

    if (IsValid)
    {
        sstream >> nextMove;
        newMove = Point::ConvertNumToPoint(nextMove - 1);
    }

    while ((IsValid == false) || (board.getCellContent(newMove) != ' '))
    {
        std::cout << "Wrong Move, try again\n";
        nextMove_str = controller.GetNextMove();
        if (compareStrings(nextMove_str, "r"))
            return unique;

        IsValid = IsValidDigit(nextMove_str);

        if (IsValid)
        {
            std::stringstream sstream(nextMove_str);
            sstream >> nextMove;
            newMove = Point::ConvertNumToPoint(nextMove - 1);
        }
    }

    return newMove;
}

std::string RealPlayer::getName() const
{
    return name;
}

char RealPlayer::getPlayerType() const
{
    return type;
}

void RealPlayer::setPlayerType(char newTypeToUse)
{
    type = newTypeToUse;
}

} // namespace Liron486