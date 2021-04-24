#pragma once

#include "BoardGui.h"
#include "ScoreGUI.h"
#include "ComboLnf.h"
#include "Utils.h"

class GamePlayGUI
    : public Liron486::Gui
    , public Component
{
public:
    explicit GamePlayGUI(Liron486::GameManager& managerToUse);
    void resized() override;

    void setButtonsVisibility(bool isVisible);
    void setTieMessageVisibility(bool isVisible);
    void setWinMessageVisibility(bool isVisible);
    void setPlayAgainMessageVisibile(bool isVisible);
    void updateScore();
    void setYesNoButtonsCallbacks(std::function<void()> yesCallback,
                                  std::function<void()> noCallback);
    Liron486::Configuration::Difficulty getDifficultyChosen();
    void increseGameCounter();

private:
    void setDifficultyComboBox();
    void setButtons();
    void switchTypeCallback();
    void resetGameCallback();

    ButtonLNF buttonLnf;
    ComboLnf comboLnf;
    ScoreGui score {gameData};
    BoardGui borad {gameData};
    juce::ComboBox difficulty;
    juce::TextButton switchType {"Switch Type"};
    juce::TextButton resetButton {"Reset"};
    juce::Label tieMessage {"Tie", "It's A Tie!"};
    juce::Label winMessage {"WinMessage", "XXX Wins!"};
    juce::TextButton yesButton {"Play Again"};
    juce::TextButton noButton {"Exit"};
};