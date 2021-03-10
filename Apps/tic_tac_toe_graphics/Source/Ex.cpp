//
// Created by liron on 5/13/2020.
//
#include "Ex.h"

void Ex::resized()
{
    auto offsetDiag = Point<int>(60, 60);
    auto offsetAntiDiag = Point<int>(-60, 60);

    diag = {getLocalBounds().getTopLeft() + offsetDiag,
            getLocalBounds().getBottomRight() - offsetDiag};

    antiDiag = {getLocalBounds().getTopRight() + offsetAntiDiag,
                getLocalBounds().getBottomLeft() - offsetAntiDiag};
}

void Ex::paint(Graphics& g)
{
    Colour red(178, 34, 34);

    g.setColour(red.withAlpha(alpha));
    g.drawLine(diag.toFloat(), 8);
    g.drawLine(antiDiag.toFloat(), 8);
}
