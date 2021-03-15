#pragma once

#include <memory>

#include "../Background.h"
#include "../Utils.h"
#include "NumOfPlayersSection.h"
#include "DifficultySection.h"
#include "PlayersNames.h"
#include "TypeSection.h"

class ConfigurationGui : public Component
{
public:
    ConfigurationGui();

    void resized() override;

private:
    void setHeader();
    void numOfPlayersButtonPressed(int newNumOfPlayers);

    ButtonLNF lnf;
    Background background;
    juce::Label header {"Settings", "Settings"};
    NumOfPlayersSection numOfPlayers {
        lnf, [&](int num) { numOfPlayersButtonPressed(num); }};
    DifficultySection difficulty {lnf};
    std::unique_ptr<PlayersNames> playerNames {new PlayersNames(1)};
    std::unique_ptr<TypeSection> type {new TypeSection {lnf}};
};