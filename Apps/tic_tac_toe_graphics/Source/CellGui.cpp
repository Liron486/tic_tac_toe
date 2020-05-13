
#include "CellGui.h"

#include <memory>
#include "Ex.h"
#include "Circle.h"



void CellGui::mouseDown(const MouseEvent& event)
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
void CellGui::resized()
{
    if (cellContent != nullptr)
        cellContent->setBounds(getLocalBounds());
}
