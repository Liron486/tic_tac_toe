#include "NameAndScore.h"

NameAndScore::NameAndScore(const String& playerNameToUse)
{
    playerName.setText(playerNameToUse, dontSendNotification);

    setLabels(playerName, Colours::black, Justification::centredLeft, 25.f);
    setLabels(wins, Colours::black, Justification::centredLeft, 25.f);
    setTextToBold(playerName, true);

    addAndMakeVisible(playerName);
    addAndMakeVisible(wins);
}

NameAndScore::NameAndScore(const NameAndScore& other)
{
    playerName.setText(other.playerName.getText(), dontSendNotification);
    wins.setText(other.wins.getText(), dontSendNotification);
}

void NameAndScore::resized()
{
    playerName.setBoundsRelative(0.1f, 0.1f, 0.55f, 0.8f);
    wins.setBoundsRelative(0.7f, 0.1f, 0.2f, 0.8f);
}

void NameAndScore::setWins(int numOfWins)
{
    wins.setText(String(numOfWins), dontSendNotification);

    resized();
}

NameAndScore& NameAndScore::operator=(const NameAndScore& other)
{
    playerName.setText(other.playerName.getText(), dontSendNotification);
    wins.setText(other.wins.getText(), dontSendNotification);

    return *this;
}
