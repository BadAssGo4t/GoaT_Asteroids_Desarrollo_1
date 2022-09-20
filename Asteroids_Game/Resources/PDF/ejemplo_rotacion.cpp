#include "raylib.h"

#include <iostream>

int main()
{
    const float screenWidth = 800;
    const float screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Nueva Ventana");

    Rectangle rec;
    rec.x = screenWidth / 2;
    rec.y = screenHeight / 2;
    rec.width = 50;
    rec.height = 300;

    Vector2 pivot;
    pivot.x = rec.width / 2;
    pivot.y = rec.height / 2;

    float rotation = 0.0f;

    while (!WindowShouldClose())
    {
        rotation += 0.01f;

        std::cout << rotation << std::endl;

        BeginDrawing();
        ClearBackground(WHITE);

        DrawRectanglePro(rec, pivot, rotation, RED);
        
        EndDrawing();
    }

    CloseWindow();
}