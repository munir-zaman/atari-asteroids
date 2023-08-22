#include "iostream"
#include "bits/stdc++.h"
#include "raylib/raylib-cpp.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "app"
#define WINDOW_CENTER {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}
#define BG_COLOR BLACK


Vector2 polar_degree(int r, int theta) {
    // convert to radians
    theta = theta * (PI / 180);
    return (Vector2){ r * cos(theta), r * sin(theta) };
}

template <typename T>
void print_vec(std::vector<T> vec) {
    for (const auto& x : vec) { std::cout << x << " "; }
    std::cout << "\n";
}

void print_vec(std::vector<Vector2> vec) {
    for (const auto& x : vec) { std::cout << "( " << x.x << ", "  << x.y << ") "; }
    std::cout << "\n";
}

typedef struct {
    int size;
    int corners;
    std::vector<Vector2> points;
    Color color;
    Vector2 pos;
    Vector2 velocity;

    void generate_points(void) {
        std::vector<int> thetas(corners, 0);
        for (int i = 1; i < corners; i++) {
            thetas[i] = rand() % 360;
        }

        std::sort(thetas.begin(), thetas.end());
        print_vec(thetas);

        for (int i = 0; i < corners; i++) {
            points.push_back( (Vector2){pos.x + polar_degree(size, thetas[i]).x , 
                                        pos.y + polar_degree(size, thetas[i]).y } );
        }

        print_vec(points);
    } 

    void draw(void) {
        int thick = 1;
        for (int j = 0; j < corners; j++) {
            DrawLineEx(points[j], points[(j+1)%corners], thick, color);
        }

        DrawCircleLines(pos.x, pos.y, size, color);
    }
} Asteroid;

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    Asteroid Asteroid_test = {.size = 100, .corners = 4, .color = WHITE, .pos = WINDOW_CENTER};
    Asteroid_test.generate_points();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BG_COLOR);

        Asteroid_test.draw();

        EndDrawing();
    }

    CloseWindow();
}