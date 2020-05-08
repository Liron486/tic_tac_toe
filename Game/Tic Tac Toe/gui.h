#pragma once

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
	static void PrintBoard(const std::vector<std::vector<char>>& boardToUse);
	static void PrintHeader(const Score& scoreToUse,
	                        int gameNumberToUse,
	                        Configuration::Difficulty difficultyToUse);
	static void PrintHeaderWithoutDiff(const Score& scoreToUse, int gameNumberToUse);
	static void WeHaveAWinner(std::unique_ptr<Player>& playerToUse);
	static void Tie();
	static void Tutorial(const std::vector<std::vector<char>>& boardToUse,
	                     const Score& scoreToUse,
	                     Configuration::Difficulty difficultyToUse,
	                     const std::string& name1ToUse,
	                     const std::string& name2ToUse);
};

} // namespace Liron486

