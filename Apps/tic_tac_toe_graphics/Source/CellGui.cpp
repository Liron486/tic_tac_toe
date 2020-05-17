
#include <memory>

#include "Ex.h"
#include "Circle.h"
#include "CellGui.h"

void CellGui::mouseDown(const MouseEvent& event)
{
    gameData.getGameData().makeMoveFunc(cellNumber);
}

void CellGui::resized()
{
    if (cellContent != nullptr)
        cellContent->setBounds(getLocalBounds());
}

Component* CellGui::createCell()
{
    using namespace Liron486;

    switch (type)
    {
        case CellTypes::Empty:
            return nullptr;

        case CellTypes::Ex:
            return new Ex();

        case CellTypes::Circle:
            return new Circle();
    }

    jassertfalse; //invalid type
    return nullptr;
}

void CellGui::updateCellContent(Liron486::CellTypes cellType)
{
    if (type != cellType)
    {
        type = cellType;
        cellContent.reset(createCell());

        addAndMakeVisible(*cellContent);
        resized();
    }
}
