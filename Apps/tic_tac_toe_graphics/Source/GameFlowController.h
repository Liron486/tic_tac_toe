#pragma once

#include "gui.h"
#include "BoardGui.h"

class GameFlowController : public Liron486::Gui, public Timer
{
public:
    explicit GameFlowController(Liron486::GameManager& managerToUse)
        : Gui(managerToUse)
    {
    }

    void startPlay();
    void timerCallback() override;

private:
    void playNextMove();

    void playNextTurn();
    Liron486::Move nextMove;
};