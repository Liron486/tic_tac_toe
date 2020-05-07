#include <cstdlib> /* srand, rand */
#include <ctime> /* time */
#include <vector>

#include "brain_hard.h"
#include "gui.h"
#include "cross_platform_funcs.h"

#define MAX2(X, Y) (X) > (Y) ? (X) : (Y)
#define MIN2(X, Y) (X) < (Y) ? (X) : (Y)

namespace Liron486
{

const int num_of_cells = 9;

BrainHard::BrainHard(const Board& board_, char type_)
    : m_board(board_)
    , m_myType(type_)
{
}

inline char GetCurrentType(char my_type, int depth)
{
    char current_type = ' ';

    if (1 == depth % 2)
    {
        current_type = my_type;
    }
    else
    {
        if ('X' == my_type)
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

static int RecCheckBestMove(Board& board_copy,
                            char type,
                            const Judge& judge,
                            const Point& last_move,
                            int depth)
{
    char current_type = GetCurrentType(type, depth);

    board_copy.SetSquare(current_type, last_move);

    if (judge.CheckForWinner(last_move))
    {
        if (type != board_copy.GetSquareContent(last_move))
        {
            return (-1);
        }

        return 1;
    }

    Point nextMove;
    int current_value = 0;
    std::vector<int> vector_of_values;
    bool isfull = true;

    for (int i = 0; i < num_of_cells; ++i)
    {
        nextMove = Point::ConvertNumToPoint(i);

        if (board_copy.IsSquareEmpty(nextMove))
        {
            current_value =
                RecCheckBestMove(board_copy, type, judge, nextMove, depth + 1);
            board_copy.SetSquare(' ', nextMove);

            vector_of_values.push_back(current_value);
            isfull = false;
        }
    }

    int value = 0;

    if (!isfull)
    {
        int vector_size = static_cast<int>(vector_of_values.size());

        if (0 == depth % 2)
        {
            value = -10;
            for (int i = 0; i < vector_size; ++i)
            {
                value = MAX2(value, vector_of_values[i]);
            }
        }
        else
        {
            value = 10;
            for (int i = 0; i < vector_size; ++i)
            {
                value = MIN2(value, vector_of_values[i]);
            }
        }
    }

    return value;
}

static bool AmIBegin(const Board& board)
{
    for (int i = 0; i < num_of_cells; ++i)
    {
        if (!board.IsSquareEmpty(Point::ConvertNumToPoint(i)))
        {
            return (false);
        }
    }

    return true;
}

static bool CheckIfWinNextMove(Board& board,
                               std::vector<Point>& best_moves,
                               Judge& judge,
                               char type,
                               int range,
                               int& index_result)
{
    for (int i = 0; i < range; ++i)
    {
        board.SetSquare(type, best_moves[i]);

        if (judge.CheckForWinner(best_moves[i]))
        {
            index_result = i;
            board.SetSquare(' ', best_moves[i]);
            return true;
        }

        board.SetSquare(' ', best_moves[i]);
    }

    return false;
}

Point BrainHard::GetNextMove() const
{
    int max = -10;
    int current_res = -10;
    Board board_copy(m_board);
    Point nextMove;
    Point checkMove;
    Judge judge(board_copy);
    std::vector<Point> best_moves;
    int counter_best_moves = 0;

    srand(static_cast<unsigned int>(time(NULL)));

    if (AmIBegin(board_copy))
    {
        nextMove = Point::ConvertNumToPoint(rand() % num_of_cells);
    }
    else
    {
        for (int i = 0; i < num_of_cells; ++i)
        {
            checkMove = Point::ConvertNumToPoint(i);

            if (board_copy.IsSquareEmpty(checkMove))
            {
                current_res =
                    RecCheckBestMove(board_copy, m_myType, judge, checkMove, 1);
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

                board_copy = m_board;
            }
        }

        int index_of_winning_move = 0;
        if (CheckIfWinNextMove(board_copy,
                               best_moves,
                               judge,
                               m_myType,
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

void BrainHard::SetType(char type_)
{
    m_myType = type_;
}

char BrainHard::GetType() const
{
    return m_myType;
}

} // namespace Liron486