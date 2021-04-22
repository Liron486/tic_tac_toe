#pragma once

#include <JuceHeader.h>

#include "../ButtonLNF.h"
#include "../../Game/Tic Tac Toe/configuration.h"

typedef Liron486::Configuration::Difficulty Diff;

class DifficultySection : public Component
{
public:
    explicit DifficultySection(ButtonLNF& lnfToUse);
    void resized() override;
    Diff getDifficultyPressed() { return difficultyPressed; }

private:
    void initDifficultyButtons();

    ButtonLNF& lnf;
    juce::Label difficulty {"Difficulty", "Choose Difficulty: "};
    std::vector<std::unique_ptr<juce::TextButton>> difficultyButtons;
    Diff difficultyPressed {Diff::Hard};
    Diff diffArr[2] = {Diff::Easy, Diff::Hard};
};