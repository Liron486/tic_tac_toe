
#include "MainComponent.h"
#include "configuration.h"

MainComponent::MainComponent()
:controller(gameManager, board)
{
    gameManager.getGameData().conf.setDifficulty(Liron486::Configuration::Difficulty::Easy);
    gameManager.getGameData().conf.setNumRealPlayers(0);
    gameManager.createNewPlayersPtrs();
    addAndMakeVisible(board);

    setSize(750, 750);
    controller.startPlay();
}

void MainComponent::resized()
{
    board.setBounds(getLocalBounds());
}
