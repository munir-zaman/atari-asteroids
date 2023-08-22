#include "iostream"
#include "raylib/raylib-cpp.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "app"

#define BG_COLOR BLACK

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BG_COLOR);
        EndDrawing();
    }

    CloseWindow();
}