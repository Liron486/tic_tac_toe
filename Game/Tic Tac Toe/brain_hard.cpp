#include <cstdlib> /* srand, rand */
#include <ctime> /* time */
#include <vector>

#include "brain_hard.h"
#include "judge.h"
#include "gui.h"
#include "utils.h"

#define MAX2(X, Y) (X) > (Y) ? (X) : (Y)
#define MIN2(X, Y) (X) < (Y) ? (X) : (Y)

namespace Liron486
{

const int num_of_cells = 9;

BrainHard::BrainHard(const Board& boardToUse, char typeToUse)
    : board(boardToUse)
    , myType(typeToUse)
{
}

inline char GetCurrentType(char myTypeToUse, int depthToUse)
{
    auto current_type = ' ';

    if (1 == depthToUse % 2)
    {
        current_type = myTypeToUse;
    }
    else
    {
        if ('X' == myTypeToUse)
        {
            current_type = 'O';
        }
        else
        {
            current_type = 'X';
        }
    }

    return current_type;
}

static int RecCheckBestMove(Board& boardCopyToUse,
                            char typeToUse,
                            const Judge& judgeToUse,
                            const Point& lastMLastMoveToUse,
                            int depthToUse)
{
    auto current_type = GetCurrentType(typeToUse, depthToUse);

    boardCopyToUse.setCell(current_type, lastMLastMoveToUse);

    if (judgeToUse.CheckForWinner(lastMLastMoveToUse))
    {
        if (typeToUse != boardCopyToUse.getCellContent(lastMLastMoveToUse))
        {
            return (-1);
        }

        return 1;
    }

    Point nextMove;
    auto current_value = 0;
    std::vector<int> vector_of_values;
    auto isfull = true;

    for (auto i = 0; i < num_of_cells; ++i)
    {
        nextMove = Point::ConvertNumToPoint(i);

        if (boardCopyToUse.isSquareEmpty(nextMove))
        {
            current_value =
                RecCheckBestMove(boardCopyToUse, typeToUse, judgeToUse, nextMove, depthToUse + 1);
            boardCopyToUse.setCell(' ', nextMove);

            vector_of_values.push_back(current_value);
            isfull = false;
        }
    }

    auto value = 0;

    if (!isfull)
    {
        auto vector_size = static_cast<int>(vector_of_values.size());

        if (depthToUse % 2 == 0)
        {
            value = -10;
            for (auto i = 0; i < vector_size; ++i)
            {
                value = MAX2(value, vector_of_values[i]);
            }
        }
        else
        {
            value = 10;
            for (auto i = 0; i < vector_size; ++i)
            {
                value = MIN2(value, vector_of_values[i]);
            }
        }
    }

    return value;
}

static bool AmIBegin(const Board& boardToUse)
{
    for (auto i = 0; i < num_of_cells; ++i)
    {
        if (!boardToUse.isSquareEmpty(Point::ConvertNumToPoint(i)))
        {
            return false;
        }
    }

    return true;
}

static bool CheckIfWinNextMove(Board& boardToUse,
                               std::vector<Point>& bestMovesToUse,
                               Judge& judgeToUse,
                               char typeToUse,
                               int rangeToUse,
                               int& indexResultToUse)
{
    for (auto i = 0; i < rangeToUse; ++i)
    {
        boardToUse.setCell(typeToUse, bestMovesToUse[i]);

        if (judgeToUse.CheckForWinner(bestMovesToUse[i]))
        {
            indexResultToUse = i;
            boardToUse.setCell(' ', bestMovesToUse[i]);
            return true;
        }

        boardToUse.setCell(' ', bestMovesToUse[i]);
    }

    return false;
}

Point BrainHard::getNextMove() const
{
    auto max = -10;
    auto current_res = -10;
    auto boardCopy(board);
    Point nextMove;
    Point checkMove;
    Judge judge(boardCopy);
    std::vector<Point> best_moves;
    auto counter_best_moves = 0;

    srand(static_cast<unsigned int>(time(nullptr)));

    if (AmIBegin(boardCopy))
    {
        nextMove = Point::ConvertNumToPoint(rand() % num_of_cells);
    }
    else
    {
        for (auto i = 0; i < num_of_cells; ++i)
        {
            checkMove = Point::ConvertNumToPoint(i);

            if (boardCopy.isSquareEmpty(checkMove))
            {
                current_res =
                    RecCheckBestMove(boardCopy, myType, judge, checkMove, 1);
                if (current_res > max)
                {
                    best_moves.clear();
                    max = current_res;
                    best_moves.push_back(checkMove);
                    counter_best_moves = 1;
                }
                else if (current_res == max)
                {
                    best_moves.push_back(checkMove);
                    ++counter_best_moves;
                }

                boardCopy = board;
            }
        }

        auto index_of_winning_move = 0;
        if (CheckIfWinNextMove(boardCopy,
                               best_moves,
                               judge,
                               myType,
                               counter_best_moves,
                               index_of_winning_move))
        {
            nextMove = best_moves[index_of_winning_move];
        }
        else
        {
            nextMove = best_moves[rand() % counter_best_moves];
        }
    }

    MySleep(1000);
    return nextMove;
}

void BrainHard::setType(char typeToUse)
{
    myType = typeToUse;
}

char BrainHard::getType() const
{
    return myType;
}

} // namespace Liron486