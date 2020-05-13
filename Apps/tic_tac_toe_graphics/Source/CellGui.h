#pragma once

#include <memory>
#include <JuceHeader.h>

class CellGui : public Component
{
public:
    void mouseDown(const MouseEvent& event) override;
    void resized() override;

private:
    int mouseDownCounter = 0;
    std::unique_ptr<Component> cellContent = nullptr;
};

