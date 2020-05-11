
#include "score.h"

namespace Liron486
{

void Score::updateScore(int theWinnerToUse)
{
    if ((theWinnerToUse == 0) || (theWinnerToUse == 1))
        ++winsCounter[theWinnerToUse];
}

const std::array<std::string, 2>& Score::getPlayersNames() const
{
    return playersNames;
}

void Score::setPlayerName(const std::string& namePlayerToUse, int indexToUse)
{
    playersNames[indexToUse] = namePlayerToUse;
}

const std::array<int, 2>& Score::getWinsCounter() const
{
    return winsCounter;
}

void Score::setWinsCounter(int numOfWinsToUse, int indexToUse)
{
    winsCounter[indexToUse] = numOfWinsToUse;
}

} // namespace Liron486