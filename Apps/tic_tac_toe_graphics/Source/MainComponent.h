#pragma once

#include <memory>
#include <JuceHeader.h>

#include "game_manager.h"
#include "BoardGui.h"
#include "GameFlowController.h"
#include "ConfigurationGui.h"

class MainComponent : public Component
{
public:
    MainComponent();
    void resized() override;

private:
    std::unique_ptr<ConfigurationGui> config {new ConfigurationGui()};
    Liron486::GameManager gameManager;
    //std::unique_ptr<BoardGui> board {new BoardGui(gameManager)};
    GameFlowController controller {gameManager};
};
