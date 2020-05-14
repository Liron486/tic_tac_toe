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
    void printBoard() const override;
    void printHeader() const override;
    void printHeaderWithoutDiff() const override;
    void weHaveAWinner(int winerIndex) override;
    void tie() override;
    void tutorial() override;
    Point makeMove(int playerIndexToUse) const override;
    ActionEnum wantToPlayAgain() const override;
    void startPlay() override;
    void displayOnScreen() const override;

private:
    std::string getUserRequiredCell(int playerIndexToUse) const;

    ConfigurationGuiConsole confGuiConsole {gameData.getGameData().conf};
};

} // namespace Liron486
