#include "PlayersNames.h"
#include "../Utils.h"

PlayersNames::PlayersNames()
{
    initTextEditors();
    setLabels(player1);
    setLabels(player2);

    addAndMakeVisible(player2);
    addAndMakeVisible(player2Name);

    addAndMakeVisible(player1);
    addAndMakeVisible(player1Name);
}

void PlayersNames::resized()
{
    player1.setBoundsRelative(0.f, 0.f, 0.5f, 1.f);
    player1Name.setBoundsRelative(0.2f, 0.38f, 0.2f, 0.25f);

    player2.setBoundsRelative(0.45f, 0.f, 0.5f, 1.f);
    player2Name.setBoundsRelative(0.655f, 0.38f, 0.2f, 0.25f);
}

void PlayersNames::initTextEditors()
{
    auto textEditorFont = Font(17.f);
    textEditorFont.setTypefaceName("Century Ghotic");
    textEditorFont.setBold(true);


    player1Name.setFont(textEditorFont);
    player2Name.setFont(textEditorFont);
    player1Name.setColour(TextEditor::ColourIds::backgroundColourId,
                          Colours::seashell);
    player2Name.setColour(TextEditor::ColourIds::backgroundColourId,
                          Colours::seashell);
    player1Name.setColour(TextEditor::ColourIds::textColourId, Colours::navy);
    player2Name.setColour(TextEditor::ColourIds::textColourId, Colours::navy);

    player1Name.setText("Player1");
    player2Name.setText("Player2");
    player1Name.setTextToShowWhenEmpty("Player1", juce::Colours::white);
    player2Name.setTextToShowWhenEmpty("Player2", juce::Colours::white);

    player1Name.setLookAndFeel(&editorLnf);
    player2Name.setLookAndFeel(&editorLnf);
}
