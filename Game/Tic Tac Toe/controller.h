#ifndef _Liron486_CONTROLLER_HPP_
#define _Liron486_CONTROLLER_HPP_

#include <string>

#include "point.h"

namespace Liron486
{

    class Controller
    {
    public:
        explicit Controller(const std::string& playerName_);
        const std::string GetNextMove() const;

    private:
        const std::string m_playerName;
    };

} // namespace Liron486

#endif // _Liron486_CONTROLLER_HPP_#pragma once
