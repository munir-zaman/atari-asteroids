#include "iostream"
#include "bits/stdc++.h"
#include "raylib/raylib-cpp.hpp"

#include "asteroids.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "app"
#define WINDOW_CENTER {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}
#define BG_COLOR BLACK


template <typename T>
void print_vec(std::vector<T> vec) {
    for (const auto& x : vec) { std::cout << x << " "; }
    std::cout << "\n";
}

void print_vec(std::vector<Vector2> vec) {
    for (const auto& x : vec) { std::cout << "( " << x.x << ", "  << x.y << ") "; }
    std::cout << "\n";
}

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    
    std::vector<Asteroid> asteroids = randomAsteroids(30);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BG_COLOR);

        for (auto &a : asteroids) {
            a.draw();
        }

        EndDrawing();
    }

    CloseWindow();
}