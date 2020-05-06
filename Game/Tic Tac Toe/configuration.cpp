#include <iostream>
#include <string>
#include <sstream>

#include "configuration.h"

namespace Liron486
{

    Configuration::Configuration()
        : m_nRealPlayers(1), m_difficulty(Difficulty::HARD), m_playerChoice('X')
    {
        SetNumRealPlayers();
        int nPlayers = GetNumRealPlayers();

        if (2 != nPlayers)
        {
            SetDifficulty();
        }

        m_namesOfPlayers[0] = "Player1";
        m_namesOfPlayers[1] = "Player2";

        int counter = 0;
        while (counter < nPlayers)
        {
            SetNamesOfPlayers(counter);
            ++counter;
        }

        if (1 == GetNumRealPlayers())
        {
            SetPlayerChoice();

            if ('O' == GetPlayerChoice())
            {
                m_namesOfPlayers[1] = m_namesOfPlayers[0];
                m_namesOfPlayers[0] = "Player1";
            }
        }
    }

    int Configuration::GetNumRealPlayers() const
    {
        return (m_nRealPlayers);
    }

    Configuration::Difficulty Configuration::GetDifficulty() const
    {
        return (m_difficulty);
    }

    std::string Configuration::GetPlayerName(int nPlayer_) const
    {
        if ((nPlayer_ != 1) && (nPlayer_ != 2))
        {
            return ("");
        }

        return (m_namesOfPlayers[nPlayer_ - 1]);
    }

    char Configuration::GetPlayerChoice() const
    {
        return (m_playerChoice);
    }

    inline bool IsValidInput(const std::string& str)
    {
        std::string::const_iterator it = str.begin();
        if (std::isdigit(*it))
        {
            ++it;
        }

        return (!str.empty() && it == str.end() && ((str == "0") || (str == "1") || (str == "2")));
    }

    void Configuration::SetNumRealPlayers()
    {
        std::cout << "Welcome!\n\nPlease input number of players (0 - 2)" << std::endl;
        std::string playerInput;
        std::cin >> playerInput;

        while (IsValidInput(playerInput) == false)
        {
            std::cout << "Wrong input, try again\nInput number of players (0 - 2)" << std::endl;

            std::cin >> playerInput;
        }
         
        std::stringstream sstream(playerInput);
        sstream >> m_nRealPlayers;
    }

    void Configuration::SetDifficulty()
    {
        std::cout << "Please input required difficulty (EASY or HARD)" << std::endl;

        std::string difficultyStr;
        std::cin >> difficultyStr;

        while ((difficultyStr != "EASY") && (difficultyStr != "HARD") && (difficultyStr != "Hard") && (difficultyStr != "hard") && (difficultyStr != "easy") && (difficultyStr != "Easy"))
        {
            std::cout << "Wrong input, try again\nInput required difficulty (EASY or HARD)" << std::endl;

            std::cin >> difficultyStr;
        }

        if ((difficultyStr == "HARD") || (difficultyStr == "Hard") || (difficultyStr == "hard"))
        {
            m_difficulty = Difficulty::HARD;
        }
        else
        {
            m_difficulty = Difficulty::EASY;
        }
    }

    void Configuration::SetNamesOfPlayers(int playerNumber_)
    {
        std::cout << "Please enter player " << playerNumber_ + 1 << " name: " << std::endl;
        std::cin >> m_namesOfPlayers[playerNumber_];
    }

    void Configuration::SetPlayerChoice()
    {
        std::cout << "Please Choose type (X or O)" << std::endl;

        char type = 'X';
        std::cin >> type;

        while ((type != 'X') && (type != 'O') && (type != 'o') && (type != 'x') && (type != '0'))
        {
            std::cout << "Wrong input, try again\nChoose type (X or O)" << std::endl;

            std::cin >> type;
        }

        if ((type == 'x') || (type == 'X'))
        {
            m_playerChoice = 'X';
        }
        else
        {
            m_playerChoice = 'O';
        }
    }


} // namespace Liron486