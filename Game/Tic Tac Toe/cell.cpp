
#include "cell.h"

namespace Liron486
{
Cell::Cell(int relativeLocToUse)
    : relativeLoc(relativeLocToUse)
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