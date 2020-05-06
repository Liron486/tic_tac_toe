#include <iostream>
#include <cstdlib>
#include <thread>
//#include <conio.h>

#include "gui.h"
#include "cross_platform_funcs.h"

namespace Liron486
{
void Gui::PrintBoard(const std::vector<std::vector<char>>& board_) const
{
    std::cout << "               +---+---+---+   \n"
              << "               | " << board_[0][0] << " | " << board_[0][1]
              << " | " << board_[0][2] << " |\n"
              << "               +---+---+---+   \n"
              << "               | " << board_[1][0] << " | " << board_[1][1]
              << " | " << board_[1][2] << " |\n"
              << "               +---+---+---+   \n"
              << "               | " << board_[2][0] << " | " << board_[2][1]
              << " | " << board_[2][2] << " |\n"
              << "               +---+---+---+   \n"
              << std::endl;
}

void Gui::PrintHeader(const Score& score_,
                      int gameNUmber_,
                      Configuration::Difficulty difficulty_) const
{
    std::string difficulty =
        difficulty_ == Configuration::Difficulty::EASY ? "EASY" : "HARD";

    std::cout << "      " << score_.GetPlayersNames()[0] << " - "
              << score_.GetWinsCounter()[0] << "  |  " << score_.GetPlayersNames()[1]
              << " - " << score_.GetWinsCounter()[1]
              << "  ||||  Difficulty: " << difficulty
              << "  |  Game Number: " << gameNUmber_ << std::endl;

    std::cout
        << "--------------------------------------------------------------------------------"
        << std::endl;
}

void Gui::PrintHeaderWithoutDiff(const Score& score_, int gameNUmber_) const
{
    std::cout << "      " << score_.GetPlayersNames()[0] << " - "
              << score_.GetWinsCounter()[0] << "  |  " << score_.GetPlayersNames()[1]
              << " - " << score_.GetWinsCounter()[1]
              << "  ||||  Game Number: " << gameNUmber_ << std::endl;

    std::cout << "------------------------------------------------------------"
              << std::endl;
}

void Gui::WeHaveAWinner(std::unique_ptr<Player>& player_) const
{
    std::cout << "We have a Winner!!!!!\n"
              << player_->GetName() << " Wins!\n"
              << std::endl;
}

void Gui::Tie() const
{
    std::cout << "It's a tie!\n" << std::endl;
}

void Gui::Tutorial(const std::vector<std::vector<char>>& board_,
                   const Score& score_,
                   Configuration::Difficulty difficulty_,
                   const std::string& name1,
                   const std::string& name2) const
{
    //		liron486::ClearScreen();
    //		std::vector<std::string> sentences;
    //		std::string str1;
    //		int numOfRealPlayers = 0;
    //
    //		if ((name1 != "Player1") && (name2 != "Player2"))
    //		{
    //			str1 = "Hi " + name1 + " and " + name2 + ", thanks for playing my tic tac toe. I hope you will enjoy.";
    //			numOfRealPlayers = 2;
    //		}
    //		if ((name1 == "Player1") && (name2 != "Player2"))
    //		{
    //			str1 = "Hi " + name2 + ", thanks for playing my tic tac toe. I hope you will enjoy.";
    //			numOfRealPlayers = 1;
    //		}
    //		if ((name1 != "Player1") && (name2 == "Player2"))
    //		{
    //			str1 = "Hi " + name1 + ", thanks for playing my tic tac toe. I hope you will enjoy.";
    //			numOfRealPlayers = 1;
    //		}
    //		if ((name1 == "Player1") && (name2 == "Player2"))
    //		{
    //			str1 = "Hi, thanks for playing my tic tac toe. I hope you will 	enjoy.";
    //		}
    //		sentences.push_back(str1);
    //
    //		std::string str2 = "If you want to skip this tutorial just press any key on the keyboard.";
    //		sentences.push_back(str2);
    //
    //		std::string str3 = "As you can see in the table above each cell has a number.";
    //		sentences.push_back(str3);
    //
    //		std::string str4 = "In order to choose a cell, you have to press on the appropriate number on the\nkeyboard.";
    //		sentences.push_back(str4);
    //
    //		if (0 != numOfRealPlayers)
    //		{
    //			std::string str5 = "In order to reset a game press 'r' on the keyboard.";
    //			sentences.push_back(str5);
    //		}
    //
    //		if (0 != numOfRealPlayers)
    //		{
    //			std::string str6 = "In order to switch from 'X' to 'O' or otherwise press 's' on the keyboard\nat the end of a match.";
    //			sentences.push_back(str6);
    //		}
    //
    //		if (2 != numOfRealPlayers)
    //		{
    //			std::string str7 = "In order to switch difficulty during the game, write EASY/HARD \nat the end of a match.";
    //			sentences.push_back(str7);
    //		}
    //
    //		std::string str8 = "I am just reminding - The player who succeeds in placing three of their marks\nin a horizontal, vertical, or diagonal row is the winner.";
    //		sentences.push_back(str8);
    //
    //		std::string str9 = "Good luck!";
    //		sentences.push_back(str9);
    //
    //		int num_of_sentences = static_cast<int>(sentences.size());
    //
    //		for (int i = 0; i < num_of_sentences; ++i)
    //		{
    //			liron486::ClearScreen();
    //			if (2 == numOfRealPlayers)
    //			{
    //				PrintHeaderWithoutDiff(score_, 1);
    //			}
    //			else
    //			{
    //				PrintHeader(score_, 1, difficulty_);
    //			}
    //			PrintBoard(board_);
    //
    //			int length_of_sentence = static_cast<int>(sentences[i].length());
    //			for (int j = 0; j < length_of_sentence; ++j)
    //			{
    //				std::cout << sentences[i][j] << std::flush;
    //				liron486::MySleep(70);
    //
    //				if (_kbhit())
    //				{
    //					std::cin.get();
    //					liron486::ClearScreen();
    //					return;
    //				}
    //			}
    //
    //			liron486::MySleep(1000);
    //		}
    //
    //		liron486::MySleep(700);
}

} // namespace Liron486