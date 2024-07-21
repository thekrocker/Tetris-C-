#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
    Block();
    int id;
    std::map<int, std::vector<Position>> cells;
    void Draw();
    void Move(int row, int column);

private:
    int cellSize;
    int rotationState;
    int rowOffset;
    int columnOffset;
    std::vector<Color> colors;
    std::vector<Position> GetCellPositions();
};