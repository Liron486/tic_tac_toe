#pragma once

#include "gui.h"
#include "game_manager.h"
#include "configurtion_gui_console.h"

namespace Liron486
{
class GuiConsole : public Gui
{
public:
    explicit GuiConsole(GameManager& gameDataToUse);
    void printBoard() const;
    void printHeader() const;
    void printHeaderWithoutDiff() const;
    void weHaveAWinner();
    void tie();
    void tutorial();
    Point makeMove() const;
    ActionEnum wantToPlayAgain() const;
    void startPlay();
    void displayOnScreen() const;

private:
    int getCurrentPlayer() const { return gameData.getGameData().currentPlayer; }
    std::string getUserRequiredCell(int playerIndexToUse) const;
    void playNextTurn() const;
    void checkEndGameStatus();
    void askUserToRestart();

    ConfigurationGuiConsole confGuiConsole {gameData.getGameData().conf};

};

} // namespace Liron486
