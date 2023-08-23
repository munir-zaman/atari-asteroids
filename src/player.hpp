#include "raylib/raylib.hpp"
#include "coordinates.hpp"

#include "iostream"

typedef struct
{
    Vector2 pos = {10, 10};
    Vector2 velocity = {0, 0};
    Color color = PLAYER_COLOR;
    int size = 10;
    Vector2 dir = {0, 1};
    int delta_v = 50;

    void draw(void) {

        if (IsKeyPressed(KEY_W)) {
            std::cout << "W was pressed" << "\n";
            velocity = add_vec(velocity, mul_vec(delta_v, dir));
        }

        pos = add_vec(pos, mul_vec(GetFrameTime(), velocity));
        Vector2 pixel_pos = world_to_pixel_coord(pos);

        Vector2 vert1 = mul_vec(size, {cos(90 * PI / 180), sin(90 * PI / 180)});
        Vector2 vert2 = mul_vec(size, {cos((180 + 45) * PI / 180), sin((180 + 45) * PI / 180)});
        Vector2 vert3 = mul_vec(size, {cos((270 + 45) * PI / 180), sin((270 + 45) * PI / 180)});

        vert1 = add_vec(pixel_pos, vert1);
        vert2 = add_vec(pixel_pos, vert2);
        vert3 = add_vec(pixel_pos, vert3);

        DrawLineV(vert1, vert2, color);
        DrawLineV(vert2, vert3, color);
        DrawLineV(vert3, vert1, color);
    }
} Player;
