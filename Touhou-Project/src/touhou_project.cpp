#include "header/touhou_project.h"

touhou_project::touhou_project() {
    /* Initialization */
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "Touhou Project by n0miya");

    main_menu* MainMenu = new main_menu();
    delete MainMenu;
}