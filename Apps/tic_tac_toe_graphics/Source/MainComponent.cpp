#include "MainComponent.h"

const auto numOfRows = 3;
const auto numOfCols = 3;

void Cell::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    if (mouseDownCounter % 3 == 1)
    {
        auto offsetDiag = Point<int>(60, 60);
        auto offsetAntiDiag = Point<int>(-60, 60);

        Line<int> diag(getLocalBounds().getTopLeft() + offsetDiag,
                       getLocalBounds().getBottomRight() - offsetDiag);
        Line<int> antiDiag(getLocalBounds().getTopRight() + offsetAntiDiag,
                           getLocalBounds().getBottomLeft() - offsetAntiDiag);

        g.drawLine(diag.toFloat(), 8);
        g.drawLine(antiDiag.toFloat(), 8);
    }

    else if (mouseDownCounter % 3 == 2)
    {
        auto rect = getLocalBounds().toFloat();
        auto offset = 80;
        auto smallerRect = rect.withSizeKeepingCentre(rect.getWidth() - offset,
                                                      rect.getHeight() - offset);
        g.drawEllipse(smallerRect, 10);
    }
}



void Cell::mouseDown(const MouseEvent& event)
{
    ++mouseDownCounter;
    repaint();
}

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
