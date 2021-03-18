#pragma once

#include <JuceHeader.h>

#include "../ButtonLNF.h"
#include "../../Game/Tic Tac Toe/cell.h"

using namespace Liron486;

class TypeSection : public Component
{
public:
    explicit TypeSection(ButtonLNF& lnfToUse);
    void resized() override;
    CellTypes getPlayerCellType() { return typePressed; }

private:
    void initTypeButtons();

    ButtonLNF& lnf;
    juce::Label type {"type", "Choose Type: "};
    std::vector<std::unique_ptr<juce::TextButton>> typeButtons;
    CellTypes typePressed {CellTypes::Ex};
    CellTypes diffArr[2] = {CellTypes::Ex, CellTypes::Circle};
};