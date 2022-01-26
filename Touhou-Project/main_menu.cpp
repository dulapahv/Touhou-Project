#include "main_menu.h"

main_menu::main_menu() {
    /* Screen Resolution */
    const int screenWidth = 1024;
    const int screenHeight = 768;

    /* Music */
    InitAudioDevice();
    Music music = LoadMusicStream("resources/music/TITLE.wav");
    PlayMusicStream(music);

    /* BG */
    Texture2D titleBG = LoadTexture("resources/gfx/bg/title.png");
    int frameWidth = titleBG.width;
    int frameHeight = titleBG.height;
    Rectangle sourceRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };
    Rectangle destRec = { screenWidth / 0.65f, screenHeight / 0.65f, frameWidth * 0.67f , frameHeight * 0.67f };
    Vector2 origin = { (float)frameWidth, (float)frameHeight };

    SetTargetFPS(360);

    /* Main game loop */
    while (!WindowShouldClose()) {
        /* Update music buffer with new stream data */
        UpdateMusicStream(music);

        /* Draw */
        BeginDrawing();

        DrawTexturePro(titleBG, sourceRec, destRec, origin, 0, WHITE);
        DrawText("Touhou Project by n0miya", 30, 350, 40, GRAY);
        DrawText("Start", 30, 500, 40, WHITE);
        DrawText("Option", 30, 550, 40, WHITE);
        DrawText("Help", 30, 600, 40, WHITE);
        DrawText("About", 30, 650, 40, WHITE);
        DrawText("Exit", 30, 700, 40, WHITE);

        EndDrawing();
    }

    /* De-Initialization */
    UnloadMusicStream(music);
    UnloadTexture(titleBG);
    CloseAudioDevice();
    CloseWindow();
}
