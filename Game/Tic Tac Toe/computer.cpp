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

Computer::Computer(const std::string& nameToUse,
                   char typeToUse,
                   const Board& boardToUse,
                   Configuration::Difficulty difficultyToUse)
    : name(nameToUse)
    , type(typeToUse)
    , board(boardToUse)
    , difficulty(difficultyToUse)
    , brain(CreateBrain(board, type, difficulty))
{
}

Point Computer::makeMove() const
{
    if (type != brain->getType())
    {
        brain->setType(type);
    }

    return brain->getNextMove();
}

std::string Computer::getName() const
{
    return name;
}

char Computer::getPlayerType() const
{
    return type;
}

void Computer::setPlayerType(char newTypeToUse)
{
    type = newTypeToUse;
}

} // namespace Liron486