#pragma once
#include "grid.h"
#include <vector>
#include "blocks.cpp"

class Game
{
    public:
    Game();
    Block GetRandomBlock();
    void Draw();
    Grid grid;

private:
    std::vector<Block> GetAllBlocks();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};