#include "block.h"

Block::Block()
{
    rotationState = 0;
    cellSize = 30;
    rowOffset = 0;
    columnOffset = 0;
    colors = GetCellColors();
}

void Block::Draw()
{
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles)
    {
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int row, int column)
{
    rowOffset += row;
    columnOffset += column;
}

void Block::Rotate()
{
    rotationState = (rotationState + 1) % cells.size();
}

void Block::UndoRotate()
{
    rotationState = (rotationState - 1 + cells.size()) % cells.size();
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;

    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }

    return movedTiles;
}