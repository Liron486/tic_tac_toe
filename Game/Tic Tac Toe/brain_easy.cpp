#include <cstdlib> /* srand, rand */
#include <ctime> /* time */

#include "brain_easy.h"
#include "cross_platform_funcs.h"

namespace Liron486
{
BrainEasy::BrainEasy(const Board& board_, const char type_)
    : m_board(board_)
    , m_myType(type_)
{
}

BrainEasy::~BrainEasy()
{
}

Point BrainEasy::GetNextMove() const
{
    Point checkMove;
    Point availableMoves[9];
    int countAvailableMoves = 0;

    for (int i = 0; i < 9; ++i)
    {
        checkMove = Point::ConvertNumToPoint(i);

        if (m_board.IsSquareEmpty(checkMove))
        {
            availableMoves[countAvailableMoves] = checkMove;
            ++countAvailableMoves;
        }
    }

    srand(static_cast<unsigned int>(time(NULL)));

    Point nextMove = availableMoves[rand() % countAvailableMoves];

    liron486::MySleep(1000);
    return (nextMove);
}

void BrainEasy::SetType(char type_)
{
    m_myType = type_;
}

char BrainEasy::GetType() const
{
    return (m_myType);
}

} // namespace Liron486