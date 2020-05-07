
#include "score.h"

namespace Liron486
{
Score::Score(const std::string& namePlayer1ToUse, const std::string& namePlayer2ToUse)
{
    playersNames[0] = namePlayer1ToUse;
    playersNames[1] = namePlayer2ToUse;
}

void Score::UpdateScore(int theWinnerToUse)
{
    if ((theWinnerToUse == 0) || (theWinnerToUse == 1))
        ++winsCounter[theWinnerToUse];
}

const std::array<std::string, 2>& Score::GetPlayersNames() const
{
    return playersNames;
}

void Score::SetPlayerName(const std::string& namePlayerToUse, int indexToUse)
{
    playersNames[indexToUse] = namePlayerToUse;
}

const std::array<int, 2>& Score::GetWinsCounter() const
{
    return winsCounter;
}

void Score::SetWinsCounter(int numOfWinsToUse, int indexToUse)
{
    winsCounter[indexToUse] = numOfWinsToUse;
}

} // namespace Liron486