#pragma once

#include <JuceHeader.h>

#include "../ButtonLNF.h"

class DifficultySection : public Component
{
public:
    explicit DifficultySection(ButtonLNF& lnfToUse);
    void resized() override;

private:
    void initDifficultyButtons();

    ButtonLNF& lnf;
    juce::Label difficulty {"Difficulty", "Choose Difficulty: "};
    std::vector<std::unique_ptr<juce::TextButton>> difficultyButtons;
    juce::String difficultyPressed {"EASY"};
    juce::String diffArr[2] = {"EASY", "HARD"};
};