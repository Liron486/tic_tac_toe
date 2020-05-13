#pragma once

#include <JuceHeader.h>

#include "game_manager.h"
#include "BoardGui.h"

class GuiController : public Liron486::Gui
{
public:
    GuiController(Liron486::GameManager& managerToUse)
        : Gui(managerToUse)
    {
    }
    void printBoard() override {}
    void printHeader() override {}
    void printHeaderWithoutDiff() override {}
    void weHaveAWinner(int winerIndex) override {}
    void tie() override {}
    void tutorial() override {}
    Liron486::Point makeMove(int playerIndexToUse) const override
    {
        return Liron486::Point();
    }
    ActionEnum wantToPlayAgain() const override { return ActionEnum::No; }
};

class MainComponent : public Component
{
public:
    MainComponent();
    void resized() override;

private:
    Liron486::GameManager gameManager;
    GuiController controller {gameManager};
    BoardGui board;
};
