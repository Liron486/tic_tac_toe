#ifndef _Liron486_PLAYER_HPP_
#define _Liron486_PLAYER_HPP_

#include "point.h"

namespace Liron486
{
class Player
{
public:
    virtual Point makeMove() const = 0;
    virtual std::string getName() const = 0;
    virtual char getPlayerType() const = 0;
    virtual void setPlayerType(char newTypeToUse) = 0;
};

} // namespace Liron486

#endif // _Liron486_PLAYER_HPP_#pragma once
