#include "game.h"
#include <random>
#include <raylib.h>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();

    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveLeft();
        break;

    case KEY_RIGHT:
        MoveRight();
        break;

    case KEY_DOWN:
        MoveDown();
        break;

    case KEY_UP:
        Rotate();
    }
}

void Game::MoveLeft()
{
    currentBlock.Move(0, -1);

    if (IsBlockOutOfGrid())
    {
        currentBlock.Move(0, 1);
    }
}

void Game::MoveRight()
{
    currentBlock.Move(0, 1);
    if (IsBlockOutOfGrid())
    {
        currentBlock.Move(0, -1);
    }
}

void Game::MoveDown()
{
    currentBlock.Move(1, 0);
    if (IsBlockOutOfGrid())
    {
        currentBlock.Move(-1, 0);
    }
}

void Game::Rotate()
{
    currentBlock.Rotate();
    if (IsBlockOutOfGrid())
    {
        currentBlock.UndoRotate();
    }
}

bool Game::IsBlockOutOfGrid()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    for (Position item : tiles)
    {
        if (grid.IsBlockOutOfGrid(item.row, item.column))
        {
            return true;
        }
    }

    return false;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}