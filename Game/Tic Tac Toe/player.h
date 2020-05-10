#ifndef _Liron486_PLAYER_HPP_
#define _Liron486_PLAYER_HPP_

#include <string>

#include "point.h"
#include "board.h"

namespace Liron486
{
struct PlayerData
{
    PlayerData(const std::string& nameToUse, char typeToUse, const Board& boardToUse)
        : name(nameToUse), type(typeToUse), board(boardToUse){}
	
    std::string name;
    char type;
    const Board& board;
};

class Player
{
public:
    explicit Player(const PlayerData& dataToUse)
        : data(dataToUse){}
	
    virtual ~Player() = default;
    virtual Point makeMove() const = 0;

	const PlayerData& getData() const { return data; }
    virtual void setPlayerType(char newTypeToUse) { data.type = newTypeToUse; }


protected:
    PlayerData data;
};

} // namespace Liron486

#endif // _Liron486_PLAYER_HPP_#pragma once
