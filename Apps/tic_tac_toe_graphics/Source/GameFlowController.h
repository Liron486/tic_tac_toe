#pragma once

#include "gui.h"
#include "BoardGui.h"

class GameFlowController : public Liron486::Gui
{
    using LPoint = Liron486::Point;

public:
    explicit GameFlowController(Liron486::GameManager& managerToUse);

    void startPlay();

private:
    void setNextMovePosition(int cellNum);
    void playNextMove();
    void playNextTurn();

    Liron486::Move nextMove;
};