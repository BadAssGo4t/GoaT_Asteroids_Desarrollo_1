#include "Menu.h"

int Menu(void)
{
    // Init
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Menu");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update

        // TODO: Update your variables here

        // Draw

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}	