#include "Circle.h"

void Circle::paint(Graphics& g)
{
    auto rect = getLocalBounds().toFloat();
    auto offset = 100.f;
    auto smallerRect = rect.withSizeKeepingCentre(rect.getWidth() - offset,
                                                  rect.getHeight() - offset);

    Colour blue(108, 180, 238);
    g.setColour(blue.withAlpha(alpha));
    g.drawEllipse(smallerRect, 8);
}
