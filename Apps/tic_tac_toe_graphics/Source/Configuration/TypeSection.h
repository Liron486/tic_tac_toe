#pragma once

#include <JuceHeader.h>

#include "../ButtonLNF.h"

class TypeSection : public Component
{
public:
    explicit TypeSection(ButtonLNF& lnfToUse);
    void resized() override;

private:
    void initTypeButtons();

    ButtonLNF& lnf;
    juce::Label type {"type", "Choose Type: "};
    std::vector<std::unique_ptr<juce::TextButton>> typeButtons;
    juce::String typePressed {"X"};
    juce::String diffArr[2] = {"X", "O"};
};