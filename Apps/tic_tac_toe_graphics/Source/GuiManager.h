#pragma once

#include <memory>

#include "game_manager.h"
#include "BoardGui.h"
#include "GameFlowController.h"
#include "Configuration/ConfigurationGui.h"
#include "WelcomePage.h"

class GuiManager : public Component
{
public:
    GuiManager();
    void resized() override;

private:
    void startButtonPressed();
    void playButtonPressed();

    Liron486::GameManager gameManager;
    std::unique_ptr<WelcomePage> welcomePage {
        std::make_unique<WelcomePage>([&] { startButtonPressed(); })};
    std::unique_ptr<ConfigurationGui> config;
    std::unique_ptr<BoardGui> board;
    GameFlowController controller {gameManager};
};
