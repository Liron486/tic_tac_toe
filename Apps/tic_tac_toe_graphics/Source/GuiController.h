#pragma once

#include "gui.h"
#include "BoardGui.h"

class GuiController : public Liron486::Gui
{
public:
    GuiController(Liron486::GameManager& managerToUse, BoardGui& boardToUse)
        : Gui(managerToUse)
        , board(boardToUse)
    {
    }

    void updateCells();
    void startPlay();

private:
    void playNextMove();

    void playNextTurn();
    BoardGui& board;
    Liron486::Move nextMove;
};