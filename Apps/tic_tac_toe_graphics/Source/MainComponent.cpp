#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize (600, 400);
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

	g.setColour(Colours::red);
	
	for (auto& rect: rects)
	{
        g.fillRect(rect);
	}
}

void MainComponent::resized()
{

}

void MainComponent::mouseDown(const MouseEvent& event)
{
    Rectangle<float> rect {20.f, 20.f};
    rect.setCentre(event.position);

	rects.push_back(rect);
	repaint();
}
