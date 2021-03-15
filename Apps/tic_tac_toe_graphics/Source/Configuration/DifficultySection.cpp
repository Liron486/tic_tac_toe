#include "DifficultySection.h"
#include "../Utils.h"

DifficultySection::DifficultySection(ButtonLNF& lnfToUse)
    : lnf(lnfToUse)
{
    setQuestions(difficulty);
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
                ((5.f / 17.f) + ((float) i / 9.f)), 1.f / 3.f, 1.f / 9.f, 1.f / 3.f);
    }
}

void DifficultySection::initDifficultyButtons()
{
    for (auto i = 0; i < 2; ++i)
    {
        difficultyButtons.emplace_back(new juce::TextButton(diffArr[i], diffArr[i]));
        setButton(*difficultyButtons[i], lnf);
        setButtonConnectedFlags(*difficultyButtons[i], i, 1);
        difficultyButtons[i]->onClick = [&]
        {
            anyButtonPressed(
                difficultyButtons,
                [&](int index)
                { return !difficultyPressed.equalsIgnoreCase(diffArr[index]); },
                [&](int index) { difficultyPressed = diffArr[index]; });
        };

        if (difficultyPressed.equalsIgnoreCase(difficultyButtons[i]->getName()))
            difficultyButtons[i]->setToggleState(true, juce::dontSendNotification);

        addAndMakeVisible(*difficultyButtons[i]);
    }
}
