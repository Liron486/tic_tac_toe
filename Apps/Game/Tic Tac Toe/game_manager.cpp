#include <iostream>
#include <string>
#include <vector>

#include "game_manager.h"
#include "real_player.h"
#include "utils.h"

namespace Liron486
{
const int num_of_cells = 9;
const int threshhold = 3;

Computer* GameManager::createComputer(int index, CellTypes type) const
{
    PlayerData data(gameData.conf.getPlayerName(index), type, gameData.board);
    return new Computer(data, gameData.conf.getDifficulty());
}

RealPlayer* GameManager::createRealPlayer(int index, CellTypes type) const
{
    PlayerData data(gameData.conf.getPlayerName(index), type, gameData.board);
    return new RealPlayer(data, gui);
}

void GameManager::createNewPlayersPtrs()
{
    auto numOfRealPlayers = gameData.conf.getNumRealPlayers();

    if (numOfRealPlayers == 0)
    {
        gameData.players[0].reset(createComputer(0, CellTypes::Ex));
        gameData.players[1].reset(createComputer(1, CellTypes::Circle));
    }

    else if (numOfRealPlayers == 1)
    {
        if (gameData.conf.getPlayerChoice() == CellTypes::Circle)
        {
            gameData.players[0].reset(createComputer(0, CellTypes::Ex));

            gameData.players[1].reset(createRealPlayer(1, CellTypes::Circle));
        }
        else
        {
            gameData.players[0].reset(createRealPlayer(0, CellTypes::Ex));
            gameData.players[1].reset(createComputer(1, CellTypes::Circle));
        }
    }

    else if (numOfRealPlayers == 2)
    {
        gameData.players[0].reset(createRealPlayer(0, CellTypes::Ex));
        gameData.players[1].reset(createRealPlayer(1, CellTypes::Circle));
    }
}

void GameManager::displayOnScreen() const
{
    ClearScreen();
    if (gameData.conf.getNumRealPlayers() == 2)
    {
        gui->printHeaderWithoutDiff();
    }
    else
    {
        gui->printHeader();
    }
    gui->printBoard();
}

void GameManager::resetGame()
{
    gameData.board.resetBoardData();

    if (moveNumber > threshhold)
    {
        ++gameData.gameNumber;
    }
    moveNumber = 0;
    weHaveAWinner = false;

    play();
}

Point GameManager::fillLastSquare() const
{
    Point newMove;

    for (auto i = 1; i <= num_of_cells; ++i)
    {
        if (gameData.board.getCellContent(Point::convertNumToPoint(i))
            == CellTypes::Empty)
        {
            newMove = Point::convertNumToPoint(i);
            gameData.board.setCell(CellTypes::Ex, newMove);
            break;
        }
    }

    return newMove;
}

void GameManager::play()
{
    constexpr auto lastMove = 8;
    auto playerNum = 0;
    Point newMove;

    if (gameData.gameNumber == 1)
    {
        createNewPlayersPtrs();
        gameData.score.setPlayerName(gameData.conf.getPlayerName(0), 0);
        gameData.score.setPlayerName(gameData.conf.getPlayerName(1), 1);
    }

    while ((moveNumber < num_of_cells))
    {
        playerNum = moveNumber % 2;
        displayOnScreen();

        if (moveNumber != lastMove)
        {
            newMove = gameData.players[playerNum]->makeMove();
            if (newMove.isPointUnique())
            {
                resetGame();
                return;
            }

            gameData.board.setCell(gameData.players[playerNum]->getData().type,
                                   newMove);
        }
        else
        {
            newMove = fillLastSquare();
            MySleep(700);
        }

        if (moveNumber > threshhold)
        {
            if (judge.checkForWinner(newMove))
            {
                weHaveAWinner = true;
                break;
            }
        }

        ++moveNumber;
    }

    if (weHaveAWinner)
    {
        displayOnScreen();
        gui->weHaveAWinner(playerNum);
        gameData.score.updateScore(playerNum);
    }
    else
    {
        displayOnScreen();
        gui->tie();
    }

    if (wantToPlayAgain())
    {
        resetGame();
    }
}

GameData& GameManager::getGameData()
{
    return gameData;
}

void GameManager::switchSides()
{
    gameData.players[0]->setPlayerType(CellTypes::Circle);
    gameData.players[1]->setPlayerType(CellTypes::Ex);

    std::swap(gameData.players[0], gameData.players[1]);

    auto temp = gameData.score.getPlayersNames()[1];
    gameData.score.setPlayerName(gameData.score.getPlayersNames()[0], 1);
    gameData.score.setPlayerName(temp, 0);

    auto tmp = gameData.score.getWinsCounter()[1];
    gameData.score.setWinsCounter(gameData.score.getWinsCounter()[0], 1);
    gameData.score.setWinsCounter(tmp, 0);

    ++switchSidesCounter;
}

bool GameManager::wantToPlayAgain()
{
    auto userAnswer = gui->wantToPlayAgain();

    switch (userAnswer)
    {
        case Gui::ActionEnum::Yes:
            return true;
        case Gui::ActionEnum::Switch:
            switchSides();
            return true;
        case Gui::ActionEnum::Easy:
            changeDifficulty(Configuration::Difficulty::Easy);
            return true;
        case Gui::ActionEnum::Hard:
            changeDifficulty(Configuration::Difficulty::Hard);
            return true;
        default:
            return false;
    }
}

static int CalcCumputerIndex(int switchCounterToUse,
                             CellTypes playerFirstChoiseToUse)
{
    auto num = switchCounterToUse;
    num = playerFirstChoiseToUse == CellTypes::Ex ? num + 1 : num;

    return (num % 2);
}

void GameManager::changeDifficulty(Configuration::Difficulty difficultyToUse)
{
    if (difficultyToUse == gameData.conf.getDifficulty())
        return;

    if (gameData.conf.getNumRealPlayers() == 2)
        return;

    gameData.conf.setDifficulty(difficultyToUse);

    if (gameData.conf.getNumRealPlayers() == 0)
    {
        auto name1 = gameData.players[0]->getData().name;
        auto name2 = gameData.players[1]->getData().name;

        gameData.players[0].reset(
            new Computer({name1, CellTypes::Ex, gameData.board}, difficultyToUse));
        gameData.players[1].reset(new Computer(
            {name2, CellTypes::Circle, gameData.board}, difficultyToUse));
    }

    if (gameData.conf.getNumRealPlayers() == 1)
    {
        auto computer_index =
            CalcCumputerIndex(switchSidesCounter, gameData.conf.getPlayerChoice());

        auto cellType = computer_index == 0 ? CellTypes::Ex : CellTypes::Circle;

        auto name = gameData.players[computer_index]->getData().name;

        gameData.players[computer_index].reset(
            new Computer({name, cellType, gameData.board}, difficultyToUse));
    }
}

} // namespace Liron486