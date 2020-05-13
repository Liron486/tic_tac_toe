
#include "Board.h"
#include "Cell.h"

const auto numOfRows = 3;
const auto numOfCols = 3;

Board::Board()
{
    for (auto i = 0; i < numOfRows * numOfCols; ++i)
    {
        cells.emplace_back(new Cell);
        addAndMakeVisible(*cells.back());
    }

    setSize(750, 750);
}

void Board::resized()
{
    auto x = 0.f;
    auto y = 0.f;
    auto width = 1.f / (float) numOfCols;
    auto hight = 1.f / (float) numOfRows;
    auto cellIdx = 0;

    for (auto i = 1; i <= numOfCols; ++i)
    {
        for (auto j = 1; j <= numOfRows; ++j)
        {
            cells[cellIdx]->setBoundsRelative(x, y, width, hight);
            x += width;
            ++cellIdx;
        }

        x = 0.f;
        y += hight;
    }
}

void Board::paintOverChildren(Graphics& g)
{
    g.setColour(Colours::black);
    auto width = getLocalBounds().getWidth();
    auto hight = getLocalBounds().getHeight();

    g.drawLine(0, hight / 3, width, hight / 3, 8);
    g.drawLine(0, (hight * 2) / 3, width, (hight * 2) / 3, 8);
    g.drawLine(width / 3, 0, width / 3, hight, 8);
    g.drawLine((width * 2) / 3, 0, (width * 2) / 3, hight, 8);
}