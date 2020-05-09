
#include "cell.h"

namespace Liron486
{
Cell::Cell(int rowLocationToUse, int colLocationToUse)
    : relativeLoc((rowLocationToUse + 1) * (colLocationToUse + 1))
{
}

char Cell::getCellContent() const
{
    return content;
}

void Cell::setCellContent(char newContentToUse)
{
    content = newContentToUse;
}

int Cell::getRelativeLocation() const
{
    return relativeLoc;
}

} // namespace Liron486