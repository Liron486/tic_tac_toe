#pragma once

#include <array>
#include <string>

namespace Liron486
{
class Score
{
public:
    explicit Score(const std::string& namePlayer1ToUse, const std::string& namePlayer2ToUse);
    void UpdateScore(int theWinnerToUse);
    const std::array<std::string, 2>& GetPlayersNames() const;
    void SetPlayerName(const std::string& namePlayerToUse, int indexToUse);
    const std::array<int, 2>& GetWinsCounter() const;
    void SetWinsCounter(int numOfWinsToUse, int indexToUse);

private:
    std::array<std::string, 2> playersNames;
    std::array<int, 2> winsCounter = {0, 0};
};

} // namespace Liron486

