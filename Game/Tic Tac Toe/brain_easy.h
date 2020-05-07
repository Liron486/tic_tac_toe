#ifndef _Liron486_BRAIN_EASY_HPP_
#define _Liron486_BRAIN_EASY_HPP_

#include "brain.h"
#include "board.h"

namespace Liron486
{
class BrainEasy : public Brain
{
public:
    explicit BrainEasy(const Board& board_, char type_);
    virtual Point GetNextMove() const;
    virtual char GetType() const;
    virtual void SetType(char type_);

private:
    const Board& m_board;
    char m_myType;
};

} // namespace Liron486

#endif // _Liron486_BRAIN_EASY_HPP_