#pragma once

#include "configuration.h"

namespace Liron486
{
class ConfigurationGuiConsole
{
public:
    explicit ConfigurationGuiConsole(Configuration& confToUse);
    void setDifficulty() const;
    void setDifficulty(Configuration::Difficulty difficultyToUse) const;
    void setNumRealPlayers() const;
    void setPlayerChoice() const;
    CellTypes getPlayerChoice() const { return conf.getPlayerChoice(); }
    Configuration::Difficulty getDifficulty() const { return conf.getDifficulty(); }
    int getNumRealPlayers() const { return conf.getNumRealPlayers(); }
    void setPlayerName(const std::string& playerNameToUse,
                       int playerIndexToUse) const
    {
        conf.setPlayerName(playerNameToUse, playerIndexToUse);
    }

    void setNamesOfPlayers(int playerNumberToUse) const;
    std::string getPlayerName(int nPlayerToUse) const
    {
        return conf.getPlayerName(nPlayerToUse);
    }

private:
    Configuration& conf;
};

} // namespace Liron486
