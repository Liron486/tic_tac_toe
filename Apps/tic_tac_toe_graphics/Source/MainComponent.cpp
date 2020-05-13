
#include "MainComponent.h"

MainComponent::MainComponent()
{
    addAndMakeVisible(board);

    setSize(750, 750);
}

void MainComponent::resized()
{
    board.setBounds(getLocalBounds());
}

void GuiGraphics::printBoard()
{

}
