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
    const std::vector<std::unique_ptr<CellGui>>& getCells() const { return cells; };

private:
    std::vector<std::unique_ptr<CellGui>> cells;
};
