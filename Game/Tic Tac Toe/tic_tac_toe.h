#pragma once

#include <memory>

#include "board.h"
#include "configuration.h"
#include "player.h"
#include "score.h"

namespace Liron486
{
struct GameData
{
    Configuration conf;
    Board board;
    Score score;
    std::unique_ptr<Player> players[2];
    int gameNumber = 1;
};
} // namespace Liron486
