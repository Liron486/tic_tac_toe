
#include "game_manager.h"
#include "GuiController.h"
#include "CellGui.h"
#include "point.h"

void GuiController::startPlay()
{
    gameData.resetGame();

//    displayOnScreen();

    while (gameData.keepPlaying())
        playNextTuren();
}

void GuiController::playNextTuren()
{
    auto newMove = gameData.askForNextMove();

    if (newMove.waitingForHuman)
    {
        //timercallback
    }

    gameData.makeMove(newMove);
    updateCells();
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

void ComputerTimer::timerCallback()
{
}
