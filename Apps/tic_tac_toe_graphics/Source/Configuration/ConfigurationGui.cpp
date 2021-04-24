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
    numOfPlayers.setBoundsRelative(0.03f, 1.f / 7.f, 1.f, 1.f / 7.f);

    if (numOfPlayers.getNumOfRealPlayers() != 2)
    {
        difficulty->setVisible(true);
        difficulty->setBoundsRelative(0.03f, 2.f / 7.f, 1.f, 1.f / 7.f);
        playerNames->setBoundsRelative(0.03f, 3.f / 7.f, 1.f, 1.f / 7.f);

    }
    else
    {
        playerNames->setBoundsRelative(0.03f, 2.f / 7.f, 1.f, 1.f / 7.f);
        difficulty->setVisible(false);
    }

    if (type)
        type->setBoundsRelative(0.03f, 4.f / 7.f, 1.f, 1.f / 7.f);

    playButton.setBoundsRelative(0.4f, 0.78f, 0.2f, 0.11f);
}

void ConfigurationGui::setHeader()
{
    header.setColour(header.textColourId, juce::Colours::navy);
    header.setJustificationType(juce::Justification::centred);
    auto font = header.getFont();
    font.setBold(true);
    font.setTypefaceName("Century Ghotic");

    font.setHeight(45.f);
    header.setFont(font);
}

void ConfigurationGui::numOfPlayersButtonPressed(int newNumOfPlayers)
{
    type.reset(nullptr);

    if (newNumOfPlayers == 1)
    {
        type = std::make_unique<TypeSection>(lnfButtons);
        addAndMakeVisible(*type);
    }

    addAndMakeVisible(*playerNames);
    resized();
}

void ConfigurationGui::setPlayButton()
{
    auto playFont = Font(30.f);
    playFont.setTypefaceName("Century Ghotic");
    playButtonLnf.setFontSize(30.f);
    playButton.setColour(playButton.buttonColourId, juce::Colours::navy);
    playButton.setLookAndFeel(&playButtonLnf);
}
