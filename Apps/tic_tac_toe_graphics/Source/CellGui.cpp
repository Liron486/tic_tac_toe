
#include <memory>

#include "Ex.h"
#include "Circle.h"
#include "CellGui.h"



void CellGui::mouseDown(const MouseEvent& event)
{
    //cellContent = std::make_unique<Ex>();

    resized();
}
void CellGui::resized()
{
    if (cellContent != nullptr)
        cellContent->setBounds(getLocalBounds());
}
void CellGui::updateCellContent(Liron486::CellTypes cellType)
{
    if (cellType == Liron486::CellTypes::Empty)
        return;

    if (cellContent == nullptr)
    {
        if (cellType == Liron486::CellTypes::Ex)
            cellContent = std::make_unique<Ex>();
        else
            cellContent = std::make_unique<Circle>();

        addAndMakeVisible(*cellContent);
        resized();
    }
}

