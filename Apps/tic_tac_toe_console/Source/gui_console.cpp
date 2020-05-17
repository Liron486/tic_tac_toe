#include <iostream>
#include <string>

#include "game_manager.h"
#include "gui_console.h"
#include "utils.h"
#include "point.h"

namespace Liron486
{
GuiConsole::GuiConsole(GameManager& gameDataToUse)
    : Gui(gameDataToUse)
{
    confGuiConsole.setNumRealPlayers();

    if (confGuiConsole.getNumRealPlayers() != 2)
    {
        confGuiConsole.setDifficulty();
    }

    confGuiConsole.setPlayerName("Player1", 0);
    confGuiConsole.setPlayerName("Player2", 1);

    auto player_number = 1;
    while (player_number <= confGuiConsole.getNumRealPlayers())
    {
        confGuiConsole.setNamesOfPlayers(player_number - 1);
        ++player_number;
    }

    if (confGuiConsole.getNumRealPlayers() == 1)
    {
        confGuiConsole.setPlayerChoice();

        if (confGuiConsole.getPlayerChoice() == CellTypes::Circle)
        {
            confGuiConsole.setPlayerName(confGuiConsole.getPlayerName(0), 1);
            confGuiConsole.setPlayerName("Player1", 0);
        }
    }

    gameData.createNewPlayersPtrs();
    gameData.initScoreNames();
}

void GuiConsole::printBoard() const
{
    auto& data = gameData.getGameData();

    std::cout << "               +---+---+---+   \n"
              << "               | "
              << Cell::cellTypeToChar(
                     data.board.getCellContent(Point::convertNumToPoint(1)))
              << " | "
              << Cell::cellTypeToChar(
                     data.board.getCellContent(Point::convertNumToPoint(2)))
              << " | "
              << Cell::cellTypeToChar(
                     data.board.getCellContent(Point::convertNumToPoint(3)))
              << " |\n"
              << "               +---+---+---+   \n"
              << "               | "
              << Cell::cellTypeToChar(
                     data.board.getCellContent(Point::convertNumToPoint(4)))
              << " | "
              << Cell::cellTypeToChar(
                     data.board.getCellContent(Point::convertNumToPoint(5)))
              << " | "
              << Cell::cellTypeToChar(
                     data.board.getCellContent(Point::convertNumToPoint(6)))
              << " |\n"
              << "               +---+---+---+   \n"
              << "               | "
              << Cell::cellTypeToChar(
                     data.board.getCellContent(Point::convertNumToPoint(7)))
              << " | "
              << Cell::cellTypeToChar(
                     data.board.getCellContent(Point::convertNumToPoint(8)))
              << " | "
              << Cell::cellTypeToChar(
                     data.board.getCellContent(Point::convertNumToPoint(9)))
              << " |\n"
              << "               +---+---+---+   \n"
              << std::endl;
}

void GuiConsole::printHeader() const
{
    auto& data = gameData.getGameData();

    std::string difficulty =
        data.conf.getDifficulty() == Configuration::Difficulty::Easy ? "Easy"
                                                                     : "HARD";

    std::cout << "       " << data.score.getPlayersNames()[0] << " - "
              << data.score.getWinsCounter()[0] << "  |  "
              << data.score.getPlayersNames()[1] << " - "
              << data.score.getWinsCounter()[1]
              << "  ||||  Difficulty: " << difficulty
              << "  |  Game Number: " << data.gameNumber << std::endl;

    std::cout
        << "--------------------------------------------------------------------------------"
        << std::endl;
}

void GuiConsole::printHeaderWithoutDiff() const
{
    auto& data = gameData.getGameData();

    std::cout << "      " << data.score.getPlayersNames()[0] << " - "
              << data.score.getWinsCounter()[0] << "  |  "
              << data.score.getPlayersNames()[1] << " - "
              << data.score.getWinsCounter()[1]
              << "  ||||  Game Number: " << data.gameNumber << std::endl;

    std::cout << "------------------------------------------------------------"
              << std::endl;
}

void GuiConsole::weHaveAWinner()
{
    std::cout << "We have a Winner!!!!!\n"
              << gameData.getGameData().players[getCurrentPlayer()]->getData().name
              << " Wins!\n"
              << std::endl;
}

void GuiConsole::tie()
{
    std::cout << "It's a tie!\n" << std::endl;
}

void GuiConsole::tutorial()
{
    ClearScreen();
    std::vector<std::string> sentences;
    std::string str1;
    auto numOfRealPlayers = 0;

    auto& data = gameData.getGameData();

    if ((data.players[0]->getData().name != "Player1")
        && (data.players[1]->getData().name != "Player2"))
    {
        str1 = "Hi " + data.players[0]->getData().name + " and "
               + data.players[1]->getData().name
               + ", thanks for playing my tic tac toe. I hope you will enjoy.";
        numOfRealPlayers = 2;
    }
    if ((data.players[0]->getData().name == "Player1")
        && (data.players[1]->getData().name != "Player2"))
    {
        str1 = "Hi " + data.players[1]->getData().name
               + ", thanks for playing my tic tac toe. I hope you will enjoy.";
        numOfRealPlayers = 1;
    }
    if ((data.players[0]->getData().name != "Player1")
        && (data.players[1]->getData().name == "Player2"))
    {
        str1 = "Hi " + data.players[0]->getData().name
               + ", thanks for playing my tic tac toe. I hope you will enjoy.";
        numOfRealPlayers = 1;
    }
    if ((data.players[0]->getData().name == "Player1")
        && (data.players[1]->getData().name == "Player2"))
    {
        str1 = "Hi, thanks for playing my tic tac toe. I hope you will 	enjoy.";
    }
    sentences.push_back(str1);

    std::string str2 =
        "If you want to skip this tutorial just press any key on the keyboard.";
    sentences.push_back(str2);

    std::string str3 = "As you can see in the table above each cell has a number.";
    sentences.push_back(str3);

    std::string str4 =
        "In order to choose a cell, you have to press on the appropriate number on the\nkeyboard.";
    sentences.push_back(str4);

    if (numOfRealPlayers != 0)
    {
        std::string str5 = "In order to reset a game press 'r' on the keyboard.";
        sentences.push_back(str5);
    }

    if (numOfRealPlayers != 0)
    {
        std::string str6 =
            "In order to switch from 'X' to 'O' or otherwise press 's' on the keyboard\nat the end of a match.";
        sentences.push_back(str6);
    }

    if (numOfRealPlayers != 2)
    {
        std::string str7 =
            "In order to switch difficulty during the game, write Easy/HARD \nat the end of a match.";
        sentences.push_back(str7);
    }

    std::string str8 =
        "I am just reminding - The player who succeeds in placing three of their marks\nin a horizontal, vertical, or diagonal row is the winner.";
    sentences.push_back(str8);

    std::string str9 = "Good luck!";
    sentences.push_back(str9);

    auto num_of_sentences = static_cast<int>(sentences.size());

    for (auto i = 0; i < num_of_sentences; ++i)
    {
        ClearScreen();
        if (numOfRealPlayers == 2)
        {
            printHeaderWithoutDiff();
        }
        else
        {
            printHeader();
        }
        printBoard();

        auto length_of_sentence = static_cast<int>(sentences[i].length());
        for (auto j = 0; j < length_of_sentence; ++j)
        {
            std::cout << sentences[i][j] << std::flush;
            mySleep(70);

            std::cin.get();
            ClearScreen();
            return;
        }

        mySleep(1000);
    }

    mySleep(700);
}

bool isValidDigit(const std::string& str)
{
    auto it = str.begin();
    if (std::isdigit(*it))
    {
        ++it;
    }

    return (!str.empty() && it == str.end() && (str != "0"));
}

Point GuiConsole::askPlayerForMove() const
{
    std::string nextMove_str;
    Point unique(3, 3);
    auto isValid = false;
    auto nextMove = 0;
    Point newMove;

    while (isValid == false)
    {
        nextMove_str = getUserRequiredCell(getCurrentPlayer());
        if (compareStrings(nextMove_str, "r"))
            return unique;

        isValid = isValidDigit(nextMove_str);

        if (isValid)
        {
            nextMove = std::stoi(nextMove_str);
            newMove = Point::convertNumToPoint(nextMove);

            if (gameData.getGameData().board.getCellContent(newMove)
                == CellTypes::Empty)
                break;
        }

        std::cout << "Wrong Move, try again\n";
    }

    return newMove;
}

std::string GuiConsole::getUserRequiredCell(int playerIndexToUse) const
{
    std::string nextMove_str;

    std::cout << gameData.getGameData().players[playerIndexToUse]->getData().name
              << " Enter your next move (1-9)" << std::endl;
    std::cin >> nextMove_str;

    return nextMove_str;
}

Gui::ActionEnum GuiConsole::wantToPlayAgain() const
{
    std::string answer;

    std::cout << "Do you want to play again? (y\\n)\n";

    while (true)
    {
        std::cin >> answer;

        if (compareStrings(answer, "n"))
        {
            return ActionEnum::No;
        }

        if (compareStrings(answer, "y"))
        {
            return ActionEnum::Yes;
        }

        if (compareStrings(answer, "s"))
        {
            return ActionEnum::Switch;
        }

        if (compareStrings(answer, "Easy"))
        {
            return ActionEnum::Easy;
        }

        if (compareStrings(answer, "HARD"))
        {
            return ActionEnum::Hard;
        }
    }
}

void GuiConsole::startPlay()
{
    gameData.resetGame();

    displayOnScreen();

    while (gameData.keepPlaying())
        playNextTurn();

    checkEndGameStatus();
    askUserToRestart();
}

void GuiConsole::askUserToRestart()
{
    auto userAnswer = wantToPlayAgain();

    if (gameData.wantToPlayAgain(userAnswer))
        startPlay();
}

void GuiConsole::checkEndGameStatus()
{
    if (gameData.isWeHaveAWinner())
    {
        weHaveAWinner();
        gameData.updateScore();
    }
    else
        tie();
}
void GuiConsole::playNextTurn() const
{
    auto nextMove = gameData.askForNextMove();

    if (nextMove.waitingForHuman)
        nextMove.position = askPlayerForMove();
    else
        mySleep(nextMove.timeToWaitUntilDisplay);

    gameData.makeMove(nextMove);
    displayOnScreen();
}

void GuiConsole::displayOnScreen() const
{
    ClearScreen();
    if (gameData.getGameData().conf.getNumRealPlayers() == 2)
        printHeaderWithoutDiff();

    else
        printHeader();

    printBoard();
}

} // namespace Liron486