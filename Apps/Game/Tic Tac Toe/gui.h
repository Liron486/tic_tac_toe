#pragma once

#include "point.h"

namespace Liron486
{
class GameManager;

class Gui
{
public:
    enum class ActionEnum
    {
        No,
        Yes,
        Switch,
        Easy,
        Hard
    };

    explicit Gui(GameManager& gameDataToUse)
        : gameData(gameDataToUse)
    {
    }

protected:

    GameManager& gameData;
};

} // namespace Liron486
