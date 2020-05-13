
#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize(750, 750);
    addAndMakeVisible(board);

}
void MainComponent::mouseDown(const MouseEvent& event)
{
    board.resized();
}
void GuiGraphics::printBoard()
{

}
