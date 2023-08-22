
#include "raylib/raylib.hpp"
#include "vector"

enum ASTEROID_SIZE {
    ASTEROID_LARGE = 50,
    ASTEROID_SMALL = 25
};

#define ASTEROID_COLOR RED

typedef struct
{
    int size;
    Vector2 pos;
    Vector2 velocity;
    Color color = ASTEROID_COLOR;

    void draw() {
        pos = {pos.x + velocity.x * GetFrameTime(), pos.y + velocity.y * GetFrameTime()};
        DrawCircleLines(pos.x, pos.y, size, color);
    }
} Asteroid;


std::vector<Asteroid> randomAsteroids(int number) {

    int asteroid_sizes[] = {ASTEROID_LARGE, ASTEROID_SMALL};
    
    std::vector<Asteroid> asteroids;
    for (int i = 0; i < number; i++) {
        Asteroid random_asteroid = {
            .size = asteroid_sizes[rand() % 2],
            .pos = {
                rand() % 1280,
                rand() % 720
            },
            .velocity = {
                rand() % 100 - 50, 
                rand() % 100 - 50
            }
        };

        asteroids.push_back(random_asteroid);
    }

    return asteroids;
}