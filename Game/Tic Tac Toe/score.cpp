#include <iostream>

#include "score.h"

namespace Liron486
{

    Score::Score(const std::string& namePlayer1_, const std::string& namePlayer2_)
    {
        m_playersNames[0] = namePlayer1_;
        m_playersNames[1] = namePlayer2_;
        m_winsCounter[0] = 0;
        m_winsCounter[1] = 0;
    }

    void Score::UpdateScore(int theWinner_)
    {
        if ((0 == theWinner_) || (1 == theWinner_))
        {
            ++m_winsCounter[theWinner_];
        }
    }

    const std::string* Score::GetPlayersNames() const
    {
        return (m_playersNames);
    }

    void Score::SetPlayerName(const std::string& namePlayer_, int index_)
    {
        m_playersNames[index_] = namePlayer_;
    }

    const int* Score::GetWinsCounter() const
    {
        return (m_winsCounter);
    }

    void Score::SetWinsCounter(int numOfWins_, int index_)
    {
        m_winsCounter[index_] = numOfWins_;
    }

} // namespace Liron486