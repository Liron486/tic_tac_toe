#include <cstdlib> /* srand, rand */
#include <ctime> /* time */

#include "brain_easy.h"
#include "utils.h"

namespace Liron486
{
BrainEasy::BrainEasy(const Board& boardToUse, char typeToUse)
    : board(boardToUse)
    , myType(typeToUse)
{
}

Point BrainEasy::getNextMove() const
{   
    constexpr auto num_of_cells = 9;

    Point checkMove;
    Point availableMoves[9];
    auto countAvailableMoves = 0;

    for (auto i = 0; i < num_of_cells; ++i)
    {
        checkMove = Point::ConvertNumToPoint(i);

        if (board.IsSquareEmpty(checkMove))
        {
            availableMoves[countAvailableMoves] = checkMove;
            ++countAvailableMoves;
        }
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    auto nextMove = availableMoves[rand() % countAvailableMoves];

    MySleep(1000);
    return nextMove;
}

void BrainEasy::setType(char typeToUse)
{
    myType = typeToUse;
}

char BrainEasy::getType() const
{
    return myType;
}

} // namespace Liron486