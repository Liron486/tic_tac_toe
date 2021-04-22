#include "TypeSection.h"
#include "../Utils.h"

TypeSection::TypeSection(ButtonLNF& lnfToUse)
    : lnf(lnfToUse)
{
    setLabels(type);
    addAndMakeVisible(type);
    initTypeButtons();
}

void TypeSection::resized()
{
    type.setBounds(getLocalBounds());

    for (auto i = 0; i < typeButtons.size(); ++i)
    {
        if (typeButtons[i])
            typeButtons[i]->setBoundsRelative(
                ((5.f / 17.f) + ((float) i / 9.f)), 1.f / 3.f, 1.f / 9.f, 1.f / 3.f);
    }
}

void TypeSection::initTypeButtons()
{
    juce::String buttonsText[] {"X", "O"};

    for (auto i = 0; i < 2; ++i)
    {
        typeButtons.emplace_back(
            new juce::TextButton(buttonsText[i], buttonsText[i]));
        setButton(*typeButtons[i], lnf);
        setButtonConnectedFlags(*typeButtons[i], i, 1);
        typeButtons[i]->onClick = [&]
        {
            anyButtonPressed(
                typeButtons,
                [&](int index) { return typePressed != diffArr[index]; },
                [&](int index) { typePressed = diffArr[index]; });
        };

        if (typeButtons[i]->getName().equalsIgnoreCase("X"))
            typeButtons[i]->setToggleState(true, juce::dontSendNotification);

        addAndMakeVisible(*typeButtons[i]);
    }
}