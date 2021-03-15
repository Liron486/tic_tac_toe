#pragma once

#include <JuceHeader.h>

#include "../ButtonLNF.h"

class NumOfPlayersSection : public Component
{
public:
    NumOfPlayersSection(ButtonLNF& lnfToUse,
                        std::function<void(int)> buttonPressedCallbackToUse);
    void resized() override;

private:
    void initNumOfPlayersButtons();

    ButtonLNF& lnf;
    std::function<void(int)> buttonPressedCallback;
    juce::Label numOfPlayers {"NumOfRealPlayers", "Choose number of real players: "};
    std::vector<std::unique_ptr<juce::TextButton>> numOfPlayersButtons;
    int numOfPlayersPressed = 1;
};