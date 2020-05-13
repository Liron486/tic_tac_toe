//
// Created by liron on 5/13/2020.
//
#include "Ex.h"

void Ex::paint(Graphics& g)
{
    auto offsetDiag = Point<int>(60, 60);
    auto offsetAntiDiag = Point<int>(-60, 60);

    Line<int> diag(getLocalBounds().getTopLeft() + offsetDiag,
                   getLocalBounds().getBottomRight() - offsetDiag);
    Line<int> antiDiag(getLocalBounds().getTopRight() + offsetAntiDiag,
                       getLocalBounds().getBottomLeft() - offsetAntiDiag);

    Colour red(178,34,34);
    g.setColour(red);
    g.drawLine(diag.toFloat(), 8);
    g.drawLine(antiDiag.toFloat(), 8);
}
