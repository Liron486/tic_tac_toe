
#include "GameFlowController.h"

GameFlowController::GameFlowController(Liron486::GameManager& managerToUse)
    : Gui(managerToUse)
{
    gameData.getGameData().makeMoveFunc = [&](int cellNum) {
        setNextMovePosition(cellNum);
    };
}

void GameFlowController::startPlay()
{
    gameData.resetGame();

    playNextTurn();
}

void GameFlowController::playNextTurn()
{
    nextMove = gameData.askForNextMove();

    if (!nextMove.waitingForHuman)
        Timer::callAfterDelay(nextMove.timeToWaitUntilDisplay,
                              [&] { playNextMove(); });
}

void GameFlowController::playNextMove()
{
    gameData.makeMove(nextMove);

    if (gameData.keepPlaying())
        playNextTurn();
    else
        nextMove.waitingForHuman = false;
}

void GameFlowController::setNextMovePosition(int cellNum)
{
    if (nextMove.waitingForHuman)
    {
        auto position = LPoint ::convertNumToPoint(cellNum);
        nextMove.position = position;
        playNextMove();
    }
}
