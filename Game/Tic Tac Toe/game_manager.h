#ifndef _Liron486_GAME_MANAGER_HPP_
#define _Liron486_GAME_MANAGER_HPP_

#include <memory>

#include "configuration.h"
#include "player.h"
#include "board.h"
#include "score.h"
#include "judge.h"
#include "gui.h"

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
    void ChangeDifficulty(Configuration::Difficulty difficulty_);
    void ResetGame();
    void FillLastSquare();

    int m_moveNumber;
    const Configuration m_conf;
    Configuration::Difficulty m_difficulty;
    Board m_board;
    Score m_score;
    std::unique_ptr<Player> m_players[2];
    Judge m_judge;
    const Gui m_gui;
    int m_gameNumber;
    int m_switchSidesCounter;
};

} // namespace Liron486

#endif // _Liron486_GAME_MANAGER_HPP_#pragma once
