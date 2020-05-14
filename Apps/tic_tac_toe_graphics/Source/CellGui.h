#pragma once

#include <memory>
#include <JuceHeader.h>

class CellGui : public Component
{
public:
    void mouseDown(const MouseEvent& event) override;
    void resized() override;

private:
    std::unique_ptr<Component> cellContent = nullptr;
};

