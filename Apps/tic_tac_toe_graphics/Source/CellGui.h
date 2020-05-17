#pragma once

#include <memory>
#include <JuceHeader.h>

#include "game_manager.h"
#include "cell.h"

class CellGui : public Component
{
public:
    explicit CellGui(Liron486::GameManager& managerToUse, int cellNumber)
        : gameData(managerToUse), cellNumber(cellNumber)
    {
    }
    void mouseDown(const MouseEvent& event) override;
    void resized() override;
    void updateCellContent(Liron486::CellTypes cellType);

private:
    Component* createCell();

    Liron486::CellTypes type = Liron486::CellTypes::Empty;
    std::unique_ptr<Component> cellContent = nullptr;
    Liron486::GameManager& gameData;
    int cellNumber;
};

