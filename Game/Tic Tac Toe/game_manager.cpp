#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include "game_manager.h"
#include "real_player.h"
#include "computer.h"
#include "cross_platform_funcs.h"

namespace Liron486
{
const int num_of_cells = 9;
const int threshhold = 3;

void GameManager::CreateNewPlayersPtrs()
{
    int numOfRealPlayers = m_conf.GetNumRealPlayers();

    if (numOfRealPlayers == 0)
    {
        m_players[0].reset(
            new Computer(m_conf.GetPlayerName(1), 'X', m_board, m_difficulty));
        m_players[1].reset(
            new Computer(m_conf.GetPlayerName(2), 'O', m_board, m_difficulty));
    }

    else if (numOfRealPlayers == 1)
    {
        if (m_conf.GetPlayerChoice() == 'O')
        {
            m_players[0].reset(
                new Computer(m_conf.GetPlayerName(1), 'X', m_board, m_difficulty));

            m_players[1].reset(
                new RealPlayer(m_conf.GetPlayerName(2), 'O', m_board));
        }
        else
        {
            m_players[0].reset(
                new RealPlayer(m_conf.GetPlayerName(1), 'X', m_board));
            m_players[1].reset(
                new Computer(m_conf.GetPlayerName(2), 'O', m_board, m_difficulty));
        }
    }

    else if (numOfRealPlayers == 2)
    {
        m_players[0].reset(new RealPlayer(m_conf.GetPlayerName(1), 'X', m_board));
        m_players[1].reset(new RealPlayer(m_conf.GetPlayerName(2), 'O', m_board));
    }
}

GameManager::GameManager()
    : m_difficulty(m_conf.GetDifficulty())
    , m_score(m_conf.GetPlayerName(1), m_conf.GetPlayerName(2))
    , m_judge(m_board)
{
    CreateNewPlayersPtrs();
    m_gui.Tutorial(m_board.GetBoard(),
                   m_score,
                   m_difficulty,
                   m_conf.GetPlayerName(1),
                   m_conf.GetPlayerName(2));
    m_board.ResetBoard();
}

void GameManager::DisplayOnScreen() const
{
    ClearScreen();
    if (m_conf.GetNumRealPlayers() == 2)
    {
        m_gui.PrintHeaderWithoutDiff(m_score, m_gameNumber);
    }
    else
    {
        m_gui.PrintHeader(m_score, m_gameNumber, m_difficulty);
    }
    m_gui.PrintBoard(m_board.GetBoard());
}

void GameManager::ResetGame()
{
    m_board.ResetBoard();

    if (m_moveNumber > threshhold)
    {
        ++m_gameNumber;
    }
    m_moveNumber = 0;

    Play();
}

void GameManager::FillLastSquare()
{
    for (int i = 0; i < num_of_cells; ++i)
    {
        if (' ' == m_board.GetSquareContent(Point::ConvertNumToPoint(i)))
        {
            m_board.SetSquare('X', Point::ConvertNumToPoint(i));
            break;
        }
    }
}

void GameManager::Play()
{
    const int lastMove = 8;
    bool weHaveAWinner = false;
    int playerNum = 0;
    Point newMove;

    while ((m_moveNumber < num_of_cells))
    {
        playerNum = m_moveNumber % 2;
        DisplayOnScreen();

        if (m_moveNumber != lastMove)
        {
            newMove = m_players[playerNum]->MakeMove();
            if (newMove.IsPointUnique())
            {
                ResetGame();
            }
            m_board.SetSquare(m_players[playerNum]->GetPlayerType(), newMove);
        }
        else
        {
            FillLastSquare();
            MySleep(700);
        }

        if (m_moveNumber > threshhold)
        {
            if (m_judge.CheckForWinner(newMove))
            {
                weHaveAWinner = true;

                break;
            }
        }

        ++m_moveNumber;
    }

    if (weHaveAWinner)
    {
        DisplayOnScreen();
        m_gui.WeHaveAWinner(m_players[playerNum]);
        m_score.UpdateScore(playerNum);
    }
    else
    {
        DisplayOnScreen();
        m_gui.Tie();
    }

    if (WantToPlayAgain())
    {
        ResetGame();
    }
}

void GameManager::SwitchSides()
{
    m_players[0]->SetPlayerType('O');
    m_players[1]->SetPlayerType('X');

    std::swap(m_players[0], m_players[1]);

    std::string temp = m_score.GetPlayersNames()[1];
    m_score.SetPlayerName(m_score.GetPlayersNames()[0], 1);
    m_score.SetPlayerName(temp, 0);

    int tmp = m_score.GetWinsCounter()[1];
    m_score.SetWinsCounter(m_score.GetWinsCounter()[0], 1);
    m_score.SetWinsCounter(tmp, 0);

    ++m_switchSidesCounter;
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

static int CalcCumputerIndex(int switchCounter, char PlayerFirstChoise)
{
    int num = switchCounter;
    num = PlayerFirstChoise == 'X' ? num + 1 : num;

    return (num % 2);
}

void GameManager::ChangeDifficulty(Configuration::Difficulty difficulty_)
{
    if (difficulty_ != m_difficulty)
        return;

    if (m_conf.GetNumRealPlayers() == 2)
        return;

    m_difficulty = difficulty_;

    if (m_conf.GetNumRealPlayers() == 0)
    {
        const std::string name1 = m_players[0]->GetName();
        const std::string name2 = m_players[1]->GetName();

        m_players[0].reset(new Computer(name1, 'X', m_board, difficulty_));
        m_players[1].reset(new Computer(name2, 'O', m_board, difficulty_));
    }

    if (m_conf.GetNumRealPlayers() == 1)
    {
        int computer_index =
            CalcCumputerIndex(m_switchSidesCounter, m_conf.GetPlayerChoice());

        char type = computer_index == 0 ? 'X' : 'O';

        const std::string name = m_players[computer_index]->GetName();

        m_players[computer_index].reset(
            new Computer(name, type, m_board, difficulty_));
    }
}

} // namespace Liron486