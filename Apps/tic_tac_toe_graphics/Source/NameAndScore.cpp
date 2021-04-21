#include "NameAndScore.h"

NameAndScore::NameAndScore(const String& playerNameToUse)
{
    playerName.setText(playerNameToUse, dontSendNotification);

    setScoreLabels(playerName);
    setScoreLabels(wins);

    addAndMakeVisible(playerName);
    addAndMakeVisible(wins);
}

void NameAndScore::resized()
{
    playerName.setBoundsRelative(0.1f, 0.1f, 0.55f, 0.8f);
    wins.setBoundsRelative(0.7, 0.1, 0.2f, 0.8f);
}

void NameAndScore::setWins(int numOfWins)
{
    wins.setText(String(numOfWins), dontSendNotification);

    resized();
}
