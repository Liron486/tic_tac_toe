#pragma once

#include <JuceHeader.h>

#include "game_manager.h"
#include "BoardGui.h"
#include "GuiController.h"

class MainComponent : public Component
{
public:
    MainComponent();
    void resized() override;

private:
    Liron486::GameManager gameManager;
    BoardGui board;
    GuiController controller;

};
