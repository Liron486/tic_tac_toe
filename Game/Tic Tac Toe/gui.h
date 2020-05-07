#ifndef _Liron486_BOARD_DRAWER_HPP_
#define _Liron486_BOARD_DRAWER_HPP_

#include <memory>
#include <vector>
#include <string>

#include "score.h"
#include "player.h"
#include "configuration.h"


namespace Liron486
{
class Gui
{
public:
    void PrintBoard(const std::vector<std::vector<char>>& boardToUse) const;
    void PrintHeader(const Score& scoreToUse,
                     int gameNumberToUse,
                     Configuration::Difficulty difficultyToUse) const;
    void PrintHeaderWithoutDiff(const Score& scoreToUse, int gameNumberToUse) const;
    void WeHaveAWinner(std::unique_ptr<Player>& playerToUse) const;
    void Tie() const;
    void Tutorial(const std::vector<std::vector<char>>& boardToUse,
                  const Score& scoreToUse,
                  Configuration::Difficulty difficultyToUse,
                  const std::string& name1ToUse,
                  const std::string& name2ToUse) const;
};

} // namespace Liron486

#endif // _Liron486_BOARD_DRAWER_HPP_#pragma once
