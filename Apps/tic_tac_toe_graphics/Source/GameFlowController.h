#pragma once

#include "gui.h"
#include "game_manager.h"
#include "GamePlayGUI.h"

#include <JuceHeader.h>

class GameFlowController : public Component
{
    using LPoint = Liron486::Point;

public:
    explicit GameFlowController(Liron486::GameManager& managerToUse);
    void startPlay();
    void resized() override;

private:
    void setNextMovePosition(int cellNum);
    void playNextMove();
    void playNextTurn();
    void endOfTheGameArrangements();
    void askThePlayerToPlayAgain();
    void playAnotherGame();

    Liron486::GameManager& manager;
    GamePlayGUI gamePlay {manager};
    Liron486::Move nextMove;
};