#include "raylib.h"
#include "raygui.h"
#include <iostream>

#define MENU_CHOICE 5

typedef enum {
    START = 0,
    OPTION,
    HELP,
    ABOUT,
    EXIT
};

int main(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "Touhou Project by n0miya");

    // Music
    InitAudioDevice();
    Music music = LoadMusicStream("resources/music/TITLE.wav");
    PlayMusicStream(music);

    // BG
    Texture2D titleBG = LoadTexture("resources/gfx/bg/title.png");
    int frameWidth = titleBG.width;
    int frameHeight = titleBG.height;
    Rectangle sourceRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };
    Rectangle destRec = { screenWidth / 0.65f, screenHeight / 0.65f, frameWidth * 0.67f , frameHeight * 0.67f };
    Vector2 origin = { (float)frameWidth, (float)frameHeight };

    Rectangle toggleRecs[MENU_CHOICE] = { 0 };
    int currentProcess = -1;
    bool textureReload = false;

    SetTargetFPS(360);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {
        // Update music buffer with new stream data
        UpdateMusicStream(music);

        for (int i = 0; i < MENU_CHOICE; i++) {
            if (CheckCollisionPointRec(GetMousePosition(), toggleRecs[i])) {
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                    currentProcess = i;
                    textureReload = true;
                }
                break;
            }
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexturePro(titleBG, sourceRec, destRec, origin, 0, WHITE);

        DrawText("Touhou Project by n0miya", 30, 350, 40, GRAY);
        DrawText("Start", 30, 500, 40, WHITE);
        DrawText("Option", 30, 550, 40, WHITE);
        DrawText("Help", 30, 600, 40, WHITE);
        DrawText("About", 30, 650, 40, WHITE);
        DrawText("Exit", 30, 700, 40, WHITE);

        for (int i = 0; i < MENU_CHOICE; i++) {
            DrawRectangleRec(toggleRecs[i], ((i == currentProcess)) ? SKYBLUE : LIGHTGRAY);
            DrawRectangleLines((int)toggleRecs[i].x, (int)toggleRecs[i].y, (int)toggleRecs[i].width, (int)toggleRecs[i].height, ((i == currentProcess)) ? BLUE : GRAY);
        }


        EndDrawing();

        
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadMusicStream(music);
    UnloadTexture(titleBG);
    CloseAudioDevice();
    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}