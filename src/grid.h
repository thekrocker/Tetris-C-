#pragma once
#include <vector>
#include <raylib.h>

class Grid {

public:
Grid();
int grid[20][10];
void Print();
void Draw();

private:
int numRows, numColumns, cellSize;
void Initialize();
std::vector<Color> colors;
};