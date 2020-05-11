#include <cstdlib> /* srand, rand */
#include <ctime> /* time */
#include <vector>
#include <algorithm>

#include "brain_hard.h"
#include "judge.h"
#include "gui_console.h"
#include "utils.h"

namespace Liron486
{
const int num_of_cells = 9;

BrainHard::BrainHard(const Board& boardToUse, CellTypes typeToUse)
    : board(boardToUse)
    , myType(typeToUse)
{
}

CellTypes GetCurrentType(CellTypes myTypeToUse, int depthToUse)
{
    auto current_type = CellTypes::Empty;

    if (depthToUse % 2 == 1)
    {
        current_type = myTypeToUse;
    }
    else
    {
        if (myTypeToUse == CellTypes::Ex)
        {
            current_type = CellTypes::Circle;
        }
        else
        {
            current_type = CellTypes::Ex;
        }
    }

    return current_type;
}

static int RecCheckBestMove(Board& boardCopyToUse,
                            CellTypes typeToUse,
                            const Judge& judgeToUse,
                            const Point& lastMLastMoveToUse,
                            int depthToUse)
{
    auto current_type = GetCurrentType(typeToUse, depthToUse);

    boardCopyToUse.setCell(current_type, lastMLastMoveToUse);

    if (judgeToUse.checkForWinner(lastMLastMoveToUse))
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

    for (auto i = 1; i <= num_of_cells; ++i)
    {
        nextMove = Point::convertNumToPoint(i);

        if (boardCopyToUse.isSquareEmpty(nextMove))
        {
            current_value = RecCheckBestMove(
                boardCopyToUse, typeToUse, judgeToUse, nextMove, depthToUse + 1);
            boardCopyToUse.setCell(CellTypes::Empty, nextMove);

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
                value = (std::max)(value, vector_of_values[i]);
            }
        }
        else
        {
            value = 10;
            for (auto i = 0; i < vector_size; ++i)
            {
                value = (std::min)(value, vector_of_values[i]);
            }
        }
    }

    return value;
}

static bool AmIBegin(const Board& boardToUse)
{
    for (auto i = 1; i <= num_of_cells; ++i)
    {
        if (!boardToUse.isSquareEmpty(Point::convertNumToPoint(i)))
        {
            return false;
        }
    }

    return true;
}

static bool CheckIfWinNextMove(Board& boardToUse,
                               std::vector<Point>& bestMovesToUse,
                               Judge& judgeToUse,
                               CellTypes typeToUse,
                               int rangeToUse,
                               int& indexResultToUse)
{
    for (auto i = 0; i < rangeToUse; ++i)
    {
        boardToUse.setCell(typeToUse, bestMovesToUse[i]);

        if (judgeToUse.checkForWinner(bestMovesToUse[i]))
        {
            indexResultToUse = i;
            boardToUse.setCell(CellTypes::Empty, bestMovesToUse[i]);
            return true;
        }

        boardToUse.setCell(CellTypes::Empty, bestMovesToUse[i]);
    }

    return false;
}

Point BrainHard::getNextMove() const
{
    auto max = -10;
    auto current_res = -10;
    auto currentDepth = 1;
    auto boardCopy(board);
    Point nextMove;
    Point checkMove;
    Judge judge(boardCopy);
    std::vector<Point> best_moves;
    auto counter_best_moves = 0;

    srand(static_cast<unsigned int>(time(nullptr)));

    if (AmIBegin(boardCopy))
    {
        nextMove = Point::convertNumToPoint((rand() % num_of_cells) + 1);
    }
    else
    {
        for (auto i = 1; i <= num_of_cells; ++i)
        {
            checkMove = Point::convertNumToPoint(i);

            if (boardCopy.isSquareEmpty(checkMove))
            {
                current_res = RecCheckBestMove(
                    boardCopy, myType, judge, checkMove, currentDepth);
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

void BrainHard::setType(CellTypes typeToUse)
{
    myType = typeToUse;
}

CellTypes BrainHard::getType() const
{
    return myType;
}

} // namespace Liron486