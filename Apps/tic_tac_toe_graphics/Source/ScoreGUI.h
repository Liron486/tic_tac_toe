#pragma once

#include "NameAndScore.h"
#include "Utils.h"

class ScoreGui : public Component
{
public:
    explicit ScoreGui(Liron486::GameManager& gameManagerToUse)
        : gameManager(gameManagerToUse)
    {
        setScoreLabels(gameCounter, juce::Justification::centred, 35.f);

        addAndMakeVisible(player1);
        addAndMakeVisible(gameCounter);
        addAndMakeVisible(player2);
    }

    void resized() override
    {
        player1.setBoundsRelative(0.f, 0.f, 0.4f, 1.f);
        gameCounter.setBoundsRelative(0.4f, 0.f, 0.2f, 1.f);
        player2.setBoundsRelative(0.6f, 0.f, 0.4f, 1.f);
    }
    void paint(Graphics& g) override
    {
        auto bounds = getLocalBounds().toFloat();
        auto width = bounds.getWidth();
        auto height = bounds.getHeight();
        auto thickness = 5.f;

        g.setColour(Colours::darkblue);
        g.drawLine((width * 0.58f) / 3.f + 0.2f * width,
                   0.f,
                   (width * 0.58f) / 3.f + 0.2f * width,
                   height,
                   thickness);
        g.drawLine((width * 2 * 0.58f) / 3.f + 0.2f * width,
                   0.f,
                   (width * 2 * 0.58f) / 3.f + 0.2f * width,
                   height,
                   thickness);
        g.drawLine(0.f, height - thickness, width, height, thickness);

    }

    void setGameCounter(int gameCounterToUse)
    {
        gameCounter.setText(String(gameCounterToUse), dontSendNotification);

        resized();
    }

private:
    Liron486::GameManager& gameManager;
    NameAndScore player1 {gameManager.getGameData().conf.getPlayerName(0)};
    juce::Label gameCounter {"GameCounter", "0"};
    NameAndScore player2 {gameManager.getGameData().conf.getPlayerName(1)};
};