#pragma once

#include <memory>
#include <functional>

#include "board.h"
#include "configuration.h"
#include "player.h"
#include "score.h"

namespace Liron486
{
struct GameData
{
    void updateCell(Move move)
    {
        auto type = players[currentPlayer]->getData().type;
        board.setCell(type, move.position);
    }

    Configuration conf;
    Board board;
    Score score;
    std::unique_ptr<Player> players[2];
    int gameNumber = 1;
    int currentPlayer = 0;

    std::function<void(int)> makeMoveFunc = [](int){};
};
} // namespace Liron486
