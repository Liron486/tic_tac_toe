#pragma once

#include <memory>

#include "configuration.h"
#include "player.h"
#include "real_player.h"
#include "board.h"
#include "score.h"
#include "judge.h"
#include "computer.h"
#include "cell.h"

namespace Liron486
{
class GameManager
{

public:
    explicit GameManager();
    void Play();
    bool WantToPlayAgain();

private:
    void CreateNewPlayersPtrs();
    void SwitchSides();
    void DisplayOnScreen() const;
    void ChangeDifficulty(Configuration::Difficulty difficultyToUse);
    void ResetGame();
    Computer* createComputer(int index, CellTypes type) const;
    RealPlayer* createRealPlayer(int index, CellTypes type) const;

	
    Point FillLastSquare() const;

    int moveNumber = 0;
    Configuration conf;
    Configuration::Difficulty difficulty;
    Board board;
    Score score;
    std::unique_ptr<Player> players[2];
    Judge judge;
    int gameNumber = 1;
    int switchSidesCounter = 0;
};

} // namespace Liron486
