#include <cstdlib> /* srand, rand */
#include <ctime> /* time */

#include "computer.h"
#include "brain_easy.h"
#include "brain_hard.h"

namespace Liron486
{
static std::unique_ptr<Brain> CreateBrain(const Board& boardToUse,
                                          char typeToUse,
                                          Configuration::Difficulty difficultyToUse)
{
    std::unique_ptr<Brain> brain;

    if (Configuration::Difficulty::EASY == difficultyToUse)
    {
        brain.reset(new BrainEasy(boardToUse, typeToUse));
    }
    else
    {
        brain.reset(new BrainHard(boardToUse, typeToUse));
    }

    return brain;
}

Computer::Computer(const PlayerData& dataToUse,
                   Configuration::Difficulty difficultyToUse)
    : Player(dataToUse)
    , difficulty(difficultyToUse)
    , brain(CreateBrain(data.board, data.type, difficulty))
{
}

Point Computer::makeMove() const
{
    if (data.type != brain->getType())
    {
        brain->setType(data.type);
    }

    return brain->getNextMove();
}


} // namespace Liron486