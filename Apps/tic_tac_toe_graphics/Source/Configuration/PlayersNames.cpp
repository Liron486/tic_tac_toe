#include "PlayersNames.h"
#include "../Utils.h"

PlayersNames::PlayersNames(int numOfPlayersToUse)
    : numOfPlayers(numOfPlayersToUse)
{
    initTextEditors();
    setLabels(player1);
    setLabels(player2);

    if (numOfPlayers != 0)
    {
        if (numOfPlayers == 2)
        {
            player1.setText("First Player Name: ", juce::dontSendNotification);
            addAndMakeVisible(player2);
            addAndMakeVisible(player2Name);
        }

        addAndMakeVisible(player1);
        addAndMakeVisible(player1Name);
    }
}

void PlayersNames::resized()
{
    player1.setBoundsRelative(0.f, 0.f, 0.5f, 1.f);

    if (numOfPlayers == 2)
        player1Name.setBoundsRelative(0.23f, 0.38f, 0.2f, 0.25f);
    else
        player1Name.setBoundsRelative(0.17f, 0.38f, 0.2f, 0.25f);

    player2.setBoundsRelative(0.45f, 0.f, 0.5f, 1.f);
    player2Name.setBoundsRelative(0.71f, 0.38f, 0.2f, 0.25f);
}

void PlayersNames::initTextEditors()
{
    player1Name.setText("Player1");
    player2Name.setText("Player2");
    player1Name.setTextToShowWhenEmpty("Player1", juce::Colours::white);
    player2Name.setTextToShowWhenEmpty("Player2", juce::Colours::white);
}
