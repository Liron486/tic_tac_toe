#include <iostream>
#include <sstream>

#include "real_player.h"

namespace Liron486
{
RealPlayer::RealPlayer(const std::string name_,
                       const char type_,
                       const Board& board_)
    : m_name(name_)
    , m_type(type_)
    , m_controller(name_)
    , m_board(board_)
{
}

inline bool IsValidDigit(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    if (std::isdigit(*it))
    {
        ++it;
    }

    return (!str.empty() && it == str.end() && (str != "0"));
}

Point RealPlayer::MakeMove() const
{
    Point unique(3, 3);
    std::string nextMove_str = m_controller.GetNextMove();

    if ((nextMove_str == "r") || (nextMove_str == "R"))
    {
        return (unique);
    }

    std::stringstream sstream(nextMove_str);
    bool IsValid = IsValidDigit(nextMove_str);
    Point newMove;
    int nextMove = 0;

    if (IsValid)
    {
        sstream >> nextMove;
        newMove = Point::ConvertNumToPoint(nextMove - 1);
    }

    while ((IsValid == false) || (' ' != m_board.GetSquareContent(newMove)))
    {
        std::cout << "Wrong Move, try again\n";
        nextMove_str = m_controller.GetNextMove();
        if ((nextMove_str == "r") || (nextMove_str == "R"))
        {
            return (unique);
        }
        IsValid = IsValidDigit(nextMove_str);

        if (IsValid)
        {
            std::stringstream sstream(nextMove_str);
            sstream >> nextMove;
            newMove = Point::ConvertNumToPoint(nextMove - 1);
        }
    }

    return (newMove);
}

const std::string RealPlayer::GetName() const
{
    return (m_name);
}

char RealPlayer::GetPlayerType() const
{
    return (m_type);
}

void RealPlayer::SetPlayerType(char newType_)
{
    m_type = newType_;
}

} // namespace Liron486