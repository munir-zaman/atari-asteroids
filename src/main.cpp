#include "iostream"
#include "bits/stdc++.h"
#include "raylib/raylib-cpp.hpp"

#include "asteroids.hpp"
#include "constants.hpp"


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
    InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WINDOW_TITLE);
    
    std::vector<Asteroid> asteroids = random_asteroids(10);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WINDOW_BG_COLOR);

        for (auto &a : asteroids) {
            a.draw();
        }

        EndDrawing();
    }

    CloseWindow();
}