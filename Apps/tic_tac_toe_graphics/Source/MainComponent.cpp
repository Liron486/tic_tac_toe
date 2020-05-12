#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize(600, 400);
}

void MainComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    g.setColour(Colours::red);

    for (auto& rect: rects)
    {
        g.fillRect(rect);
    }
}

void MainComponent::resized()
{
}

Rectangle<float>* MainComponent::getRectUnder(Point<float> position)
{
    for (auto& rect: rects)
    {
        if (rect.contains(position))
            return &rect;
    }

    return nullptr;
}

void MainComponent::mouseDown(const MouseEvent& event)
{
    DBG ("Down " << event.position.toString());
    draggedRect = getRectUnder(event.position);

    if (draggedRect == nullptr)
    {
        Rectangle<float> rect {20.f, 20.f};
        rect.setCentre(event.position);

        rects.push_back(rect);
        repaint();
    }
}

void MainComponent::mouseDrag(const MouseEvent& event)
{
    DBG ("Drag " << event.position.toString());

    if (draggedRect != nullptr)
    {
        draggedRect->setCentre(event.position);
        repaint();
    }
}
