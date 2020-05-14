
#include "real_player.h"

namespace Liron486
{
RealPlayer::RealPlayer(const PlayerData& dataToUse)
    : Player(dataToUse)
{
}


Move RealPlayer::makeMove() const
{
    return {Point(), true, 0};
}


} // namespace Liron486