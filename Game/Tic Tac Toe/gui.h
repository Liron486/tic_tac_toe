#ifndef _Liron486_BOARD_DRAWER_HPP_
#define _Liron486_BOARD_DRAWER_HPP_

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
        void PrintBoard(const std::vector<std::vector<char> >& board_) const;
        void PrintHeader(const Score& score_, int gameNUmber_, Configuration::Difficulty difficulty_) const;
        void PrintHeaderWithoutDiff(const Score& score_, int gameNUmber_) const;
        void WeHaveAWinner(Player** players_, int playerNum_) const;
        void Tie() const;
        void Tutorial(const std::vector<std::vector<char> >& board_, const Score& score_, Configuration::Difficulty difficulty_, const std::string& name1, const std::string& name2) const;
    };

} // namespace Liron486

#endif // _Liron486_BOARD_DRAWER_HPP_#pragma once
