#include "GamePlayGUI.h"

GamePlayGUI::GamePlayGUI(Liron486::GameManager& managerToUse)
    : Gui(managerToUse)
{
    setDifficultyComboBox();
    setButtons();
    setLabels(tieMessage, Colours::black, Justification::centred, 42.f);
    setLabels(winMessage, Colours::black, Justification::centred, 42.f);

    addAndMakeVisible(score);
    addChildComponent(difficulty);
    addAndMakeVisible(borad);
    addChildComponent(switchType);
    addAndMakeVisible(resetButton);
    addChildComponent(tieMessage);
    addChildComponent(winMessage);
    addChildComponent(yesButton);
    addChildComponent(noButton);
}

void GamePlayGUI::resized()
{
    score.setBoundsRelative(0.f, 0.f, 1.f, 0.1f);
    difficulty.setBoundsRelative(0.085f, 0.145f, 0.15f, 0.06f);
    resetButton.setBoundsRelative(0.425f, 0.145f, 0.15f, 0.06f);
    switchType.setBoundsRelative(0.765f, 0.145f, 0.15f, 0.06f);
    borad.setBoundsRelative(0.21f, 0.25f, 0.58f, 0.58f);
    tieMessage.setBoundsRelative(0.25f, 0.865f, 0.5f, 0.1f);
    winMessage.setBoundsRelative(0.25f, 0.865f, 0.5f, 0.1f);
    yesButton.setBoundsRelative(0.3f, 0.89f, 0.15f, 0.06f);
    noButton.setBoundsRelative(0.55f, 0.89f, 0.15f, 0.06f);
}

void GamePlayGUI::setDifficultyComboBox()
{
    difficulty.setJustificationType(Justification::centred);
    difficulty.addItem("EASY", 1);
    difficulty.addItem("HARD", 2);

    if (Liron486::Configuration::Difficulty::Hard
        == gameData.getGameData().conf.getDifficulty())
    {
        difficulty.setSelectedId(2);
    }
    else
        difficulty.setSelectedId(1);
}

void GamePlayGUI::setButtons()
{
    buttonLnf.setFontSize(22.f);

    switchType.setColour(TextButton::buttonColourId, Colours::navy);
    switchType.setLookAndFeel(&buttonLnf);
    resetButton.setColour(TextButton::buttonColourId, Colours::navy);
    resetButton.setLookAndFeel(&buttonLnf);

    switchType.onClick = [&] { switchTypeCallback(); };
    resetButton.onClick = [&] { resetGameCallback(); };

    yesButton.setColour(TextButton::buttonColourId, Colours::navy);
    noButton.setColour(TextButton::buttonColourId, Colour(178, 34, 34));

    yesButton.setLookAndFeel(&buttonLnf);
    noButton.setLookAndFeel(&buttonLnf);

    difficulty.setLookAndFeel(&comboLnf);
}

void GamePlayGUI::setButtonsVisibility(bool isVisible)
{
    difficulty.setVisible(isVisible);
    switchType.setVisible(isVisible);
    resetButton.setVisible(!isVisible);

    resized();
}

void GamePlayGUI::setTieMessageVisibility(bool isVisible)
{
    tieMessage.setVisible(isVisible);

    resized();
}

void GamePlayGUI::setWinMessageVisibility(bool isVisible)
{
    if (isVisible)
    {
        auto winnerIndex = gameData.getGameData().currentPlayer;
        auto winnerName =
            gameData.getGameData().players[winnerIndex]->getData().name;
        winMessage.setText(winnerName + " Wins!", dontSendNotification);
    }

    winMessage.setVisible(isVisible);

    resized();
}

void GamePlayGUI::setPlayAgainMessageVisibile(bool isVisible)
{
    yesButton.setVisible(isVisible);
    noButton.setVisible(isVisible);

    resized();
}

void GamePlayGUI::setYesNoButtonsCallbacks(std::function<void()> yesCallback,
                                           std::function<void()> noCallback)
{
    yesButton.onClick = std::move(yesCallback);
    noButton.onClick = std::move(noCallback);
}

void GamePlayGUI::updateScore()
{
    gameData.updateScore();
    auto winsArray = gameData.getGameData().score.getWinsCounter();
    score.setPlayer1Score(winsArray[0]);
    score.setPlayer2Score(winsArray[1]);
}

Liron486::Configuration::Difficulty GamePlayGUI::getDifficultyChosen()
{
    auto comboText = difficulty.getText();

    if (comboText.equalsIgnoreCase("HARD"))
        return Liron486::Configuration::Difficulty::Hard;
    else
        return Liron486::Configuration::Difficulty::Easy;
}

void GamePlayGUI::switchTypeCallback()
{
    gameData.switchSides();
    score.switchPlayers();
}

void GamePlayGUI::increseGameCounter()
{
    score.setGameCounter(gameData.getGameData().gameNumber);
}

void GamePlayGUI::resetGameCallback()
{
    gameData.getGameData().makeMoveFunc(0);
    increseGameCounter();
}
