#pragma once

#include <JuceHeader.h>
#include "board.h"
#include "CellGui.h"

class BoardGui : public Component
{
public:
    explicit BoardGui();

    void paintOverChildren(Graphics& g) override;
    void resized() override;
    void updateCell(int index, Liron486::CellTypes type)
    {
        cells[index]->updateCellContent(type);
    }

private:
    std::vector<std::unique_ptr<CellGui>> cells;
};
