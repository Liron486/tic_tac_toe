#include "WelcomePage.h"

WelcomePage::WelcomePage(std::function<void()> startButtonCallback)
{
    startButton.onClick = startButtonCallback;
    startButton.setColour(startButton.buttonColourId, Colour(204, 229, 255));
    startButton.setColour(startButton.textColourOffId, juce::Colours::black);
    startButton.setLookAndFeel(&lnf);
    setHeader();

    addAndMakeVisible(background);
    addAndMakeVisible(header);
    addAndMakeVisible(startButton);
}

void WelcomePage::resized()
{
    background.setBounds(getLocalBounds());
    header.setBoundsRelative(0.f,0.f, 1.f, 1.f/3.f);
    startButton.setBoundsRelative(5.f/13.f, 11.f/17.f, 3.f/13.f, 1.f/17.f);
}

void WelcomePage::setHeader()
{
    header.setColour(header.textColourId, juce::Colours::orange);
    header.setJustificationType(juce::Justification::centred);
    auto font = header.getFont();
    font.setBold(true);
    font.setUnderline(true);

    font.setHeight(45.f);
    header.setFont(font);
}
