#include "Background.h"

void Background::paint(Graphics& g)
{
    auto bounds = getLocalBounds().toFloat();
    drawGrid(g, bounds.getWidth(), bounds.getHeight(), alpha);
}

void Background::fillBoard()
{
    ExAndCircles.emplace_back(new Circle(alpha));
    ExAndCircles.emplace_back(new Circle(alpha));
    ExAndCircles.emplace_back(new Ex(alpha));
    ExAndCircles.push_back(nullptr);
    ExAndCircles.emplace_back(new Ex(alpha));
    ExAndCircles.emplace_back(new Circle(alpha));
    ExAndCircles.emplace_back(new Ex(alpha));
    ExAndCircles.emplace_back(new Circle(alpha));
    ExAndCircles.push_back(nullptr);

    for (auto& element: ExAndCircles)
    {
        if (element)
            addAndMakeVisible(*element);
    }
}
