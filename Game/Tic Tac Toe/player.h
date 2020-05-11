#pragma once

#include <string>

#include "point.h"
#include "board.h"
#include "cell.h"

namespace Liron486
{
struct PlayerData
{
    PlayerData(const std::string& nameToUse, CellTypes typeToUse, const Board& boardToUse)
        : name(nameToUse), type(typeToUse), board(boardToUse){}
	
    std::string name;
    CellTypes type;
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
    void setPlayerType(CellTypes newTypeToUse) { data.type = newTypeToUse; }


protected:
    PlayerData data;
};

} // namespace Liron486

