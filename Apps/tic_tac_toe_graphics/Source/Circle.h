#pragma once

#include <JuceHeader.h>

#include "cell.h"

class Circle : public Component
{
public:
    explicit Circle(float alphaToUse = 1.f)
        : alpha(alphaToUse)
    {
    }

    void paint(Graphics& g) override;
    Liron486::CellTypes getMyType() const { return myType; }

private:
    Liron486::CellTypes myType = Liron486::CellTypes::Circle;
    float alpha {1.f};
};
