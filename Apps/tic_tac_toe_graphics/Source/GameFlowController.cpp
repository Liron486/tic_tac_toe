
#include "GameFlowController.h"

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
    else
    {
        gameData.getGameData().waitingForInputFromUser = true;
        startTimerHz(200);
    }
}

void GameFlowController::playNextMove()
{
    gameData.makeMove(nextMove);

    if (gameData.keepPlaying())
        playNextTurn();
}
void GameFlowController::timerCallback()
{
    if (gameData.keepPlaying() && !gameData.getGameData().waitingForInputFromUser)
    {
        stopTimer();
        playNextTurn();
    }
}
