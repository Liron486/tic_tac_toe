#pragma once

namespace Liron486
{
enum class CellTypes
{
    Ex,
    Circle,
    Empty
};

class Cell
{
public:
    Cell(int rowLocationToUse, int colLocationToUse);
    CellTypes getCellContent() const;
    void setCellContent(CellTypes newContentToUse);
    int getRelativeLocation() const;
    static char cellTypeToChar(CellTypes cellTypeToUse);
    static CellTypes charToCellType(char charToUse);


private:
    CellTypes content = CellTypes::Empty;
    int relativeLoc;
};

} // namespace Liron486
