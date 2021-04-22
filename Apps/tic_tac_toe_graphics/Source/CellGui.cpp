
#include <memory>

#include "Ex.h"
#include "Circle.h"
#include "CellGui.h"

CellGui::CellGui(Liron486::GameManager& managerToUse,
                 int cellNumber,
                 const float& alphaToUse)
    : gameData(managerToUse)
    , cellNumber(cellNumber)
    , alpha(alphaToUse)
{
}

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
            return new Ex(alpha);

        case CellTypes::Circle:
            return new Circle(alpha);
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

        if (cellContent)
            addAndMakeVisible(*cellContent);

        resized();
    }
}

