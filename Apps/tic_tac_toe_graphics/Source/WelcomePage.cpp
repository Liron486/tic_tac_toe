#include "WelcomePage.h"

WelcomePage::WelcomePage(std::function<void()> startButtonCallback)
{
    startButton.onClick = std::move(startButtonCallback);
    startButton.setColour(startButton.buttonColourId, Colours::navy);
    startButton.setColour(startButton.textColourOffId, juce::Colours::white);
    startButton.setLookAndFeel(&lnf);
    setHeader();

    addAndMakeVisible(background);
    addAndMakeVisible(header);
    addAndMakeVisible(startButton);
}

void WelcomePage::resized()
{
    background.setBounds(getLocalBounds());
    header.setBoundsRelative(0.f,0.f, 1.f, 0.9f);
    startButton.setBoundsRelative(0.375f, 0.52f, 0.25f, 0.06f);
}

void WelcomePage::setHeader()
{
    header.setColour(header.textColourId, juce::Colours::navy);
    header.setJustificationType(juce::Justification::centred);
    auto font = header.getFont();
    font.setBold(true);
    font.setTypefaceName("Century Gothic");

    font.setHeight(45.f);
    header.setFont(font);
}
