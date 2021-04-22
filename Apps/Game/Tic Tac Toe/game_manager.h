#pragma once

#include "tic_tac_toe.h"
#include "cell.h"
#include "computer.h"
#include "gui.h"
#include "judge.h"
#include "player.h"
#include "real_player.h"

namespace Liron486
{
class GameManager
{
public:
    bool wantToPlayAgain(Gui::ActionEnum userAnswer);
    GameData& getGameData();
    void createNewPlayersPtrs();
    void initScoreNames();
    bool keepPlaying() const { return gameIsInProgress; }
    Move askForNextMove();
    void checkForWinner(Point lastMove);
    void resetGame();
    bool isWeHaveAWinner() const;

    void updateScore() { gameData.score.updateScore(gameData.currentPlayer); }
    void makeMove(Move move);
    void switchSides();
    void changeDifficulty(Configuration::Difficulty difficultyToUse);

private:
    Computer* createComputer(int index, CellTypes type) const;
    RealPlayer* createRealPlayer(int index, CellTypes type) const;
    Point fillLastSquare() const;

    int moveNumber = 0;
    GameData gameData;
    Judge judge {gameData.board};
    int switchSidesCounter = 0;
    bool gameIsInProgress = true;
    bool weHaveAWinner = false;
};

} // namespace Liron486
