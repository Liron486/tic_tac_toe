#pragma once

#include <JuceHeader.h>

class Board : public Component
{
public:
    Board();

    void paintOverChildren(Graphics& g) override;
    void resized() override;

private:
    std::vector<std::unique_ptr<Component>> cells;
};
