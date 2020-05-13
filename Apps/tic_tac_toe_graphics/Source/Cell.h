#pragma once

#include <JuceHeader.h>

class Cell : public Component
{
public:

    void paint(Graphics&) override;

    void mouseDown(const MouseEvent& event) override;

private:
    int mouseDownCounter = 0;
};

