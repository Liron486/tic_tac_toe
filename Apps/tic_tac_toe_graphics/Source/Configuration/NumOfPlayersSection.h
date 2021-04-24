#pragma once

#include <JuceHeader.h>

#include "../ButtonLNF.h"

class NumOfPlayersSection : public Component
{
public:
    explicit NumOfPlayersSection(
        ButtonLNF& lnfToUse, std::function<void(int)> buttonPressedCallbackToUse);
    void resized() override;
    int getNumOfRealPlayers() const { return numOfPlayersPressed; }

private:
    void initNumOfPlayersButtons();

    ButtonLNF& lnf;
    std::function<void(int)> buttonPressedCallback;
    juce::Label numOfPlayers {"NumOfRealPlayers", "Choose Number of Real Players: "};
    std::vector<std::unique_ptr<juce::TextButton>> numOfPlayersButtons;
    int numOfPlayersPressed = 1;
};