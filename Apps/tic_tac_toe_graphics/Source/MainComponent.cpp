
#include "MainComponent.h"

MainComponent::MainComponent()
{
//    gameManager.getGameData().conf.setDifficulty(
//        Liron486::Configuration::Difficulty::Hard);
//    gameManager.getGameData().conf.setNumRealPlayers(1);
//    gameManager.getGameData().conf.setPlayerChoice(Liron486::CellTypes::Circle);
//    gameManager.createNewPlayersPtrs();

    setSize(750, 750);
    //controller.startPlay();

    addAndMakeVisible(*welcomePage);
}

void MainComponent::resized()
{
    if (welcomePage)
        welcomePage->setBounds(getLocalBounds());

    if (config)
        config->setBounds(getLocalBounds());

    //board->setBounds(getLocalBounds());
}
