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

    void GameManager::CreateNewPlayersPtrs()
    {
        int numOfRealPlayers = m_conf.GetNumRealPlayers();

        if (0 == numOfRealPlayers)
        {
            m_players[0] = new Computer(m_conf.GetPlayerName(1), 'X', m_board, m_difficulty);
            m_players[1] = new Computer(m_conf.GetPlayerName(2), 'O', m_board, m_difficulty);
        }

        else if (1 == numOfRealPlayers)
        {
            if ('O' == m_conf.GetPlayerChoice())
            {
                m_players[0] = new Computer(m_conf.GetPlayerName(1), 'X', m_board, m_difficulty);
                m_players[1] = new RealPlayer(m_conf.GetPlayerName(2), 'O', m_board);
            }
            else
            {
                m_players[0] = new RealPlayer(m_conf.GetPlayerName(1), 'X', m_board);
                m_players[1] = new Computer(m_conf.GetPlayerName(2), 'O', m_board, m_difficulty);
            }
        }

        else if (2 == numOfRealPlayers)
        {
            m_players[0] = new RealPlayer(m_conf.GetPlayerName(1), 'X', m_board);
            m_players[1] = new RealPlayer(m_conf.GetPlayerName(2), 'O', m_board);
        }
    }

    GameManager::GameManager()
        : m_moveNumber(0), m_conf(), m_difficulty(m_conf.GetDifficulty())
        , m_board(), m_score(m_conf.GetPlayerName(1), m_conf.GetPlayerName(2))
        , m_judge(m_board), m_gui(), m_gameNumber(1), m_switchSidesCounter(0)
    {
        CreateNewPlayersPtrs();
        m_gui.Tutorial(m_board.GetBoard(), m_score, m_difficulty, m_conf.GetPlayerName(1), m_conf.GetPlayerName(2));
        m_board.ResetBoard();
    }

    GameManager::~GameManager()
    {
        delete m_players[0];
        delete m_players[1];
    }

    void GameManager::DisplayOnScreen() const
    {
        liron486::ClearScreen();
        if (2 == m_conf.GetNumRealPlayers())
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
        if (m_moveNumber > 3)
        {
            ++m_gameNumber;
        }
        m_moveNumber = 0;

        Play();
    }

    void GameManager::FillLastSquare()
    {
        for (int i = 0; i < 9; ++i)
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
        bool weHaveAWinner = false;
        int playerNum = 0;
        Point newMove;

        while ((m_moveNumber < 9))
        {
            playerNum = m_moveNumber % 2;
            DisplayOnScreen();

            if (8 != m_moveNumber)
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
                liron486::MySleep(700);
            }

            if (m_moveNumber > 3)
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
            m_gui.WeHaveAWinner(m_players, playerNum);
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

            if ((answer == "n") || (answer == "N"))
            {
                return (false);
            }

            if ((answer == "y") || (answer == "Y"))
            {
                liron486::ClearScreen();
                return (true);
            }

            if ((answer == "s") || (answer == "S"))
            {
                SwitchSides();
                return (true);
            }

            if ((answer == "Easy") || (answer == "easy") || (answer == "EASY"))
            {
                if (m_difficulty != Configuration::Difficulty::EASY)
                {
                    m_difficulty = Configuration::Difficulty::EASY;
                    ChangeDifficulty(m_difficulty);
                }

                return (true);
            }

            if ((answer == "Hard") || (answer == "hard") || (answer == "HARD"))
            {
                if (m_difficulty != Configuration::Difficulty::HARD)
                {
                    m_difficulty = Configuration::Difficulty::HARD;
                    ChangeDifficulty(m_difficulty);
                }

                return (true);
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
        if (2 == m_conf.GetNumRealPlayers())
        {
            return;
        }

        if (0 == m_conf.GetNumRealPlayers())
        {
            const std::string name1 = m_players[0]->GetName();
            delete m_players[0];
            const std::string name2 = m_players[1]->GetName();
            delete m_players[1];

            m_players[0] = new Computer(name1, 'X', m_board, difficulty_);
            m_players[1] = new Computer(name2, 'O', m_board, difficulty_);
        }

        if (1 == m_conf.GetNumRealPlayers())
        {
            int computer_index = CalcCumputerIndex(m_switchSidesCounter, m_conf.GetPlayerChoice());

            char type = computer_index == 0 ? 'X' : 'O';

            const std::string name = m_players[computer_index]->GetName();
            delete m_players[computer_index];

            m_players[computer_index] = new Computer(name, type, m_board, difficulty_);
        }
    }

} // namespace Liron486