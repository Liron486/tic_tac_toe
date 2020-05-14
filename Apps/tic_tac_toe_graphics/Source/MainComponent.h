#pragma once

#include <JuceHeader.h>

#include "game_manager.h"
#include "BoardGui.h"

class GuiController : public Liron486::Gui
{
public:
    GuiController(Liron486::GameManager& managerToUse, BoardGui& boardToUse)
        : Gui(managerToUse), board(boardToUse)
    {
    }

private:
    void printBoard() override { board.updateFrom(gameData.getGameData().board);}
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

    BoardGui& board;
};

class MainComponent : public Component
{
public:
    MainComponent();
    void resized() override;

private:
    Liron486::GameManager gameManager;
    BoardGui board;
    GuiController controller {gameManager,board};

};
