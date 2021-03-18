#include "ConfigurationGui.h"

#include <utility>

ConfigurationGui::ConfigurationGui(std::function<void()> playButtonCallback)
{
    setHeader();
    setPlayButton();
    playButton.onClick = std::move(playButtonCallback);
    addAndMakeVisible(background);
    addAndMakeVisible(header);
    addAndMakeVisible(numOfPlayers);
    addAndMakeVisible(*difficulty);
    addAndMakeVisible(*playerNames);
    addAndMakeVisible(*type);
    addAndMakeVisible(playButton);
}

void ConfigurationGui::resized()
{
    background.setBounds(getLocalBounds());
    header.setBoundsRelative(0.f, 0.f, 1.f, 1.f / 6.f);
    numOfPlayers.setBoundsRelative(0.f, 1.f / 7.f, 1.f, 1.f / 7.f);

    if (numOfPlayers.getNumOfRealPlayers() != 2)
    {
        difficulty->setVisible(true);
        difficulty->setBoundsRelative(0.f, 2.f / 7.f, 1.f, 1.f / 7.f);
    }

    if (numOfPlayers.getNumOfRealPlayers() == 1)
        playerNames->setBoundsRelative(0.f, 3.f / 7.f, 1.f, 1.f / 7.f);

    else if (numOfPlayers.getNumOfRealPlayers() == 2)
    {
        playerNames->setBoundsRelative(0.f, 2.f / 7.f, 1.f, 1.f / 7.f);
        difficulty->setVisible(false);
    }

    if (type)
        type->setBoundsRelative(0.f, 4.f / 7.f, 1.f, 1.f / 7.f);

    playButton.setBoundsRelative(0.425f, 0.75f, 0.15f, 0.06f);
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

void ConfigurationGui::setPlayButton()
{
    playButton.setColour(playButton.textColourOffId, juce::Colours::white);
    playButton.setColour(playButton.buttonColourId, juce::Colours::tan);
    playButton.setLookAndFeel(&lnf);
}
