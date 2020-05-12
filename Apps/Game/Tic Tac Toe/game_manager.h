#pragma once

#include "tic_tac_toe.h"
#include "cell.h"
#include "computer.h"
#include "gui.h"
#include "judge.h"
#include "real_player.h"

namespace Liron486
{
class GameManager
{
public:
    void play();
    bool wantToPlayAgain();
    GameData& getGameData();
    void setGui(Gui* guiToUse) { gui = guiToUse; }

private:
    void createNewPlayersPtrs();
    void switchSides();
    void displayOnScreen() const;
    void changeDifficulty(Configuration::Difficulty difficultyToUse);
    void resetGame();
    Computer* createComputer(int index, CellTypes type) const;
    RealPlayer* createRealPlayer(int index, CellTypes type) const;
    Point fillLastSquare() const;

    int moveNumber = 0;
    GameData gameData;
    Judge judge {gameData.board};
    int switchSidesCounter = 0;
    Gui* gui = nullptr;
    bool weHaveAWinner = false;
};

} // namespace Liron486
