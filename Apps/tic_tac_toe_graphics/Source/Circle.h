#pragma once

#include <JuceHeader.h>

#include "cell.h"

class Circle : public Component
{
public:
    explicit Circle(const float& alphaToUse)
        : alpha(alphaToUse)
    {
    }

    void paint(Graphics& g) override;
    Liron486::CellTypes getMyType() const { return myType; }

private:
    Liron486::CellTypes myType = Liron486::CellTypes::Circle;

    const float& alpha;
};
