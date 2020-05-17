
#include "game_manager.h"
#include "GameFlowController.h"
#include "CellGui.h"
#include "point.h"

void GameFlowController::startPlay()
{
    gameData.resetGame();

    playNextTurn();
}

void GameFlowController::playNextTurn()
{
    nextMove = gameData.askForNextMove();

    if (!nextMove.waitingForHuman)
        Timer::callAfterDelay(1000, [&] { playNextMove(); });
}


void GameFlowController::playNextMove()
{
    gameData.makeMove(nextMove);

    if (gameData.keepPlaying())
        playNextTurn();
}
