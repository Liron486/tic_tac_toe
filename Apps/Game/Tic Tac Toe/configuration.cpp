
#include <string>


#include "configuration.h"

namespace Liron486
{


int Configuration::getNumRealPlayers() const
{
    return nRealPlayers;
}

Configuration::Difficulty Configuration::getDifficulty() const
{
    return difficulty;
}

std::string Configuration::getPlayerName(int nPlayerToUse) const
{
    return namesOfPlayers[nPlayerToUse];
}

CellTypes Configuration::getPlayerChoice() const
{
    return playerChoice;
}

void Configuration::setNumRealPlayers(int nRealPlayersToUse)
{
    nRealPlayers = nRealPlayersToUse;
}

void Configuration::setDifficulty(Difficulty difficultyToUse)
{
    difficulty = difficultyToUse;
}

void Configuration::setPlayerName(const std::string& playerNameToUse, int playerIndexToUse)
{
    namesOfPlayers[playerIndexToUse] = playerNameToUse;
}

void Configuration::setPlayerChoice(CellTypes playerChosenTypeToUse)
{
    playerChoice = playerChosenTypeToUse;
}

} // namespace Liron486