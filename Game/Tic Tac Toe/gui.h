#pragma once

#include <string>

#include "score.h"
#include "board.h"
#include "player.h"
#include "configuration.h"


namespace Liron486
{
class Gui
{
public:
	static void PrintBoard(const Board& boardToUse);
	static void PrintHeader(const Score& scoreToUse,
	                        int gameNumberToUse,
	                        Configuration::Difficulty difficultyToUse);
	static void PrintHeaderWithoutDiff(const Score& scoreToUse, int gameNumberToUse);
    static void WeHaveAWinner(const PlayerData& playerDataToUse);
	static void Tie();
    static void Tutorial(const Board& boardToUse,
	                     const Score& scoreToUse,
	                     Configuration::Difficulty difficultyToUse,
	                     const std::string& name1ToUse,
	                     const std::string& name2ToUse);
};

} // namespace Liron486

