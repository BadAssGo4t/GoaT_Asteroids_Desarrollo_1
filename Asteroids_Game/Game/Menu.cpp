#include "Menu.h"

#define NUM_FRAMES  3 

typedef struct   Button
{
    Texture2D button;
    float frameHeight;
    Rectangle sourceRec;
    Rectangle btnBounds;
    int btnState;
    bool btnAction;
} Play, Controls, Credits;

int Menu(void)
{
    // Init
    const int screenWidth = 800;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "Menu");

    static Play play;
    static Controls controls;
    static Credits credits;

    play.button = LoadTexture("../Resources/Button/Play-Bttn.png");
    play.frameHeight = (float)play.button.height / NUM_FRAMES;
    play.sourceRec = { 0, 0, (float)play.button.width, play.frameHeight };
    // Define button bounds on screen
    play.btnBounds = { screenWidth / 2.0f - play.button.width / 2.0f, screenHeight / 2.0f - play.button.height*3 / NUM_FRAMES / 2.0f, (float)play.button.width, play.frameHeight };
    play.btnState = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    play.btnAction = false; 






    Vector2 mousePoint = { 0.0f, 0.0f };
    SetTargetFPS(60);

    // Menu loop
    while (!WindowShouldClose())
    {
        // Update
        mousePoint = GetMousePosition();
        play.btnAction = false;

        // Check button state
        if (CheckCollisionPointRec(mousePoint, play.btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) play.btnState = 2;
            else play.btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) play.btnAction = true;
        }
        else play.btnState = 0;

        if (play.btnAction)
        {
            std::cout << "boton precionado" << "\n";
        
        }

        // Calculate button frame rectangle to draw depending on button state
        play.sourceRec.y = play.btnState * play.frameHeight;

        // TODO: Update your variables here

        // Draw

        BeginDrawing();

        ClearBackground(LIGHTGRAY);
        DrawText("Asteroids", screenWidth / 2 - MeasureText("Asteroids", 15), 60, 30, BLACK);

        DrawTextureRec(play.button, play.sourceRec, Vector2{ play.btnBounds.x, play.btnBounds.y }, WHITE); 
           
        EndDrawing();
    }

    UnloadTexture(play.button);
    CloseWindow();

    return 0;
}	