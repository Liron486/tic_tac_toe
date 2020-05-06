#ifndef _Liron486_PLAYER_HPP_
#define _Liron486_PLAYER_HPP_

#include "point.h"

namespace Liron486
{

    class Player
    {
    public:
        virtual ~Player() {}
        virtual Point MakeMove() const = 0;
        virtual const std::string GetName() const = 0;
        virtual char GetPlayerType() const = 0;
        virtual void SetPlayerType(char newType_) = 0;
    };

} // namespace Liron486

#endif // _Liron486_PLAYER_HPP_#pragma once
