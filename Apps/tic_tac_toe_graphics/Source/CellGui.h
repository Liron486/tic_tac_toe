#pragma once

#include <memory>
#include <JuceHeader.h>

#include "cell.h"

class CellGui : public Component
{
public:
    void mouseDown(const MouseEvent& event) override;
    void resized() override;
    void updateCellContent(Liron486::CellTypes cellType);

private:
    std::unique_ptr<Component> cellContent = nullptr;
};

