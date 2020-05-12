#pragma once

#include <array>
#include <string>

namespace Liron486
{
class Score
{
public:
    void updateScore(int theWinnerToUse);
    const std::array<std::string, 2>& getPlayersNames() const;
    void setPlayerName(const std::string& namePlayerToUse, int indexToUse);
    const std::array<int, 2>& getWinsCounter() const;
    void setWinsCounter(int numOfWinsToUse, int indexToUse);

private:
    std::array<std::string, 2> playersNames;
    std::array<int, 2> winsCounter = {0, 0};
};

} // namespace Liron486

