
#include "Cell.h"

#include <memory>
#include "Ex.h"
#include "Circle.h"



void Cell::mouseDown(const MouseEvent& event)
{
    ++mouseDownCounter;

    if (mouseDownCounter % 3 == 1)
        cellContent = std::make_unique<Ex>();

    else if(mouseDownCounter % 3 == 2)
        cellContent = std::make_unique<Circle>();

    else
        cellContent = nullptr;

    if (cellContent != nullptr)
    {
        addAndMakeVisible(*cellContent);
//        cellContent->setInterceptsMouseClicks(false,false);
    }

    resized();
}
void Cell::resized()
{
    if (cellContent != nullptr)
        cellContent->setBounds(getLocalBounds());
}
