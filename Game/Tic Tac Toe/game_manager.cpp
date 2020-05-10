#include <iostream>
#include <string>
#include <vector>

#include "game_manager.h"
#include "real_player.h"
#include "computer.h"
#include "gui.h"
#include "utils.h"

namespace Liron486
{
const int num_of_cells = 9;
const int threshhold = 3;

Computer* GameManager::createComputer(int index, char type) const
{
    PlayerData data(conf.GetPlayerName(index), type, board);
    return new Computer(data, difficulty);
}

RealPlayer* GameManager::createRealPlayer(int index, char type) const
{
    PlayerData data(conf.GetPlayerName(index), type, board);
    return new RealPlayer(data);
}

void GameManager::CreateNewPlayersPtrs()
{
    auto numOfRealPlayers = conf.GetNumRealPlayers();

    if (numOfRealPlayers == 0)
    {
        players[0].reset(createComputer(1, 'X'));
        players[1].reset(createComputer(2, 'O'));
    }

    else if (numOfRealPlayers == 1)
    {
        if (conf.GetPlayerChoice() == 'O')
        {
            players[0].reset(createComputer(1, 'X'));

            players[1].reset(createRealPlayer(2, 'O'));
        }
        else
        {
            players[0].reset(createRealPlayer(1, 'X'));
            players[1].reset(createComputer(2, 'O'));
        }
    }

    else if (numOfRealPlayers == 2)
    {
        players[0].reset(createRealPlayer(1, 'X'));
        players[1].reset(createRealPlayer(2, 'O'));
    }
}

GameManager::GameManager()
    : difficulty(conf.GetDifficulty())
    , score(conf.GetPlayerName(1), conf.GetPlayerName(2))
    , judge(board)
{
    CreateNewPlayersPtrs();
    Gui::Tutorial(
        board, score, difficulty, conf.GetPlayerName(1), conf.GetPlayerName(2));
}

void GameManager::DisplayOnScreen() const
{
    ClearScreen();
    if (conf.GetNumRealPlayers() == 2)
    {
        Gui::PrintHeaderWithoutDiff(score, gameNumber);
    }
    else
    {
        Gui::PrintHeader(score, gameNumber, difficulty);
    }
    Gui::PrintBoard(board);
}

void GameManager::ResetGame()
{
    board.resetBoardData();

    if (moveNumber > threshhold)
    {
        ++gameNumber;
    }
    moveNumber = 0;

    Play();
}

Point GameManager::FillLastSquare() const
{
    Point newMove;

    for (auto i = 1; i <= num_of_cells; ++i)
    {
        if (compareChars(board.getCellContent(Point::ConvertNumToPoint(i)), ' '))
        {
            newMove = Point::ConvertNumToPoint(i);
            board.setCell('X', newMove);
            break;
        }
    }

    return newMove;
}

void GameManager::Play()
{
    constexpr auto lastMove = 8;
    auto weHaveAWinner = false;
    auto playerNum = 0;
    Point newMove;

    while ((moveNumber < num_of_cells))
    {
        playerNum = moveNumber % 2;
        DisplayOnScreen();

        if (moveNumber != lastMove)
        {
            newMove = players[playerNum]->makeMove();
            if (newMove.IsPointUnique())
            {
                ResetGame();
            }
            board.setCell(players[playerNum]->getData().type, newMove);
        }
        else
        {
            newMove = FillLastSquare();
            MySleep(700);
        }

        if (moveNumber > threshhold)
        {
            if (judge.CheckForWinner(newMove))
            {
                weHaveAWinner = true;

                break;
            }
        }

        ++moveNumber;
    }

    if (weHaveAWinner)
    {
        DisplayOnScreen();
        Gui::WeHaveAWinner(players[playerNum]->getData());
        score.UpdateScore(playerNum);
    }
    else
    {
        DisplayOnScreen();
        Gui::Tie();
    }

    if (WantToPlayAgain())
    {
        ResetGame();
    }
}

void GameManager::SwitchSides()
{
    players[0]->setPlayerType('O');
    players[1]->setPlayerType('X');

    std::swap(players[0], players[1]);

    auto temp = score.GetPlayersNames()[1];
    score.SetPlayerName(score.GetPlayersNames()[0], 1);
    score.SetPlayerName(temp, 0);

    auto tmp = score.GetWinsCounter()[1];
    score.SetWinsCounter(score.GetWinsCounter()[0], 1);
    score.SetWinsCounter(tmp, 0);

    ++switchSidesCounter;
}

bool GameManager::WantToPlayAgain()
{
    std::string answer;

    std::cout << "Do you want to play again? (y\\n)\n";

    while (true)
    {
        std::cin >> answer;

        if (compareStrings(answer, "n"))
        {
            return false;
        }

        if (compareStrings(answer, "y"))
        {
            ClearScreen();
            return true;
        }

        if (compareStrings(answer, "s"))
        {
            SwitchSides();
            return true;
        }

        if (compareStrings(answer, "easy"))
        {
            ChangeDifficulty(Configuration::Difficulty::EASY);
            return true;
        }

        if (compareStrings(answer, "HARD"))
        {
            ChangeDifficulty(Configuration::Difficulty::HARD);
            return true;
        }
    }
}

static int CalcCumputerIndex(int switchCounterToUse, char playerFirstChoiseToUse)
{
    auto num = switchCounterToUse;
    num = playerFirstChoiseToUse == 'X' ? num + 1 : num;

    return (num % 2);
}

void GameManager::ChangeDifficulty(Configuration::Difficulty difficultyToUse)
{
    if (difficultyToUse != difficulty)
        return;

    if (conf.GetNumRealPlayers() == 2)
        return;

    difficulty = difficultyToUse;

    if (conf.GetNumRealPlayers() == 0)
    {
        auto name1 = players[0]->getData().name;
        auto name2 = players[1]->getData().name;

        players[0].reset(new Computer({name1, 'X', board}, difficultyToUse));
        players[1].reset(new Computer({name2, 'O', board}, difficultyToUse));
    }

    if (conf.GetNumRealPlayers() == 1)
    {
        auto computer_index =
            CalcCumputerIndex(switchSidesCounter, conf.GetPlayerChoice());

        auto type = computer_index == 0 ? 'X' : 'O';

        auto name = players[computer_index]->getData().name;

        players[computer_index].reset(
            new Computer({name, type, board}, difficultyToUse));
    }
}

} // namespace Liron486