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
    explicit ConfigurationGui(std::function<void()> playButtonCallback);
    void resized() override;
    Diff getDifficulty() { return difficulty->getDifficultyPressed(); }
    int getNumOfRealPlayers() { return numOfPlayers.getNumOfRealPlayers(); }
    CellTypes getPlayercellType() { return type->getPlayerCellType(); }
    juce::String getPlayer1Name() { return playerNames->getPlayer1Name(); }
    juce::String getPlaer2Name() { return playerNames->getPlayer2Name(); }

private:
    void setHeader();
    void setPlayButton();

    void numOfPlayersButtonPressed(int newNumOfPlayers);

    ButtonLNF lnf;
    Background background;
    juce::Label header {"Settings", "Settings"};
    NumOfPlayersSection numOfPlayers {
        lnf, [&](int num) { numOfPlayersButtonPressed(num); }};
    std::unique_ptr<DifficultySection> difficulty {
        std::make_unique<DifficultySection>(lnf)};
    std::unique_ptr<PlayersNames> playerNames {std::make_unique<PlayersNames>(1)};
    std::unique_ptr<TypeSection> type {std::make_unique<TypeSection>(lnf)};
    juce::TextButton playButton {"PLAY!"};
};