#ifndef _Liron486_BRAIN_EASY_HPP_
#define _Liron486_BRAIN_EASY_HPP_

#include "brain.h"
#include "Board.h"

namespace Liron486
{
class BrainEasy : public Brain
{
public:
    explicit BrainEasy(const Board& boardToUse, char typeToUse);
    Point getNextMove() const override;
    char getType() const override;
    void setType(char typeToUse) override;

private:
    const Board& board;
    char myType;
};

} // namespace Liron486

#endif // _Liron486_BRAIN_EASY_HPP_