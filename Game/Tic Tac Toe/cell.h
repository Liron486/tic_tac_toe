#ifndef _Liron486_CELL_HPP_
#define _Liron486_CELL_HPP_

namespace Liron486
{
class Cell
{
public:
    Cell(int rowLocationToUse, int colLocationToUse);
    char getCellContent() const;
    void setCellContent(char newContentToUse);
    int getRelativeLocation() const;

private:
    char content = ' ';
    int relativeLoc;
};

} // namespace Liron486

#endif // _Liron486_CELL_HPP_#pragma once
#pragma once
