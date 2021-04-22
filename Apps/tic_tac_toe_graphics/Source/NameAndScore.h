#pragma once

#include "Utils.h"

class NameAndScore : public Component
{
public:
    explicit NameAndScore(const String& playerNameToUse);
    void resized() override;
    void setWins(int numOfWins);

private:
    juce::Label playerName {"PlayerName", ""};
    juce::Label wins {"Wins", "0"};
};