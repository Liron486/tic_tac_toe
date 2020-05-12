#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize(600, 400);
}

void MainComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));	

	for (auto& rect: rects)
	{
        g.setColour(rect.second);
		g.fillRect(rect.first);
	}

}

void MainComponent::resized()
{
}

Rectangle<float>* MainComponent::getRectUnder(Point<float> position)
{
    for (auto& rect: rects)
    {
        if (rect.first.contains(position))
            return &rect.first;
    }

    return nullptr;
}

void MainComponent::mouseDown(const MouseEvent& event)
{
    draggedRect = getRectUnder(event.position);

    if (draggedRect == nullptr)
    {
        auto red = Random::getSystemRandom().nextInt() % 256;
        auto green = Random::getSystemRandom().nextInt() % 256;
        auto blue = Random::getSystemRandom().nextInt() % 256;

        Colour randomColor(red, green, blue);
        Rectangle<float> rect {20.f, 20.f};
        rect.setCentre(event.position);
    	
		std::pair<Rectangle<float>, Colour> newRect;
        newRect = std::make_pair(rect, randomColor);
    	
        rects.push_back(newRect);
        draggedRect = getRectUnder(event.position);
    	
        repaint();
    }
}

void MainComponent::mouseDrag(const MouseEvent& event)
{
    DBG("druging" << event.position.toString());
	
    if (draggedRect != nullptr)
    {
        draggedRect->setCentre(event.position);
        repaint();
    }
}
