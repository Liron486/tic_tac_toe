#pragma once

#include <JuceHeader.h>

#include "cell.h"

class Circle : public Component
{
public:
    void paint(Graphics& g) override;
    Liron486::CellTypes getMyType() const { return myType; }

private:
    Liron486::CellTypes myType = Liron486::CellTypes::Circle;
};
