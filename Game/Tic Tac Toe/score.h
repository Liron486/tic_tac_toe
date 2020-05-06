#ifndef _Liron486_SCORE_HPP_
#define _Liron486_SCORE_HPP_

#include <string>

namespace Liron486
{
class Score
{
public:
    explicit Score(const std::string& namePlayer1_, const std::string& namePlayer2_);
    void UpdateScore(int theWinner_);
    const std::string* GetPlayersNames() const;
    void SetPlayerName(const std::string& namePlayer_, int index_);
    const int* GetWinsCounter() const;
    void SetWinsCounter(int numOfWins_, int index_);

private:
    std::string m_playersNames[2];
    int m_winsCounter[2];
};

} // namespace Liron486

#endif // _Liron486_SCORE_HPP_#pragma once
