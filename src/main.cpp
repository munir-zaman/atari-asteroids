#include "iostream"
#include "bits/stdc++.h"
#include "raylib/raylib-cpp.hpp"

#include "utils.hpp"

#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720
#define WINDOW_TITLE "Atari asteroids"



typedef struct
{
    Vector2 pos = {100, 100};
    float dir = - 45;

    float velocity = 10;
    float acceleration = 10;

    float radius = 50;

    
    void update() {

        if (IsKeyPressedRepeat(KEY_D)) dir += 5;

        pos = pos + polar(1, dir * PI / 180) * velocity * GetFrameTime();
    }

    void draw() {

        update();
        
        DrawCircleLines(pos.x, pos.y, radius, BLUE);
    }
} Player;


int main() {
    InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WINDOW_TITLE);


    Player p;

    while (!WindowShouldClose()) {
    
        BeginDrawing();
        ClearBackground(BLACK);

        p.draw();

        EndDrawing();
    }

    CloseWindow();
}