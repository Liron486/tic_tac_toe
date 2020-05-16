#pragma once

#include "gui.h"
#include "BoardGui.h"


class ComputerTimer : public Timer
{
public:
    explicit ComputerTimer(Liron486::GameManager& gameManagerToUse)
        : gameData(gameManagerToUse)
    {
    }
    void timerCallback() override;

private:
    Liron486::GameManager& gameData;
};

class GuiController : public Liron486::Gui
{
public:
    GuiController(Liron486::GameManager& managerToUse, BoardGui& boardToUse)
        :Gui(managerToUse), board(boardToUse), timer(managerToUse)
    {
    }

    void updateCells();
    void startPlay();
    void displayOnScreen() const;


private:

    void playNextTuren();
    BoardGui& board;
    ComputerTimer timer;
};