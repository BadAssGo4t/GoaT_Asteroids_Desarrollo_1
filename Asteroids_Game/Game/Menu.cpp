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
    const int screenWidth = 600;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Menu");

    static Play play;
    static Controls controls;
    static Credits credits;

    //parallax
    Texture2D background = LoadTexture ("../Resources/Dynamic Space Background/Nebula Blue.png");
    Texture2D stars = LoadTexture("../Resources/Dynamic Space Background/Stars-Big_1_1_PC.png");

    float scrollingBack   = 0.0f;
    float scrollingStars  = 0.0f;

    // PLay Button
    play.button = LoadTexture("../Resources/Button/Play-Bttn.png");
    play.frameHeight = (float)play.button.height / NUM_FRAMES;
    play.sourceRec = { 0, 0, (float)play.button.width, play.frameHeight };
    // Define button bounds on screen
    play.btnBounds = { screenWidth / 2.0f - play.button.width / 2.0f, screenHeight / 2.0f - play.button.height*3 / NUM_FRAMES / 2.0f, (float)play.button.width, play.frameHeight };
    play.btnState = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    play.btnAction = false; 

    // Controls Button
    controls.button = LoadTexture("../Resources/Button/Controls-Bttn.png");
    controls.frameHeight = (float)controls.button.height / NUM_FRAMES;
    controls.sourceRec = { 0, 0, (float)controls.button.width, controls.frameHeight };

    controls.btnBounds = { screenWidth / 2.0f - controls.button.width / 2.0f, screenHeight / 2.0f - controls.button.height/2 / NUM_FRAMES / 2.0f, (float)controls.button.width, controls.frameHeight };
    controls.btnState = 0; 
    controls.btnAction = false;

    // Credits Button
    credits.button = LoadTexture("../Resources/Button/Credits-Bttn.png");
    credits.frameHeight = (float)play.button.height / NUM_FRAMES;
    credits.sourceRec = { 0, 0, (float)credits.button.width, credits.frameHeight };

    credits.btnBounds = { screenWidth / 2.0f - credits.button.width / 2.0f, screenHeight / 2.0f + credits.button.height * 2 / NUM_FRAMES / 2.0f, (float)credits.button.width, credits.frameHeight };
    credits.btnState = 0;  
    credits.btnAction = false;


    Vector2 mousePoint = { 0.0f, 0.0f };
    SetTargetFPS(60);

    // Menu loop
    while (!WindowShouldClose())
    {
        // Update
        mousePoint = GetMousePosition();
        play.btnAction = false;
        controls.btnAction = false;
        credits.btnAction = false;

        scrollingBack  -= 0.5f;
        scrollingStars -= 0.9f;

        if (scrollingBack <= -background.width * 2) scrollingBack = 0; 
        if (scrollingStars <= -stars.width * 2) scrollingStars = 0;

        // Check button state
        if (CheckCollisionPointRec(mousePoint, play.btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) play.btnState = 2;
            else play.btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) play.btnAction = true;
        }
        else play.btnState = 0;

        if (CheckCollisionPointRec(mousePoint, controls.btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) controls.btnState = 2;
            else controls.btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) controls.btnAction = true;
        }
        else controls.btnState = 0;

        if (CheckCollisionPointRec(mousePoint, credits.btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) credits.btnState = 2;
            else credits.btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) credits.btnAction = true;
        }
        else credits.btnState = 0;


        if (play.btnAction)
        {
            std::cout << "boton Play precionado" << "\n";
       
        }
        if (controls.btnAction)
        {
            std::cout << "boton Controls precionado" << "\n";
        }
        if (credits.btnAction)
        {
            std::cout << "boton Credits precionado" << "\n";
        }

        // Calculate button frame rectangle to draw depending on button state
        play.sourceRec.y = play.btnState * play.frameHeight;
        controls.sourceRec.y = controls.btnState * controls.frameHeight; 
        credits.sourceRec.y = credits.btnState * credits.frameHeight; 

        // TODO: Update your variables here

        // Draw

        BeginDrawing();

        ClearBackground(GetColor(0x052c46ff));



        DrawTextureEx(background, Vector2{ scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
        DrawTextureEx(background, Vector2{ background.width*2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

        DrawTextureEx(stars, Vector2 { scrollingStars, 20 }, 0.0f, 2.0f, WHITE);
        DrawTextureEx(stars, Vector2 { stars.width * 2 + scrollingStars, 20 }, 0.0f, 2.0f, WHITE);

        DrawText("Asteroids", screenWidth / 2 - MeasureText("Asteroids", 40), 40, 80, LIGHTGRAY);

        DrawTextureRec(play.button, play.sourceRec, Vector2{ play.btnBounds.x, play.btnBounds.y }, WHITE); 
        DrawTextureRec(controls.button, controls.sourceRec, Vector2{ controls.btnBounds.x, controls.btnBounds.y }, WHITE);
        DrawTextureRec(credits.button, credits.sourceRec, Vector2{ credits.btnBounds.x, credits.btnBounds.y }, WHITE);
           
        EndDrawing();
    }

    UnloadTexture(play.button);
    UnloadTexture(controls.button);
    UnloadTexture(credits.button);
    UnloadTexture(background);
    UnloadTexture(stars);
    CloseWindow();

    return 0;
}	