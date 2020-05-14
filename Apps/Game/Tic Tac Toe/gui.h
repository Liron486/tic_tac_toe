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
    virtual ~Gui() = default;
    virtual void printBoard() const = 0;
    virtual void printHeader() const = 0;
    virtual void printHeaderWithoutDiff() const = 0;
    virtual void weHaveAWinner(int winerIndex) = 0;
    virtual void tie() = 0;
    virtual void tutorial() = 0;
    virtual Liron486::Point makeMove(int playerIndexToUse) const = 0;
    virtual ActionEnum wantToPlayAgain() const = 0;
    virtual void startPlay() = 0;
    virtual void displayOnScreen() const =0;

protected:

    GameManager& gameData;
};

} // namespace Liron486
