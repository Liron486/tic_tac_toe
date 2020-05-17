#pragma once

#include <JuceHeader.h>
#include "game_manager.h"
#include "CellGui.h"

class BoardGui
    : public Component
    , public Timer
{
public:
    explicit BoardGui(Liron486::GameManager& managerToUse);

    void paintOverChildren(Graphics& g) override;
    void resized() override;

    void timerCallback() override { updateCells(); }

    void updateCells();

private:
    std::vector<std::unique_ptr<CellGui>> cells;
    Liron486::GameManager& gameData;
};
