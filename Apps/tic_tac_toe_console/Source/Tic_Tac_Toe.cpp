#include "game_manager.h"
#include "gui_console.h"

using namespace Liron486;

int main()
{
    GameManager gameManager;
	
    GuiConsole gui(gameManager);

    gui.startPlay();

    return 0;
}