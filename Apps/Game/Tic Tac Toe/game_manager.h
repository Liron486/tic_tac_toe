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
    bool keepPlaying() {return moveNumber < gameData.board.getNumOfCells();}
    int getMoveNumber() const;
    Move askForNextMove();
    bool checkForWinner(Point lastMove);
    void resetGame();
    bool isWeHaveAWinner() const;

private:
    void switchSides();
    void changeDifficulty(Configuration::Difficulty difficultyToUse);
    Computer* createComputer(int index, CellTypes type) const;
    RealPlayer* createRealPlayer(int index, CellTypes type) const;
    Point fillLastSquare() const;

    int moveNumber = 0;
    GameData gameData;
    Judge judge {gameData.board};
    int switchSidesCounter = 0;
    bool weHaveAWinner = false;

};

} // namespace Liron486
