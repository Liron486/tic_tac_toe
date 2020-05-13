#pragma once

#include <JuceHeader.h>

class BoardGui : public Component
{
public:
    BoardGui();

    void paintOverChildren(Graphics& g) override;
    void resized() override;

private:
    std::vector<std::unique_ptr<Component>> cells;
};
