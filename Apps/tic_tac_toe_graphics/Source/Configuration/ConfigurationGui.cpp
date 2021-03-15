#include "ConfigurationGui.h"

ConfigurationGui::ConfigurationGui()
{
    setHeader();
    addAndMakeVisible(background);
    addAndMakeVisible(header);
    addAndMakeVisible(numOfPlayers);
    addAndMakeVisible(difficulty);
    addAndMakeVisible(*playerNames);
    addAndMakeVisible(*type);
}

void ConfigurationGui::resized()
{
    background.setBounds(getLocalBounds());
    header.setBoundsRelative(0.f, 0.f, 1.f, 1.f / 6.f);
    numOfPlayers.setBoundsRelative(0.f, 1.f / 7.f, 1.f, 1.f / 7.f);
    difficulty.setBoundsRelative(0.f, 2.f / 7.f, 1.f, 1.f / 7.f);

    if (playerNames)
        playerNames->setBoundsRelative(0.f, 3.f / 7.f, 1.f, 1.f / 7.f);

    if (type)
        type->setBoundsRelative(0.f, 4.f / 7.f, 1.f, 1.f / 7.f);
}

void ConfigurationGui::setHeader()
{
    header.setColour(header.textColourId, juce::Colours::orange);
    header.setJustificationType(juce::Justification::centred);
    auto font = header.getFont();
    font.setBold(true);
    font.setUnderline(true);

    font.setHeight(45.f);
    header.setFont(font);
}

void ConfigurationGui::numOfPlayersButtonPressed(int newNumOfPlayers)
{
    type.reset(nullptr);
    playerNames.reset(nullptr);
    playerNames = std::make_unique<PlayersNames>(newNumOfPlayers);

    if (newNumOfPlayers == 1)
    {
        type = std::make_unique<TypeSection>(lnf);
        addAndMakeVisible(*type);
    }

    addAndMakeVisible(*playerNames);
    resized();
}
