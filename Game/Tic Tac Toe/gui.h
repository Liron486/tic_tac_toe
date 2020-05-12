#pragma once

namespace Liron486
{
class GameManager;

class Gui
{
public:
    explicit Gui(GameManager& gameDataToUse)
        : gameData(gameDataToUse)
    {
    }
    virtual ~Gui() = default;
    virtual void printBoard() = 0;
    virtual void printHeader() = 0;
    virtual void printHeaderWithoutDiff() = 0;
    virtual void weHaveAWinner(int winerIndex) = 0;
    virtual void tie() = 0;
    virtual void tutorial() = 0;
    virtual Point makeMove(int playerIndexToUse) const = 0;

protected:
    GameManager& gameData;
};

} // namespace Liron486
