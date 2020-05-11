#include <iostream>
#include <sstream>

#include "real_player.h"
#include "utils.h"

namespace Liron486
{
RealPlayer::RealPlayer(const PlayerData& dataToUse)
    : Player(dataToUse),
    controller(data.name)

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
        nextMove_str = controller.getNextMove();
        if (compareStrings(nextMove_str, "r"))
            return unique;

        isValid = isValidDigit(nextMove_str);

        if (isValid)
        {
            std::stringstream sstream(nextMove_str);
            sstream >> nextMove;
            newMove = Point::convertNumToPoint(nextMove);

            if (data.board.getCellContent(newMove) == CellTypes::Empty)
                break;
        }

        std::cout << "Wrong Move, try again\n";
        isValid = false;
    }

    return newMove;
}


} // namespace Liron486