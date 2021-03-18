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
    return new RealPlayer(data);
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

void GameManager::resetGame()
{
    gameIsInProgress = true;
    gameData.board.resetBoardData();
    gameData.currentPlayer = 0;

    if (moveNumber > threshhold)
    {
        ++gameData.gameNumber;
    }

    moveNumber = 0;
    weHaveAWinner = false;
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
            break;
        }
    }

    return newMove;
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

bool GameManager::wantToPlayAgain(Gui::ActionEnum userAnswer)
{
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
void GameManager::initScoreNames()
{
    gameData.score.setPlayerName(gameData.conf.getPlayerName(0), 0);
    gameData.score.setPlayerName(gameData.conf.getPlayerName(1), 1);
}

Move GameManager::askForNextMove()
{
    constexpr auto lastMove = 8;
    Move newMove;

    if (moveNumber != lastMove)
        newMove = gameData.players[gameData.currentPlayer]->makeMove();

    else
        newMove = {fillLastSquare(), false, 700};

    ++moveNumber;

    return newMove;
}

void GameManager::checkForWinner(Point lastMove)
{
    if (judge.checkForWinner(lastMove))
    {
        weHaveAWinner = true;
        gameIsInProgress = false;
    }
    else
        gameIsInProgress = moveNumber < gameData.board.getNumOfCells();

}

bool GameManager::isWeHaveAWinner() const
{
    return weHaveAWinner;
}

void GameManager::makeMove(Move move)
{
    if (move.shouldRestart())
        resetGame();
    else
    {
        gameData.updateCell(move);
        checkForWinner(move.position);
    }

    if (!weHaveAWinner)
        gameData.currentPlayer = moveNumber % 2;
}

} // namespace Liron486