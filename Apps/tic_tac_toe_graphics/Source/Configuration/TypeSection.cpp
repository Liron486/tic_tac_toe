#include "TypeSection.h"
#include "../Utils.h"

TypeSection::TypeSection(ButtonLNF& lnfToUse)
    : lnf(lnfToUse)
{
    setQuestions(type);
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
    for (auto i = 0; i < 2; ++i)
    {
        typeButtons.emplace_back(new juce::TextButton(diffArr[i], diffArr[i]));
        setButton(*typeButtons[i], lnf);
        setButtonConnectedFlags(*typeButtons[i], i, 1);
        typeButtons[i]->onClick = [&]
        {
          anyButtonPressed(
              typeButtons,
              [&](int index)
              { return !typePressed.equalsIgnoreCase(diffArr[index]); },
              [&](int index) { typePressed = diffArr[index]; });
        };

        if (typePressed.equalsIgnoreCase(typeButtons[i]->getName()))
            typeButtons[i]->setToggleState(true, juce::dontSendNotification);

        addAndMakeVisible(*typeButtons[i]);
    }
}