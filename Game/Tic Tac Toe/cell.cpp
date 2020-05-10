#include <string>

#include "cell.h"

namespace Liron486
{
Cell::Cell(int rowLocationToUse, int colLocationToUse)
    : relativeLoc((rowLocationToUse + 1) * (colLocationToUse + 1))
{
}

CellTypes Cell::getCellContent() const
{
    return content;
}

void Cell::setCellContent(CellTypes newContentToUse)
{
    content = newContentToUse;
}

int Cell::getRelativeLocation() const
{
    return relativeLoc;
}

char Cell::cellTypeToChar(CellTypes cellTypeToUse)
{
    switch (cellTypeToUse)
    {
        case CellTypes::Ex:
            return 'X';
        case CellTypes::Circle:
            return 'O';
        default:
            return ' ';
    }
}
	
CellTypes Cell::charToCellType(char charToUse)
{
    charToUse = std::toupper(charToUse);
	
	if (charToUse == 'X')
        return CellTypes::Ex;

    return CellTypes::Circle;
}

} // namespace Liron486