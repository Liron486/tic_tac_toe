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

bool MainComponent::isRectExist(const Point<float>& position) const
{
    for (const auto& rect: rects)
    {
        if (rect.contains(position))
            return true;
    }

	return false;
}

void MainComponent::mouseDown(const MouseEvent& event)
{
    if (isRectExist(event.position))
        return;
	
    Rectangle<float> rect {20.f, 20.f};
    rect.setCentre(event.position);

	rects.push_back(rect);
	repaint();
}

void MainComponent::mouseDrag(const MouseEvent& event)
{

	for (auto& rect: rects)
	{
        if (rect.contains(event.position))
        {
            rect.setCentre(event.position);
            repaint();
        }
	}
}
