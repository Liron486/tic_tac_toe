#include "NumOfPlayersSection.h"
#include "../Utils.h"

NumOfPlayersSection::NumOfPlayersSection(
    ButtonLNF& lnfToUse, std::function<void(int)> buttonPressedCallbackToUse)
    : lnf(lnfToUse)
    , buttonPressedCallback(buttonPressedCallbackToUse)
{
    setLabels(numOfPlayers);
    addAndMakeVisible(numOfPlayers);

    initNumOfPlayersButtons();
}

void NumOfPlayersSection::resized()
{
    numOfPlayers.setBounds(getLocalBounds());

    for (auto i = 0; i < numOfPlayersButtons.size(); ++i)
    {
        if (numOfPlayersButtons[i])
            numOfPlayersButtons[i]->setBoundsRelative(
                (3.65f + (float) i) / 9.f, 1.f / 3.f, 1.f / 9.f, 1.f / 3.f);
    }
}

void NumOfPlayersSection::initNumOfPlayersButtons()
{
    for (auto i = 0; i < 3; ++i)
    {
        numOfPlayersButtons.emplace_back(
            new juce::TextButton(juce::String(i), juce::String(i)));
        setButton(*numOfPlayersButtons[i], lnf);
        setButtonConnectedFlags(*numOfPlayersButtons[i], i, 2);
        numOfPlayersButtons[i]->onClick = [&]
        {
            auto onIndex = anyButtonPressed(
                numOfPlayersButtons,
                [&](int index) { return index != numOfPlayersPressed; },
                [&](int index) { numOfPlayersPressed = index; });

            buttonPressedCallback(onIndex);
        };

        if (i == numOfPlayersPressed)
            numOfPlayersButtons[i]->setToggleState(true, juce::dontSendNotification);

        addAndMakeVisible(*numOfPlayersButtons[i]);
    }
}
