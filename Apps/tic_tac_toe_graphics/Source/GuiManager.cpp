
#include "GuiManager.h"

GuiManager::GuiManager()
{
    setSize(windowSize, windowSize);

    addAndMakeVisible(*welcomePage);
}

void GuiManager::resized()
{
    windowSize = jmin(getWidth(), getHeight(), 750);
    auto x = (getWidth() - windowSize) / 2;
    auto y = (getHeight() - windowSize) / 2;

    if (welcomePage)
        welcomePage->setBounds(x, y, windowSize, windowSize);

    if (config)
        config->setBounds(x, y, windowSize, windowSize);

    if (controller)
        controller->setBounds(x, y, windowSize, windowSize);
}

void GuiManager::startButtonPressed()
{
    welcomePage.reset(nullptr);
    config = std::make_unique<ConfigurationGui>([&] { playButtonPressed(); });

    addAndMakeVisible(*config);
    resized();
}

void GuiManager::playButtonPressed()
{
    auto numOfPlayers = config->getNumOfRealPlayers();
    gameManager.getGameData().conf.setDifficulty(config->getDifficulty());
    gameManager.getGameData().conf.setNumRealPlayers(numOfPlayers);

    if (numOfPlayers == 1)
        gameManager.getGameData().conf.setPlayerChoice(config->getPlayercellType());

    gameManager.getGameData().conf.setPlayerName(
        config->getPlayer1Name().toStdString(), 0);
    gameManager.getGameData().conf.setPlayerName(
        config->getPlaer2Name().toStdString(), 1);

    gameManager.createNewPlayersPtrs();

    config.reset(nullptr);
    controller = std::make_unique<GameFlowController>(gameManager);

    addAndMakeVisible(*controller);
    resized();

    controller->startPlay();
}
