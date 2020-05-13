#include "Cell.h"

void Cell::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    if (mouseDownCounter % 3 == 1)
    {
        auto offsetDiag = Point<int>(60, 60);
        auto offsetAntiDiag = Point<int>(-60, 60);

        Line<int> diag(getLocalBounds().getTopLeft() + offsetDiag,
                       getLocalBounds().getBottomRight() - offsetDiag);
        Line<int> antiDiag(getLocalBounds().getTopRight() + offsetAntiDiag,
                           getLocalBounds().getBottomLeft() - offsetAntiDiag);

        g.drawLine(diag.toFloat(), 8);
        g.drawLine(antiDiag.toFloat(), 8);
    }

    else if (mouseDownCounter % 3 == 2)
    {
        auto rect = getLocalBounds().toFloat();
        auto offset = 80;
        auto smallerRect = rect.withSizeKeepingCentre(rect.getWidth() - offset,
                                                      rect.getHeight() - offset);
        g.drawEllipse(smallerRect, 10);
    }
}



void Cell::mouseDown(const MouseEvent& event)
{
    ++mouseDownCounter;
    repaint();
}


