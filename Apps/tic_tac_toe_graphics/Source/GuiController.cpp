
#include "game_manager.h"
#include "GuiController.h"
#include "CellGui.h"
#include "point.h"

void GuiController::startPlay()
{
    gameData.resetGame();

    displayOnScreen();

    while (gameData.keepPlaying())
        playNextTuren();
}

void GuiController::displayOnScreen() const
{
    board.repaint();
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
    displayOnScreen();

}

void GuiController::updateCells()
{
    for (auto i = 0; i < gameData.getGameData().board.getNumOfCells(); ++i)
    {
        auto cellContent = gameData.getGameData().board.getCellContent(Liron486::Point::convertNumToPoint(i + 1));
        board.getCells()[i]->updateCellContent(cellContent);
    }
}

void ComputerTimer::timerCallback()
{
}
