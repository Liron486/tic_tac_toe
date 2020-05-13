
#include "MainComponent.h"

MainComponent::MainComponent()
{
    gameManager.setGui(&controller);
    addAndMakeVisible(board);

//    gameManager.play();

    setSize(750, 750);
}

void MainComponent::resized()
{
    board.setBounds(getLocalBounds());
}
