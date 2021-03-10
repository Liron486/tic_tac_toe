#pragma once

#include <JuceHeader.h>

#include "cell.h"

class Ex : public Component
{
public:
    explicit Ex(const float& alphaToUse)
        : alpha(alphaToUse)
    {
    }

    void paint(Graphics& g) override;
    Liron486::CellTypes getMyType() const { return myType; }

    void resized() override;

private:
    Point<float> p;
    Liron486::CellTypes myType = Liron486::CellTypes::Ex;

    Line<int> diag, antiDiag;
    const float& alpha;
};
