
#include "GameFlowController.h"

GameFlowController::GameFlowController(Liron486::GameManager& managerToUse)
    : manager(managerToUse)
{
    manager.getGameData().makeMoveFunc = [&](int cellNum)
    { setNextMovePosition(cellNum); };

    gamePlay.setYesNoButtonsCallbacks([&] { playAnotherGame(); }, [&] {});

    addAndMakeVisible(gamePlay);
}

void GameFlowController::startPlay()
{
    manager.resetGame();

    playNextTurn();
}

void GameFlowController::playNextTurn()
{
    nextMove = manager.askForNextMove();

    if (!nextMove.waitingForHuman)
        Timer::callAfterDelay(nextMove.timeToWaitUntilDisplay,
                              [&] { playNextMove(); });
}

void GameFlowController::playNextMove()
{
    manager.makeMove(nextMove);

    if (manager.keepPlaying())
        playNextTurn();
    else
        endOfTheGameArrangements();
}

void GameFlowController::setNextMovePosition(int cellNum)
{
    if (nextMove.waitingForHuman)
    {
        auto position = LPoint::convertNumToPoint(cellNum);
        nextMove.position = position;
        playNextMove();
    }
}

void GameFlowController::resized()
{
    gamePlay.setBounds(getLocalBounds());
}

void GameFlowController::endOfTheGameArrangements()
{
    if (manager.isWeHaveAWinner())
        gamePlay.setWinMessageVisibility(true);
    else
        gamePlay.setTieMessageVisibility(true);

    gamePlay.updateScore();
    Timer::callAfterDelay(1500, [&] { askThePlayerToPlayAgain(); });

    nextMove.waitingForHuman = false;
}

void GameFlowController::askThePlayerToPlayAgain()
{
    gamePlay.setWinMessageVisibility(false);
    gamePlay.setTieMessageVisibility(false);
    gamePlay.setPlayAgainMessageVisibile(true);
    gamePlay.setButtonsVisibility(true);
}

void GameFlowController::playAnotherGame()
{
    gamePlay.setButtonsVisibility(false);
    gamePlay.setPlayAgainMessageVisibile(false);
    manager.changeDifficulty(gamePlay.getDifficultyChosen());
    startPlay();
}
