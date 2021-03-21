#pragma once

#include "Ex.h"
#include "Circle.h"
#include "Utils.h"

class Background : public Component
{
public:
    Background() { fillBoard(); }
    void paint(Graphics& g) override;

    void resized() override { resizedCells(ExAndCircles); }

private:
    void fillBoard();

    float alpha {0.1f};
    std::vector<std::unique_ptr<Component>> ExAndCircles;
};