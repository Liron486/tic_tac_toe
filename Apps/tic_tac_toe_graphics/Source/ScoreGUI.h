#pragma once

#include "game_manager.h"
#include "NameAndScore.h"
#include "Ex.h"
#include "Circle.h"

class ScoreGui : public Component
{
public:
    explicit ScoreGui(Liron486::GameManager& gameManagerToUse);

    void resized() override;
    void paint(Graphics& g) override;

    void setGameCounter(int gameCounterToUse);
    void setPlayer1Score(int newScore);
    void setPlayer2Score(int newScore);
    void switchPlayers();

private:
    Liron486::GameManager& gameManager;
    Ex ex;
    Circle circle;
    NameAndScore player1 {gameManager.getGameData().conf.getPlayerName(0)};
    juce::Label gameCounter {"GameCounter", "Game Number:"};
    juce::Label counter {"Counter", "1"};
    NameAndScore player2 {gameManager.getGameData().conf.getPlayerName(1)};
};