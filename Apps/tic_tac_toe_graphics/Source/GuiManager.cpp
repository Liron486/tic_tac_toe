
#include "GuiManager.h"

GuiManager::GuiManager()
{
    setSize(750, 750);

    addAndMakeVisible(*welcomePage);
}

void GuiManager::resized()
{
    if (welcomePage)
        welcomePage->setBounds(getLocalBounds());

    if (config)
        config->setBounds(getLocalBounds());

    if (board)
        board->setBounds(getLocalBounds());
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
        config->getPlaer2Name().toStdString(), 0);

    gameManager.createNewPlayersPtrs();

    config.reset(nullptr);
    board = std::make_unique<BoardGui>(gameManager);

    addAndMakeVisible(*board);
    resized();

    controller.startPlay();
}
