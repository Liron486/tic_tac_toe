#include <cstdlib> /* srand, rand */
#include <ctime> /* time */

#include "computer.h"
#include "brain_easy.h"
#include "brain_hard.h"

namespace Liron486
{
static std::unique_ptr<Brain> CreateBrain(const Board& board_,
                          char type_,
                          Configuration::Difficulty difficulty_)
{
    std::unique_ptr<Brain> brain;

    if (Configuration::Difficulty::EASY == difficulty_)
    {
        brain.reset(new BrainEasy(board_, type_));
    }
    else
    {
        brain.reset(new BrainHard(board_, type_));
    }

    return (brain);
}

Computer::Computer(const std::string& name_,
                   char type_,
                   const Board& board_,
                   Configuration::Difficulty difficulty_)
    : m_name(name_)
    , m_type(type_)
    , m_board(board_)
    , m_difficulty(difficulty_)
    , m_brain(CreateBrain(m_board, m_type, m_difficulty))
{
}

Computer::~Computer()
{
}

Point Computer::MakeMove() const
{
    if (m_type != m_brain->GetType())
    {
        m_brain->SetType(m_type);
    }

    return (m_brain->GetNextMove());
}

const std::string Computer::GetName() const
{
    return (m_name);
}

char Computer::GetPlayerType() const
{
    return (m_type);
}

void Computer::SetPlayerType(char newType_)
{
    m_type = newType_;
}

} // namespace Liron486