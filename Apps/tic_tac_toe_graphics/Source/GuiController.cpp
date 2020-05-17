
#include "game_manager.h"
#include "GuiController.h"
#include "CellGui.h"
#include "point.h"

void GuiController::startPlay()
{
    gameData.resetGame();

    playNextTurn();
}

void GuiController::playNextTurn()
{
    nextMove = gameData.askForNextMove();

    if (!nextMove.waitingForHuman)
        Timer::callAfterDelay(1000, [&] { playNextMove(); });
}

void GuiController::updateCells()
{
    for (auto i = 0; i < gameData.getGameData().board.getNumOfCells(); ++i)
    {
        auto point = Liron486::Point::convertNumToPoint(i + 1);
        auto cellContent = gameData.getGameData().board.getCellContent(point);
        board.updateCell(i, cellContent);
    }
}

void GuiController::playNextMove()
{
    gameData.makeMove(nextMove);
    updateCells();

    if (gameData.keepPlaying())
        playNextTurn();
}
