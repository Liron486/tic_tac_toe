#include "DifficultySection.h"
#include "../Utils.h"

DifficultySection::DifficultySection(ButtonLNF& lnfToUse)
    : lnf(lnfToUse)
{
    setLabels(difficulty);
    addAndMakeVisible(difficulty);
    initDifficultyButtons();
}

void DifficultySection::resized()
{
    difficulty.setBounds(getLocalBounds());

    for (auto i = 0; i < difficultyButtons.size(); ++i)
    {
        if (difficultyButtons[i])
            difficultyButtons[i]->setBoundsRelative(
                (0.25f + ((float) i / 9.f)), 1.f / 3.f, 1.f / 9.f, 1.f / 3.f);
    }
}

void DifficultySection::initDifficultyButtons()
{
    juce::String buttonsText[] {"EASY", "HARD"};

    for (auto i = 0; i < 2; ++i)
    {
        difficultyButtons.emplace_back(
            new juce::TextButton(buttonsText[i], buttonsText[i]));
        setButton(*difficultyButtons[i], lnf);
        setButtonConnectedFlags(*difficultyButtons[i], i, 1);
        difficultyButtons[i]->onClick = [&]
        {
            anyButtonPressed(
                difficultyButtons,
                [&](int index) { return difficultyPressed != diffArr[index]; },
                [&](int index) { difficultyPressed = diffArr[index]; });
        };

        if (difficultyButtons[i]->getName().equalsIgnoreCase("HARD"))
            difficultyButtons[i]->setToggleState(true, dontSendNotification);

        addAndMakeVisible(*difficultyButtons[i]);
    }
}
