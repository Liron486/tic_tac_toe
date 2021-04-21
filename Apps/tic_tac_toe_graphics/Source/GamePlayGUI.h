#pragma once

#include "BoardGui.h"
#include "ScoreGUI.h"

class GamePlayGUI
    : public Liron486::Gui
    , public Component
{
public:
    explicit GamePlayGUI(Liron486::GameManager& managerToUse)
        : Gui(managerToUse)
    {
        addAndMakeVisible(score);
        addAndMakeVisible(borad);
    }

    void resized() override
    {
        score.setBoundsRelative(0.f, 0.f, 1.f, 0.1f);
        borad.setBoundsRelative(0.2f, 0.25f, 0.58f, 0.58f);
    }

private:
    ScoreGui score {gameData};
    BoardGui borad {gameData};
};