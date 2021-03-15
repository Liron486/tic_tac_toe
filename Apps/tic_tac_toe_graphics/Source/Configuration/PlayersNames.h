#pragma once

#include <JuceHeader.h>

class PlayersNames : public Component
{
public:
    explicit PlayersNames(int numOfPlayersToUse);
    void resized() override;
    String getPlayer1Name() { return player1Name.getText(); }
    String getPlayer2Name() { return player2Name.getText(); }

private:
    void initTextEditors();

    int numOfPlayers;
    juce::Label player1 {"Player1Name", "Player Name: "};
    juce::Label player2 {"Player2Name", "Second Player Name: "};
    juce::TextEditor player1Name;
    juce::TextEditor player2Name;
};