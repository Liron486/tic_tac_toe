#pragma once

#include <JuceHeader.h>

#include "gui.h"
#include "BoardGui.h"

class MainComponent : public Component
{
public:
    MainComponent();
    void mouseDown(const MouseEvent& event) override;

private:
    BoardGui board;
};

class GuiGraphics : public Liron486::Gui
{
public:
    void printBoard() override;

private:
    MainComponent mainComponent;
};