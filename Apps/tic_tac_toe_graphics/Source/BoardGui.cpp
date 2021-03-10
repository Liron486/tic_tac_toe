
#include "BoardGui.h"

const auto numOfRows = 3;
const auto numOfCols = 3;

BoardGui::BoardGui(Liron486::GameManager& managerToUse)
    : gameData(managerToUse)
{
    startTimerHz(700);

    for (auto i = 0; i < numOfRows * numOfCols; ++i)
    {
        cells.emplace_back(new CellGui(gameData, i + 1, alpha));
        addAndMakeVisible(*cells.back());
    }
}

void BoardGui::resized()
{
    resizedCells(cells);
}

void BoardGui::paintOverChildren(Graphics& g)
{
    auto bounds = getLocalBounds().toFloat();

    drawGrid(g, bounds.getWidth(), bounds.getHeight(), alpha);
}

void BoardGui::updateCells()
{
    for (auto i = 0; i < gameData.getGameData().board.getNumOfCells(); ++i)
    {
        auto point = Liron486::Point::convertNumToPoint(i + 1);
        auto cellContent = gameData.getGameData().board.getCellContent(point);
        cells[i]->updateCellContent(cellContent);
    }
}
