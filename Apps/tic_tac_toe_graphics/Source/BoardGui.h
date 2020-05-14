#pragma once

#include <JuceHeader.h>
#include "board.h"

class BoardGui : public Component
{
public:
    BoardGui();

    void updateFrom(Liron486::Board& board)
    {
//        board.getCellContent()
    }
    void paintOverChildren(Graphics& g) override;
    void resized() override;

private:
    std::vector<std::unique_ptr<Component>> cells;
};
