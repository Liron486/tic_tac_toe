
#include "MainComponent.h"
#include "configuration.h"

MainComponent::MainComponent()
{
    gameManager.getGameData().conf.setDifficulty(
        Liron486::Configuration::Difficulty::Hard);
    gameManager.getGameData().conf.setNumRealPlayers(1);
    gameManager.getGameData().conf.setPlayerChoice(Liron486::CellTypes::Circle);
    gameManager.createNewPlayersPtrs();
    addAndMakeVisible(board);

    setSize(750, 750);
    controller.startPlay();
}

void MainComponent::resized()
{
    board.setBounds(getLocalBounds());
}
