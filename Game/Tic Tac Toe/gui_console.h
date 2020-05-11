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
    void printBoard() override;
    void printHeader() override;
    void printHeaderWithoutDiff() override;
    void weHaveAWinner(int winerIndex) override;
    void tie() override;
    void tutorial() override;
private:
	
    ConfigurationGuiConsole confGuiConsole {gameData.getGameData().conf};
};

} // namespace Liron486
