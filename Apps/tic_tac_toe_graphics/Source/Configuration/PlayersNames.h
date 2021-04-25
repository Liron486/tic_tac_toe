#pragma once

#include "TextEditorLNF.h"

#include <JuceHeader.h>

class PlayersNames : public Component
{
public:
    PlayersNames();
    void resized() override;
    String getPlayer1Name() { return player1Name.getText(); }
    String getPlayer2Name() { return player2Name.getText(); }

private:
    void initTextEditors();

    TextEditorLNF editorLnf;
    juce::Label player1 {"Player1Name", "X Player Name: "};
    juce::Label player2 {"Player2Name", "O Player Name: "};
    juce::TextEditor player1Name;
    juce::TextEditor player2Name;
};