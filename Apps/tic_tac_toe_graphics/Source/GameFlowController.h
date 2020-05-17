#pragma once

#include "gui.h"
#include "BoardGui.h"

class GameFlowController : public Liron486::Gui
{
public:
    explicit GameFlowController(Liron486::GameManager& managerToUse)
        : Gui(managerToUse)
    {
    }

    void startPlay();
    void setNextPlayerMove(Liron486::Point pos);

private:
    void playNextMove();

    void playNextTurn();
    Liron486::Move nextMove;
};