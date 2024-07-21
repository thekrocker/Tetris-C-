#include <raylib.h>
#include "grid.h"

int main()
{
    Color darkBlue = Color{44, 44, 127, 255};

    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tetris C++");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.grid[0][0] = 1;
    grid.Print();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}