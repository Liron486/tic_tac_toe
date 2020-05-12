

#include "real_player.h"

namespace Liron486
{
RealPlayer::RealPlayer(const PlayerData& dataToUse, const Gui* guiToUse)
    : Player(dataToUse)
    , gui(guiToUse)
{
}



Point RealPlayer::makeMove() const
{
    auto myIndex = 0;
    if (data.type == CellTypes::Circle)
        myIndex = 1;
	
    return gui->makeMove(myIndex);
}


} // namespace Liron486