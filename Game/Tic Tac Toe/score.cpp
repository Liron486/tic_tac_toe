#include <iostream>

#include "score.h"

namespace Liron486
{
Score::Score(const std::string& namePlayer1_, const std::string& namePlayer2_)
{
    m_playersNames[0] = namePlayer1_;
    m_playersNames[1] = namePlayer2_;
}

void Score::UpdateScore(int theWinner_)
{
    if ((theWinner_ == 0) || (theWinner_ == 1))
        ++m_winsCounter[theWinner_];
}

const std::string* Score::GetPlayersNames() const
{
    return m_playersNames;
}

void Score::SetPlayerName(const std::string& namePlayer_, int index_)
{
    m_playersNames[index_] = namePlayer_;
}

const std::array<int, 2>& Score::GetWinsCounter() const
{
    return m_winsCounter;
}

void Score::SetWinsCounter(int numOfWins_, int index_)
{
    m_winsCounter[index_] = numOfWins_;
}

} // namespace Liron486