#pragma once

#include <JuceHeader.h>

#include "game_manager.h"
#include "BoardGui.h"

class GuiController
{
public:
    GuiController(Liron486::GameManager& managerToUse, BoardGui& boardToUse)
        :board(boardToUse)
    {
    }

private:


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
