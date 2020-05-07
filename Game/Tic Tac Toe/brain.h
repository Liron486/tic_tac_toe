#pragma once
#ifndef _Liron486_BRAIN_HPP_
#define _Liron486_BRAIN_HPP_

#include "point.h"

namespace Liron486
{
class Brain
{
public:
    virtual Point getNextMove() const = 0;
    virtual char getType() const = 0;
    virtual void setType(char type_) = 0;
};

} // namespace Liron486

#endif // _Liron486_BRAIN_HPP_