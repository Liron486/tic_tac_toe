#pragma once

#include "game_manager.h"
#include "CellGui.h"
#include "Utils.h"

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
    void setBoardAlpha(float alphaToUse) { alpha = alphaToUse; }

private:
    std::vector<std::unique_ptr<CellGui>> cells;
    Liron486::GameManager& gameData;
    float alpha {1.f};
};
