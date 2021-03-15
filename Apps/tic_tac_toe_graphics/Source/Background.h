#pragma once

#include "Ex.h"
#include "Circle.h"
#include "Utils.h"

class Background : public Component
{
public:
    Background() { fillBoard(); }
    void paint(Graphics& g) override
    {
        auto bounds = getLocalBounds().toFloat();
        drawGrid(g, bounds.getWidth(), bounds.getHeight(), alpha);
    }

    void resized() override { resizedCells(ExAndCircles); }

private:
    void fillBoard()
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

    float alpha {0.1f};
    std::vector<std::unique_ptr<Component>> ExAndCircles;
};