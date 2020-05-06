#pragma once
#ifndef _Liron486_BRAIN_HPP_
#define _Liron486_BRAIN_HPP_

#include "point.h"

namespace Liron486
{

class Brain
{
public:
    virtual ~Brain() {}
    virtual Point GetNextMove() const = 0;
    virtual char GetType() const = 0;
    virtual void SetType(char type_) = 0;
};

} // namespace Liron486

#endif // _Liron486_BRAIN_HPP_