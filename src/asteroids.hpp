
#include "raylib/raylib.hpp"
#include "vector"

#include "constants.hpp"
#include "coordinates.hpp"

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
        pos = add_vec(pos, mul_vec(GetFrameTime(), velocity));
        Vector2 pixel_pos = world_to_pixel_coord(pos);
        DrawCircleLines(pixel_pos.x, pixel_pos.y, size, color);
    }
} Asteroid;


std::vector<Asteroid> random_asteroids(int number) {

    int asteroid_sizes[] = {ASTEROID_LARGE, ASTEROID_SMALL};
    std::vector<Asteroid> asteroids;
    for (int i = 0; i < number; i++) {
        Asteroid random_asteroid = {
            .size = asteroid_sizes[rand() % 2],
            .pos = {
                (float)(rand() % WINDOW_WIDTH - (WINDOW_WIDTH / 2)),
                (float)(rand() % WINDOW_HEIGHT - (WINDOW_HEIGHT / 2))
            },
            .velocity = {
                (float)(rand() % (ASTEROID_MAX_VELOCITY - ASTEROID_MIN_VELOCITY) + ASTEROID_MIN_VELOCITY), 
                (float)(rand() % (ASTEROID_MAX_VELOCITY - ASTEROID_MIN_VELOCITY) + ASTEROID_MIN_VELOCITY)
            }
        };

        asteroids.push_back(random_asteroid);
    }

    return asteroids;
}