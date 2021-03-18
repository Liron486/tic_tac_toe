#include <cstdlib> /* srand, rand */
#include <ctime> /* time */
#include <memory>

#include "computer.h"
#include "brain_easy.h"
#include "brain_hard.h"
#include "cell.h"

namespace Liron486
{
static std::unique_ptr<Brain> CreateBrain(const Board& boardToUse,
                                          CellTypes typeToUse,
                                          Configuration::Difficulty difficultyToUse)
{
    std::unique_ptr<Brain> brain;

    if (Configuration::Difficulty::Easy == difficultyToUse)
    {
        brain = std::make_unique<BrainEasy>(boardToUse, typeToUse);
    }
    else
    {
        brain = std::make_unique<BrainHard>(boardToUse, typeToUse);
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

Move Computer::makeMove() const
{
    if (data.type != brain->getType())
        brain->setType(data.type);

    return brain->getNextMove();
}


} // namespace Liron486