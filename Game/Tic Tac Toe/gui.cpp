#include <iostream>
#include <thread>
//#include <conio.h>

#include "gui.h"
#include "utils.h"
#include "point.h"

namespace Liron486
{
void Gui::PrintBoard(const Board& boardToUse)
{
    std::cout << "               +---+---+---+   \n"
              << "               | "
              << boardToUse.getCellContent(Point::ConvertNumToPoint(1)) << " | "
              << boardToUse.getCellContent(Point::ConvertNumToPoint(2)) << " | "
              << boardToUse.getCellContent(Point::ConvertNumToPoint(3)) << " |\n"
              << "               +---+---+---+   \n"
              << "               | "
              << boardToUse.getCellContent(Point::ConvertNumToPoint(4)) << " | "
              << boardToUse.getCellContent(Point::ConvertNumToPoint(5)) << " | "
              << boardToUse.getCellContent(Point::ConvertNumToPoint(6)) << " |\n"
              << "               +---+---+---+   \n"
              << "               | "
              << boardToUse.getCellContent(Point::ConvertNumToPoint(7)) << " | "
              << boardToUse.getCellContent(Point::ConvertNumToPoint(8)) << " | "
              << boardToUse.getCellContent(Point::ConvertNumToPoint(9)) << " |\n"
              << "               +---+---+---+   \n"
              << std::endl;
}

void Gui::PrintHeader(const Score& scoreToUse,
                      int gameNumberToUse,
                      Configuration::Difficulty difficultyToUse)
{
    std::string difficulty =
        difficultyToUse == Configuration::Difficulty::EASY ? "EASY" : "HARD";

    std::cout << "      " << scoreToUse.GetPlayersNames()[0] << " - "
              << scoreToUse.GetWinsCounter()[0] << "  |  " << scoreToUse.GetPlayersNames()[1]
              << " - " << scoreToUse.GetWinsCounter()[1]
              << "  ||||  Difficulty: " << difficulty
              << "  |  Game Number: " << gameNumberToUse << std::endl;

    std::cout
        << "--------------------------------------------------------------------------------"
        << std::endl;
}

void Gui::PrintHeaderWithoutDiff(const Score& scoreToUse, int gameNumberToUse)
{
    std::cout << "      " << scoreToUse.GetPlayersNames()[0] << " - "
              << scoreToUse.GetWinsCounter()[0] << "  |  " << scoreToUse.GetPlayersNames()[1]
              << " - " << scoreToUse.GetWinsCounter()[1]
              << "  ||||  Game Number: " << gameNumberToUse << std::endl;

    std::cout << "------------------------------------------------------------"
              << std::endl;
}

void Gui::WeHaveAWinner(const PlayerData& playerDataToUse)
{
    std::cout << "We have a Winner!!!!!\n"
              << playerDataToUse.name << " Wins!\n"
              << std::endl;
}

void Gui::Tie()
{
    std::cout << "It's a tie!\n" << std::endl;
}

void Gui::Tutorial(const Board& boardToUse,
                   const Score& scoreToUse,
                   Configuration::Difficulty difficultyToUse,
                   const std::string& name1ToUse,
                   const std::string& name2ToUse)
{
    //		ClearScreen();
    //		std::vector<std::string> sentences;
    //		std::string str1;
    //		int numOfRealPlayers = 0;
    //
    //		if ((name1ToUse != "Player1") && (name2ToUse != "Player2"))
    //		{
    //			str1 = "Hi " + name1ToUse + " and " + name2ToUse + ", thanks for playing my tic tac toe. I hope you will enjoy.";
    //			numOfRealPlayers = 2;
    //		}
    //		if ((name1ToUse == "Player1") && (name2ToUse != "Player2"))
    //		{
    //			str1 = "Hi " + name2ToUse + ", thanks for playing my tic tac toe. I hope you will enjoy.";
    //			numOfRealPlayers = 1;
    //		}
    //		if ((name1ToUse != "Player1") && (name2ToUse == "Player2"))
    //		{
    //			str1 = "Hi " + name1ToUse + ", thanks for playing my tic tac toe. I hope you will enjoy.";
    //			numOfRealPlayers = 1;
    //		}
    //		if ((name1ToUse == "Player1") && (name2ToUse == "Player2"))
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
    //			ClearScreen();
    //			if (2 == numOfRealPlayers)
    //			{
    //				PrintHeaderWithoutDiff(scoreToUse, 1);
    //			}
    //			else
    //			{
    //				PrintHeader(scoreToUse, 1, difficultyToUse);
    //			}
    //			PrintBoard(boardToUse);
    //
    //			int length_of_sentence = static_cast<int>(sentences[i].length());
    //			for (int j = 0; j < length_of_sentence; ++j)
    //			{
    //				std::cout << sentences[i][j] << std::flush;
    //				MySleep(70);
    //
    //				if (_kbhit())
    //				{
    //					std::cin.get();
    //					ClearScreen();
    //					return;
    //				}
    //			}
    //
    //			MySleep(1000);
    //		}
    //
    //		MySleep(700);
}

} // namespace Liron486