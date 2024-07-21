#include "grid.h"
#include "iostream"

Grid::Grid()
{
    numRows = 20;
    numColumns = 10;
    cellSize = 30;
    colors = GetCellColors();
    Initialize();
}

void Grid::Initialize()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::Print()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// We are drawing above background, to center, we are adding offset, and to show rectangles like as a grid, we normally had 30 cell size, but this completely has no margin and they show as a whole.
// So we simply decrease cell size by given offset and we have created grid view.
// Screen width is 300, cell size is 30, so 300/30, there is 10 square per row.
void Grid::Draw()
{
    int offset = 1;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            int cellValue = grid[i][j];
            DrawRectangle(j * cellSize + offset, i * cellSize + offset, cellSize - offset, cellSize - offset, colors[cellValue]);
        }
    }
}

std::vector<Color> Grid::GetCellColors()
{
    Color darkGrey = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}
