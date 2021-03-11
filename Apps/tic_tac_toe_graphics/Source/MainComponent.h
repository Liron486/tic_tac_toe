#pragma once

#include <memory>

#include "game_manager.h"
#include "BoardGui.h"
#include "GameFlowController.h"
#include "ConfigurationGui.h"
#include "WelcomePage.h"

class MainComponent : public Component
{
public:
    MainComponent();
    void resized() override;

private:
    void startButtonPressed()
    {
        welcomePage.reset(nullptr);
        config = std::make_unique<ConfigurationGui>();

        addAndMakeVisible(*config);
        resized();
    }

    std::unique_ptr<WelcomePage> welcomePage {new WelcomePage([&] { startButtonPressed(); })};
    std::unique_ptr<ConfigurationGui> config;
    Liron486::GameManager gameManager;
    //std::unique_ptr<BoardGui> board {new BoardGui(gameManager)};
    GameFlowController controller {gameManager};
};
